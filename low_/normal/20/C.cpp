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

int n, m, k;
vector <pii> dsk[mn];
int passed[mn], F[mn];
int rev[mn];

vector <int> hardDijkstra(int s, int t)
{
	for (int i=1; i<=n; i++) passed[i]=0, F[i]=-inf, rev[i]=-1;
	priority_queue <pair <int, int> > PQ;
	while (!PQ.empty()) PQ.pop();
	PQ.push({0, s});
	F[s]=0;
	while (!PQ.empty())
	{
		int u=PQ.top().second, f=PQ.top().first;
		PQ.pop();
		if (passed[u]==1) continue;
		if (u==t) break; 
		passed[u]=1;
		
		for (int i=0; i<dsk[u].size(); i++)
		{
			int v=dsk[u][i].first;
			if (passed[v]==1) continue;
			if (F[v]<f-dsk[u][i].second) 
			{
				F[v]=f-dsk[u][i].second;
				rev[v]=u;
			}
			PQ.push({f-dsk[u][i].second, v});
		}
	}
	
	if (rev[t]==-1) return {-1};
	vector <int> ret={};
	int pt=t;
	while (pt!=-1) 
	{
		ret.push_back(pt);
		pt=rev[pt];
	}
	return ret;
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
	
	cin>>n>>m;
	int q, u, v, c;
	for (int i=0; i<m; i++)
	{
		cin>>u>>v>>c;
		dsk[u].push_back({v, c});
		dsk[v].push_back({u, c});
	}
	vector <int> ans=hardDijkstra(1, n);
	for (int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/