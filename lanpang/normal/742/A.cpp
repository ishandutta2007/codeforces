#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , i;

int quick1(int f)
{ 
    int t , h;
	if (f%2==1)
	    h = 8;
	else
	    h = 1;    
	if (f/2==1)
	    t = 8;    
	else  
	{ 
	    if (f/2==0)
		    t = 1;
		else	 
	        t = quick1(f/2);   
	}
	h = h*t*t;
	return (h%10);
}

int main ()
{
	scanf("%d",&n);
    printf("%d\n",quick1(n));
    //system("PAUSE");
	return 0;
}