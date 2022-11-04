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
const int maxn = 1e4+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , m , a[20][maxn] , dis[20][20];
bool dp[70010][20];
vector<int> v[20];
struct mmp{
	int x , y;
}p;
vector<mmp> q;

bool check(int d)
{
	int i , j , k , x , y , z;
	for (i = 1 ; i <= n ; i++)
	{
		v[i].clear();
		for (j = 1 ; j <= n ; j++)
			if (dis[i][j] >= d && i != j) v[i].push_back(j);
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 0 ; j < (1<<n) ; j++)
			for (k = 1 ; k <= n ; k++)
				dp[j][k] = false;
		q.clear();
		p.x = (1<<(i-1));
		p.y = i;
		dp[p.x][p.y] = true;
		q.push_back(p);
		for (j = 0 ; j < q.size() ; j++)
		{
			x = q[j].x;
			y = q[j].y;
			for (k = 0 ; k < v[y].size() ; k++)
			{
				z = (1<<(v[y][k]-1));
				if ((x&z) == 0 && dp[x|z][v[y][k]] == false)
				{
					p.x = (x|z);
					p.y = v[y][k];
					dp[p.x][p.y] = true;
					q.push_back(p);
				}
			}
		}
		for (j = 1 ; j <= n ; j++)
		{
			if (dp[(1<<n)-1][j] == true)
			{
				for (k = 2 ; k <= m ; k++)
					if (abs(a[i][k]-a[j][k-1]) < d) break;
				if (k > m) return true;
			}
		}
	}
	return false;
}

int main()
{
	int i , j , k , l , r , mid;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		for (j = 1 ; j <= m ; j++)
			scanf("%d",&a[i][j]);
	for (i = 1 ; i < n ; i++)
	{
		for (j = i+1 ; j <= n ; j++)
		{
			dis[i][j] = dis[j][i] = 1000000000;
			for (k = 1 ; k <= m ; k++)
			{
				dis[i][j] = min(dis[i][j],abs(a[i][k]-a[j][k]));
				dis[j][i] = min(dis[j][i],abs(a[j][k]-a[i][k]));
			}
		}
	}
	l = 0;
	r = 1000000000;
	while (l <= r)
	{
		mid = (l+r)/2;
		if (check(mid)) l = mid+1;
		else r = mid-1;
	}
	cout << r << "\n";
	return 0;
}