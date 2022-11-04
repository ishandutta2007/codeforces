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
const int maxn = 3e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , b[maxn] , top[maxn] , q[maxn] , len , f[maxn][30] , ans;
vector <int> a[maxn];
char c;

int main ()
{
	int i , j , k , x , y;
	cin >> n >> m;
	c = getchar();
	for (i = 1 ; i <= n ; i++)
	{
		c = getchar();
		b[i] = c-'a';
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		top[y]++;
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (top[i] == 0)
		{
			len++;
			q[len] = i;
			f[i][b[i]]++;
		}
	}
	for (i = 1 ; i <= len ; i++)
	{
		x = q[i];
		for (j = 0 ; j < a[x].size() ; j++)
		{
			y = a[x][j];
			top[y]--;
			for (k = 0 ; k <= 25 ; k++)
			{
				if (k != b[y]) f[y][k] = max(f[y][k],f[x][k]);
				else f[y][k] = max(f[y][k],f[x][k]+1);
			}
			if (top[y] == 0)
			{
				len++;
				q[len] = y;
			}
		}
	}
	k = 0;
	for (i = 1 ; i <= n ; i++)
	{
		k = max(k,top[i]);
	}
	if (k == 0)
	{
		for (i = 0 ; i <= 25 ; i++)
		{
			for (j = 1 ; j <= n ; j++)
			{
				ans = max(f[j][i],ans);
			}
		}
		cout << ans << "\n";
	}
	else cout << "-1\n";
	//system("PAUSE");
	return 0;
}