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
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x , y , z;
	bool operator < (const mmp op) const{
		return z > op.z;
	}
}p;
int n , m , a[4][maxn][maxn] , ans;
char c[maxn][maxn];
priority_queue <mmp> v[4];

void bfs(int k , int x , int y , int z)
{
	if (z > a[k][x][y]) return;
	if (x > 1 && c[x-1][y] != '#') 
	{
		if (c[x-1][y] == '.') p.z = a[k][x][y]+1;
		else p.z = a[k][x][y];
		if (p.z < a[k][x-1][y]) 
		{
			p.x = x-1;
			p.y = y;
			a[k][x-1][y] = p.z;
			v[k].push(p);
		}
	}
	if (y > 1 && c[x][y-1] != '#') 
	{
		if (c[x][y-1] == '.') p.z = a[k][x][y]+1;
		else p.z = a[k][x][y];
		if (p.z < a[k][x][y-1]) 
		{
			p.x = x;
			p.y = y-1;
			a[k][x][y-1] = p.z;
			v[k].push(p);
		}
	}
	if (x < n && c[x+1][y] != '#') 
	{
		if (c[x+1][y] == '.') p.z = a[k][x][y]+1;
		else p.z = a[k][x][y];
		if (p.z < a[k][x+1][y]) 
		{
			p.x = x+1;
			p.y = y;
			a[k][x+1][y] = p.z;
			v[k].push(p);
		}
	}
	if (y < m && c[x][y+1] != '#') 
	{
		if (c[x][y+1] == '.') p.z = a[k][x][y]+1;
		else p.z = a[k][x][y];
		if (p.z < a[k][x][y+1]) 
		{
			p.x = x;
			p.y = y+1;
			a[k][x][y+1] = p.z;
			v[k].push(p);
		}
	}
	return;
}

int main()
{
	int i , j , k;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		c[i][j] = getchar();
		for (j = 1 ; j <= m ; j++)
		{
			c[i][j] = getchar();
			a[1][i][j] = mod;
			a[2][i][j] = mod;
			a[3][i][j] = mod;
			if ('1' <= c[i][j] && c[i][j] <= '3')
			{
				k = c[i][j]-'0';
				a[k][i][j] = 0;
				p.x = i;
				p.y = j;
				p.z = 0;
				v[k].push(p);
			}
		}
	}
	for (i = 1 ; i <= 3 ; i++)
	{
		while (!v[i].empty())
		{
			bfs(i,v[i].top().x,v[i].top().y,v[i].top().z);
			v[i].pop();
		}
	}
	ans = mod;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= m ; j++)
		{
			if (a[1][i][j] < mod && a[2][i][j] < mod && a[3][i][j] < mod)
			{
				if (c[i][j] == '.') ans = min(ans,a[1][i][j]+a[2][i][j]+a[3][i][j]-2);
				else ans = min(ans,a[1][i][j]+a[2][i][j]+a[3][i][j]);
			}
		}
	}
	if (ans == mod) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}