#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , f , i , p;
long long k , m; 

int main ()
{
	scanf("%d%I64d",&n,&k);
	if (k%2==1)
	    f = 1;
	else
	{
		k/=2;
		if (k%2==1)
		    f = 2;
		else
		{
			k /= 2;
			m = 1;
			p = n;
			for (i = 1 ; i <= n-2 ; i++)
			    m *= 2;
			m--;    
			while (k != (m+1)/2)
			{
				p--;
				if (k > (m+1)/2)
				    k -= (m+1)/2;
				m = (m-1)/2;
			}
			f = p;
		}    
	}
	printf("%d\n",f);
    //system("PAUSE");
	return 0;
}