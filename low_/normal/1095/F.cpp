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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, m;
int C[mn];

int root[mn];
int getroot(int u)
{
	if (root[u]==u) return u;
	return root[u]=getroot(root[u]);
}

int mini[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>C[i], root[i]=i, mini[i]=inf;
	int u, v, w;
	vector <pair <int, pii> > E={};
	for (int i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		E.push_back({w, {u, v}});
	}
	
	int minv=1;
	for (int i=2; i<=n; i++) if (C[minv]>C[i]) minv=i;
	for (int i=1; i<=n; i++) if (i!=minv) E.push_back({C[i]+C[minv], {i, minv}});
	
	sort(E.begin(), E.end());
	int ans=0;
	for (int i=0; i<E.size(); i++)
	{
		if (getroot(E[i].YY.XX)!=getroot(E[i].YY.YY))
		{
			ans+=E[i].XX;
			root[getroot(E[i].YY.XX)]=getroot(E[i].YY.YY);
		}
	}
	
	int ttl=0, min1=inf, cnt=0;
	for (int i=1; i<=n; i++) mini[getroot(i)]=min(mini[getroot(i)], C[i]);
	for (int i=1; i<=n; i++) if (i==root[i])
	{
		ttl+=mini[i];
		min1=min(min1, mini[i]);
		cnt++;
	}
	
	ans+=ttl+min1*(cnt-2);
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/