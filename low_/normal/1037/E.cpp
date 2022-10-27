#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 92233720368547757
#define mn 200005
#define FLN "test"

int n, k, m;
int u, v;
vector <pair <int, int> > edges;
set <int> dsk[mn], ss;
int ans[mn];

void eli(int u)
{
	if (ss.count(u)==0) return;
	
	ss.erase(u);
	for (int j:dsk[u]) dsk[j].erase(u);
	for (int j:dsk[u]) if (dsk[j].size()<k) eli(j);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	edges.assign(m, {0, 0});
	for (int i=0; i<m; i++)
	{
		cin>>edges[i].first>>edges[i].second;
		dsk[edges[i].first].insert(edges[i].second);
		dsk[edges[i].second].insert(edges[i].first);
	}
	for (int i=1; i<=n; i++) ss.insert(i);
	
	for (int i=1; i<=n; i++) if (ss.count(i)==1) if (dsk[i].size()<k) eli(i);
	
	int t1, t2;
	for (int d=m; d>=1; d--)
	{
		ans[d]=ss.size();
		
		t1=edges.back().first, t2=edges.back().second;
		edges.pop_back();
		
		if (dsk[t1].count(t2)==1) dsk[t1].erase(t2);
		if (dsk[t2].count(t1)==1) dsk[t2].erase(t1);
		
		if (dsk[t1].size()<k) eli(t1);
		if (dsk[t2].size()<k) eli(t2);
	}
	
	for (int d=1; d<=m; d++) cout<<ans[d]<<'\n';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: