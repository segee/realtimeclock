#include <cstdint>
#include <cstddef>
#include <time.h>
#include <iostream>
//the real meat is in "my_ticks" 
//it grabs the system time in nanoseconds
//The main routine will help you figure out the actual resolution on your platform
//to compile g++ realtime.cpp
//to run ./a.out.

int64_t my_ticks(void)
{   
#include <time.h>
#include <stdint.h>
	    struct timespec bruce;

	        clock_gettime(CLOCK_REALTIME, &bruce);
		    return (int64_t) bruce.tv_sec*1000000000L+bruce.tv_nsec;
}

int main()
{
	int64_t my_array[100];

	int x;

	for(x=0;x<100;x++)
	{
		my_array[x]=my_ticks();
	}
	for(x=1;x<100;x++) std::cout << "The difference is "<<my_array[x] - my_array[x-1] << " nanoseconds \n";
}
