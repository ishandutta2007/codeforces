#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , k , p , c;

int main ()
{
	long long i;
	cin >> n >> k;
	if (k > 200000 || (k+1)*k/2 > n)
	{
		cout << "-1\n";
	}
	else
	{
		p = n/((k+1)*k/2);
		if (p <= sqrt(n))
		{
			while (n%p != 0)
			{
				p--;
			}
		}
		else
		{
			c = 0;
			for (i = n/p ; i <= sqrt(n) ; i++)
			{
				if (n%i == 0)
				{
					c = 1;
					p = n/i;
					break;
				}
			}
			if (c == 0)
			{
				p = sqrt(n);
				while (n%p != 0)
				{
					p--;
				}
			}
		}
		for (i = 1 ; i < k ; i++)
		{
			printf("%I64d ",p*i);
		}
		printf("%I64d\n",n-(p*(k-1)*k/2));
	}
	//system("PAUSE");
	return 0;
}