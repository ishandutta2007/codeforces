#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
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
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x , y;
}a[20] , b[20];
int n , m , f[20] , g[20];

int main()
{
	int i , j , ans , cnt;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	for (i = 1 ; i <= m ; i++)
	{
		cin >> b[i].x >> b[i].y;
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= 9 ; j++) g[j] = 0;
		for (j = 1 ; j <= m ; j++)
		{
			if (b[j].x != a[i].x && b[j].y == a[i].y)
			{
				f[b[j].y] = 1;
				g[b[j].y] = 1;
			}
			if (b[j].y != a[i].y && b[j].x == a[i].x)
			{
				f[b[j].x] = 1;
				g[b[j].x] = 1;
			}
			if (b[j].x != a[i].y && b[j].y == a[i].x)
			{
				f[b[j].y] = 1;
				g[b[j].y] = 1;
			}
			if (b[j].y != a[i].x && b[j].x == a[i].y)
			{
				f[b[j].x] = 1;
				g[b[j].x] = 1;
			}
		}
		cnt = 0;
		for (j = 1 ; j <= 9 ; j++)
		{
			if (g[j]) cnt++;
		}
		if (cnt > 1)
		{
			cout << "-1\n";
			return 0;
		}
	}
	for (i = 1 ; i <= m ; i++)
	{
		for (j = 1 ; j <= 9 ; j++) g[j] = 0;
		for (j = 1 ; j <= n ; j++)
		{
			if (a[j].x != b[i].x && a[j].y == b[i].y)
			{
				f[a[j].y] = 1;
				g[a[j].y] = 1;
			}
			if (a[j].y != b[i].y && a[j].x == b[i].x)
			{
				f[a[j].x] = 1;
				g[a[j].x] = 1;
			}
			if (a[j].x != b[i].y && a[j].y == b[i].x)
			{
				f[a[j].y] = 1;
				g[a[j].y] = 1;
			}
			if (a[j].y != b[i].x && a[j].x == b[i].y)
			{
				f[a[j].x] = 1;
				g[a[j].x] = 1;
			}
		}
		cnt = 0;
		for (j = 1 ; j <= 9 ; j++)
		{
			if (g[j]) cnt++;
		}
		if (cnt > 1)
		{
			cout << "-1\n";
			return 0;
		}
	}
	cnt = 0;
	for (i = 1 ; i <= 9 ; i++)
	{
		if (f[i]) 
		{
			cnt++;
			ans = i;
		}
	}
	if (cnt == 1) cout << ans << "\n";
	else cout << "0\n";
	return 0;
}