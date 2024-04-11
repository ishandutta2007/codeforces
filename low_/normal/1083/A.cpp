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
#define mn 300005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, W[mn];
vector <pii> dsk[mn];

int par[mn];
int F[mn], ans[mn];
void DFS(int u)
{
	F[u]=ans[u]=W[u];
	for (pii pp:dsk[u]) if (par[u]!=pp.XX)
	{
		par[pp.XX]=u;
		DFS(pp.XX);
	}
	
	int M1=0, M2=0;
	for (pii pp: dsk[u]) if (par[u]!=pp.XX)
	{
		int C=F[pp.XX]-pp.YY;
//		cerr<<u<<" "<<pp.XX<<" "<<C<<"\n";
		if (C>=M1)
		{
			M2=M1;
			M1=C;
		}
		else if (C>M2) M2=C;
	}
	F[u]+=M1;
	ans[u]+=M1+M2;
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
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>W[i];
	
	int u, v, c;
	for (int i=1; i<n; i++)
	{
		cin>>u>>v>>c;
		dsk[u].push_back({v, c});
		dsk[v].push_back({u, c});
	}
	
//	for (int i=1; i<=n; i++)
//	{
//		cerr<<i<<": ";
//		for (pii j:dsk[i]) cerr<<j.XX<<" ";
//		cerr<<"\n";
//	}
	
	DFS(1);
	int ANS=0;
	for (int i=1; i<=n; i++) 
	{
	//	cerr<<F[i]<<" "<<ans[i]<<" "<<par[i]<<"\n";
		ANS=max(ANS, ans[i]);
	}
	cout<<ANS;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/