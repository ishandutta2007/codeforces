#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long t , l , r , ans , f[5000001] , o[5000001] , a7 = 1e9+7 , tt; 

int main ()
{
	long long i , j;
	cin >> t >> l >> r;
	for (i = 2 ; i <= r ; i++)
	{
		if (o[i] == 0)
		{
			for (j = i*2 ; j <= r ; j += i)
			{
				if (o[j] == 0)
				{
					o[j] = i;
				}
			}
		}
	} 
	for (i = 2 ; i <= r ; i++)
	{
		if (o[i] == 0)
		{
			f[i] = i*(i-1)/2;
			f[i] %= a7;
		}
		else
		{
			f[i] = (i/o[i]*f[o[i]])+f[i/o[i]];
			f[i] %= a7;
		}
	}
	tt = 1;
	for (i = l ; i <= r ; i++)
	{
		ans += f[i]*tt;
		ans %= a7;
		tt *= t;
		tt %= a7;	
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}