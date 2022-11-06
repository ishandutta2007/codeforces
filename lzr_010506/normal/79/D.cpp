#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;

int n,k,l,t,top,x;
vector<int> g[100005];
int a[100005];
int b[100005];
int dis[20][100005];
int dp[2000005];
int q[100005];
int id[20];

int main()
{
	scanf("%d%d%d", &n, &k, &l);
	rep(i,k)
	{
		scanf("%d", &x);
		a[x] = 1;
	} 
	rep(i,l) scanf("%d", &q[i]);
	sort(q,q+l);
	rep(i,n+1) rep(j,l)
	{
		if(i + q[j] > n) break;
		g[i].emplace_back(i+q[j]);
		g[i+q[j]].emplace_back(i);
	}
	rep(i,n+1) if(a[i] ^= a[i+1])
	{
		//cout << i << endl;
		id[top] = i;
		rep(j,n+1) dis[top][j] = 1e9;
		dis[top][i] = 0;
		vector<int> q = {i};
		rep(j,q.size())
		{
			int v = q[j];
			for(auto y:g[v]) if(dis[top][v]+1 < dis[top][y])
			{
				dis[top][y] = dis[top][v]+1;
				q.emplace_back(y);
			} 
		}
		top++;
	}
	int h = (1<<top);
	rep(i,h) dp[i] = 1e9;
	dp[0] = 0;
	rep(i,h)
	if(i)
	{
		rep(j,top) if(i >> j & 1) t = j;
		rep(j,t) if(i >> j & 1) dp[i] = min(dp[i], dp[i^(1<<j)^(1<<t)] + dis[t][id[j]]); 
	}
	int ans = dp[h-1];
	if(ans == 1e9) ans = -1;
	printf("%d\n", ans);

	return 0;
}