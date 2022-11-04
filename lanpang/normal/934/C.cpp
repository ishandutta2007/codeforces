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

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , l[maxn] , r[maxn] , c1 , c2 , ans , ma;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	for (i = 1 ; i <= n ; i++) 
	{
		if (a[i] == 1) l[i] = l[i-1]+1;
		else l[i] = l[i-1];
	}
	for (i = n ; i >= 1 ; i--) 
	{
		if (a[i] == 2) r[i] = r[i+1]+1;
		else r[i] = r[i+1];
	}
	for (i = 0 ; i <= n ; i++)
	{
		ma = max(ma,l[i]+r[i+1]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		c1 = 0;
		c2 = 0;
		ans = 0;
		for (j = i ; j <= n ; j++)
		{
			if (a[j] == 2) 
			{
				c2++;
				ans = max(ans,c2);
			}
			else 
			{
				c1++;
				ans++;
			}
			ma = max(ma,l[i-1]+r[j+1]+ans);
		}
	}
	cout << ma << "\n";
	return 0;
}