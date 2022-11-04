#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 998244353;

int n , k , a[maxn] , la[2];
LL b[maxn] , c[maxn] , d[maxn] , ans;

int main()
{	
	int i , j;
	cin >> n >> k;
	b[0] = 1;
	c[0] = 0;
	d[0] = 1;
	for (i = 1 ; i <= n ; i++)
	{
		b[i] = b[i-1]*(k-1)%mod;
		c[i] = (b[i]-c[i-1]+mod)%mod;
		d[i] = (b[i]-d[i-1]+mod)%mod;
	}
	ans = 1;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (a[i] != -1)
		{
			if (la[i%2] == 0) ans = ans*b[(i-1)/2]%mod;
			else
			{
				if (la[i%2] == i-2)
				{
					if (a[la[i%2]] == a[i])
					{
						cout << "0\n";
						return 0;
					}
				}
				else
				{
					if (a[la[i%2]] == a[i]) ans = ans*c[(i-la[i%2]-2)/2]%mod;
					else ans = ans*d[(i-la[i%2])/2-1]%mod;
				}
			}
			la[i%2] = i;
		}
	}
	if (la[0] == 0) ans = ans*k%mod*b[n/2-1]%mod;
	else ans = ans*b[(n/2*2-la[0])/2]%mod;
	if (la[1] == 0) ans = ans*k%mod*b[(n+1)/2-1]%mod;
	else ans = ans*b[(n/2*2+1-(1-n%2)-la[1])/2]%mod;
	cout << ans << "\n";
	return 0;
}