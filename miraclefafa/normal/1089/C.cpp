//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
int n, m;
const int maxn = 511;
vector<int> con[maxn];
void adde(int x, int y)
{
	con[x].PB(y);
	con[y].PB(x);
}
int dis[maxn][maxn];
int q[maxn], qn;
void bfs(int S)
{
	qn = 0;
	q[qn++] = S;
	for (int i=1; i<=n; i++) dis[S][i] = -1;
	dis[S][S] = 0;
	for (int i=0; i<qn; i++)
	{
		int x = q[i];
		for (int j=0; j<con[x].size(); j++)
		{
			int u = con[x][j];
			if (dis[S][u]==-1)
			{
				dis[S][u] = dis[S][x]+1;
				q[qn++] = u;
			}
		}
	}
}
bool f[maxn];
int find_center()
{
	pair<int,int> ans = MP(1e9, -1);
	for (int i=1; i<=n; i++)
	{
		if (!f[i]) continue;
		int cur = 0;
		for (int j=0; j<con[i].size(); j++)
		{
			int u = con[i][j];
			int cnt = 0;
			for (int t=1; t<=n; t++)
			{
				if (!f[t]) continue;
				cnt += dis[u][t]<dis[i][t];
			}
			cur = max(cur, cnt);
		}
		ans = min(ans, MP(cur, i));
	}
	return ans.SS;
}
void go(int x, int u)
{
	for (int t=1; t<=n; t++)
	{
		if (!f[t]) continue;
		if (dis[u][t]>=dis[x][t]) f[t] = 0;
	}
}
void solve()
{
	for (int i=1; i<=n; i++) f[i] = 1;
	int times = 10;
	while (times--)
	{
		int x = find_center();
		cout<<x<<endl;
		fflush(stdout);
		string s;
		cin>>s;
		if (s=="FOUND") return;
		int u;
		cin>>u;
		go(x, u);
	}
	assert(false);
}
int main()
{
	cin>>n>>m;
	for (int i=1; i<=m; i++)
	{
		int k;
		cin>>k;
		vector<int> v;
		for (int j=1; j<=k; j++)
		{
			int x;
			cin>>x;
			v.PB(x);
		}
		for (int j=0; j+1<k; j++)
		{
			adde(v[j], v[j+1]);
		}
	}
	for (int i=1; i<=n; i++)
	{
		bfs(i);
	}
	for (int i=1; i<=n; i++)
	{
		solve();
	}
    return 0;
}