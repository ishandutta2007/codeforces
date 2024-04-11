#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int F[2005][2005], C[2005][2005];
vector <int> dsk[2005];
int m, n, s, t;

void inp_proc()
{
	s=2001, t=2002;
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>C[i][t], dsk[i].push_back(t), dsk[t].push_back(i);
	int u, v;
	for (int i=1001; i<=1000+m; i++) 
	{
		cin>>u>>v>>C[s][i];
		C[i][u]=inf;
		C[i][v]=inf;
		dsk[i].push_back(u);
		dsk[i].push_back(v);
		dsk[u].push_back(i);
		dsk[v].push_back(i);
	}
	for (int i=1001; i<=1000+m; i++) dsk[s].push_back(i), dsk[i].push_back(s);
}

int par[2005], maxflow=0;

bool find_flow()
{
	for (int i=1; i<=t; i++) par[i]=0;
	deque <int> DQ={s};
	while (!DQ.empty())
	{
		int u=DQ.front();
		DQ.pop_front();
		if (u==t) return 1;
		for (int i:dsk[u]) if (C[u][i]>F[u][i] && par[i]==0)
		{
			par[i]=u;
			DQ.push_back(i);
		}
	}
	return 0;
}

void inc_flow()
{
	int u=t, D=inf;
	while (u!=s)
	{
		int v=par[u];
		D=min(D, C[v][u]-F[v][u]);
		u=v;
	}
	
	u=t;
	while (u!=s)
	{
		int v=par[u];
		F[v][u]+=D;
		F[u][v]-=D;
		u=v;
	}
	
	maxflow+=D;
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	inp_proc();
//	cerr<<n<<" "<<m<<"\n";
	int cnt=0;
	while (find_flow()) 
	{
//		cerr<<cnt++<<"\n";
		inc_flow();
	}
	int ans=-maxflow;
	for (int i=1001; i<=1000+m; i++) ans+=C[s][i];
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/