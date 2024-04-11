// Author: Little09
// Problem: G. Kirill and Company
// Contest: Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) ((x)&(-(x)))


const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=100005;
int n,m,k; 

int dis[N][10],h[N],p,a[N],b[N],ans[N];
bool vis[N];
struct point
{
	int t,v;
	bool operator < (const point & o) const
	{
		return v>o.v;
	}
};
vector<point>t[N];
priority_queue<point>q;
void dij(int s,int tp)
{
	for (int i=1;i<=n;i++) dis[i][tp]=inf,vis[i]=0;
	dis[s][tp]=0;
	point u;
	u.t=s,u.v=0;
	q.push(u);
	while (!q.empty())
	{
		point v=q.top();
		q.pop();
		//cout << v.t << endl;
		if (vis[v.t]==1) continue;
		vis[v.t]=1;
		for (int i=0;i<t[v.t].size();i++) 
		{
			point to=t[v.t][i];
			if (dis[to.t][tp]>dis[v.t][tp]+to.v) 
			{
				dis[to.t][tp]=dis[v.t][tp]+to.v;
				point nxt={to.t,dis[to.t][tp]};
				q.push(nxt);
			}
		}
	}
}

bool visa[N];
bool gg[N];
bool dp[N],tmp[N];

void dfs(int x,int S,int di,int las,int v)
{
	if (dis[v][las]+di==dis[v][0])
	{
		//cout << v << " " << S << endl;
		gg[S]=1;
	}
	if (x==p+1) return;
	for (int i=1;i<=p;i++)
	{
		if (visa[i]) continue;
		visa[i]=1;
		dfs(x+1,S|(1<<(i-1)),di+dis[h[a[i]]][las],i,v);
		visa[i]=0;
	}
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		t[y].push_back({x,1});
		t[x].push_back({y,1});
	}
	dij(1,0);
	cin >> k;
	for (int i=1;i<=k;i++) cin >> h[i];
	for (int i=1;i<=k;i++) b[i]=0,ans[i]=0;
	cin >> p;
	for (int i=1;i<=p;i++) cin >> a[i];
	for (int i=1;i<=p;i++) b[a[i]]=1,ans[a[i]]=1;
	for (int i=1;i<=p;i++) dij(h[a[i]],i);
	for (int j=0;j<(1<<p);j++) dp[j]=0;
	dp[0]=1;
	for (int i=1;i<=k;i++)
	{
		if (b[i]) continue;
		for (int j=0;j<(1<<p);j++) gg[j]=0;
		dfs(1,0,0,0,h[i]);
		for (int j=0;j<(1<<p);j++) tmp[j]=0;
		for (int j=0;j<(1<<p);j++) 
		{
			for (int k=0;k<(1<<p);k++) tmp[j|k]|=gg[j]&dp[k];
		}
		for (int k=0;k<(1<<p);k++) dp[k]=tmp[k];
		// for (int j=1;j<=p;j++)
		// {
			// if (dis[h[a[j]]][0]+dis[h[i]][j]==dis[h[i]][0]) ans[a[j]]=0;
		// }
	}
	int res=0;
	for (int i=0;i<(1<<p);i++) if (dp[i]) res=max(res,__builtin_popcount(i));
	cout << p-res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}