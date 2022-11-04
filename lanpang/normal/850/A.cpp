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
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , p[maxn][5] , a[maxn] , ans;
int t[maxn] , f[maxn][maxn];

int main ()
{
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 0 ; j < 5 ; j++)
		{
			cin >> p[i][j];
		}
	}
	for (int x = 1 ; x <= n ; x++)
	{
		for (int j = 0 ; j < 5 ; j++)
		{
			t[x] += p[x][j]*p[x][j];
			for (int y = 1 ; y <= n ; y++)
			{
				f[x][y] += p[x][j]*p[y][j];
			}
		}
	}
	ans = n;
	for (int x = 1 ; x <= n ; x++)
	{
		for (int y = 1 ; y < n && !a[x] ; y++)	
		{
			for (int z = y+1 ; z <= n && !a[x] ; z++)
			{
				if (y != x && z != x)
				{
					if (t[x]+f[y][z]-f[x][y]-f[x][z] > 0)
					{
						a[x] = 1;
						ans--;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	for (int i = 1 ; i <= n ; i++)
	{
		if (!a[i]) cout << i << "\n";
	}
	//system("PAUSE");
	return 0;
}