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
const LL mod = 1e9+7;

LL n , a[maxn] , c[maxn] , c1 , c2 , ans , cnt;
bool b1 , b2;
char b[maxn];

int main()
{
	LL i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	cin >> b+1;
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i] == 'G') 
		{
			c1 += a[i];
			b1 = true;
		}
		if (b[i] == 'W') 
		{
			c2 += a[i];
			b2 = true;
		}
		if (b[i] == 'L')
		{
			if (c2 >= a[i])
			{
				c2 -= a[i];
				c[i] = a[i];
			}
			else
			{
				if (a[i]-c2 <= c1)
				{
					cnt += a[i]-c2;
					c1 -= a[i]-c2;
				}
				else
				{
					if (b2) ans += (a[i]-c2-c1)*3;
					else ans += (a[i]-c2-c1)*5;
					cnt += c1;
					c1 = 0;
				}
				c[i] = c2;
				c2 = 0;
			}
			ans += a[i];
			a[i] = 0;
		}
	}
	for (i = 1 ; i <= n && cnt > 0 ; i++)
	{
		if (b[i] == 'G')
		{
			if (cnt > a[i])
			{
				ans += a[i]*5;
				cnt -= a[i];
				a[i] = 0;
			}
			else
			{
				ans += cnt*5;
				a[i] -= cnt;
				cnt = 0;
			}
		}
	}
	for (i = n ; i >= 1 ; i--)
	{
		if (b[i] == 'L') cnt += c[i];
		if (b[i] == 'W')
		{
			if (cnt > a[i])
			{
				ans += a[i]*3;
				cnt -= a[i];
				a[i] = 0;
			}
			else
			{
				ans += cnt*3;
				a[i] -= cnt;
				cnt = 0;
			}
		}
	}
	c1 = c2 = 0;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] > 0)
		{
			if (b[i] == 'G')
			{
				if (c2 > a[i])
				{
					ans += a[i]*4;
					c2 -= a[i];
				}
				else
				{
					ans += c2*4;
					c1 += a[i]-c2;
					c2 = 0;
				}
			}
			if (b[i] == 'W') c2 += a[i];
		}
	}
	ans += c1*3+c2*2;
	cout << ans << "\n";
	return 0;
}