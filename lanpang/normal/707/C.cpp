#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long x , y , z , c = 0;

int main ()
{
	long long i;
	cin >> x;
	x*=x;
	if (x%2==1)
	{
		if (x > 1)
		{
			c = 1;
			y = (x-1)/2;
			z = y+1;
		}
	}
	else
	{
		i = 0;
		while (i <= sqrt(x))
		{
			i += 2;
			y = x-i*i;
			y /= 2;
			if (y == 0) 
			    break;
			if (y%i==0)
			{
				y/=i;
				z = y+i;
				c = 1;
				break;
			}
		}
	}
	if (c == 0)
	    cout << "-1\n";
	else
	    cout << y << " " << z << "\n";    
	//system("PAUSE");
	return 0;
}