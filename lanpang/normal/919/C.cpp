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

int n , m , k , a[maxn][maxn] , ans , s;
char c;

int main ()
{
	cin >> n >> m >> k;
	int i , j;
	for (i = 1 ; i <= n ; i++)
	{
		c = getchar();
		for (j = 1 ; j <= m ; j++)
		{
			c = getchar();
			if (c == '*') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		s = 0;
		for (j = 1 ; j <= m ; j++)
		{
			if (a[i][j] == 1) s += 1;
			else
			{
				if (s >= k) ans += s-k+1;
				s = 0;
			}
		}
		if (s >= k) ans += s-k+1;
	}
	for (i = 1 ; i <= m ; i++)
	{
		s = 0;
		for (j = 1 ; j <= n ; j++)
		{
			if (a[j][i] == 1) s += 1;
			else
			{
				if (s >= k) ans += s-k+1;
				s = 0;
			}
		}
		if (s >= k) ans += s-k+1;
	}
	if (k == 1) cout << ans/2 << "\n";
	else cout << ans << "\n";
	//system("PAUSE");
	return 0;
}