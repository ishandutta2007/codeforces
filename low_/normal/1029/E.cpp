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
#define inf 9223372036854775799
#define mn 200005
#define FLN "test"

int passed[mn], H[mn], par[mn];
int n;
vector <int> dsk[mn];

priority_queue <pair <int, int> > PQ;

void dfs(int u)
{
	for (int i=0; i<dsk[u].size(); i++) if (H[dsk[u][i]]==-1)
	{
		par[dsk[u][i]]=u;
		H[dsk[u][i]]=H[u]+1;
		dfs(dsk[u][i]);
	}
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int u, v;
	cin>>n;
	for (int i=1; i<n; i++)
	{
		H[i+1]=-1;
		cin>>u>>v;
		dsk[u].push_back(v);
		dsk[v].push_back(u);
	}
	H[1]=0;
	dfs(1);
	
	while (!PQ.empty()) PQ.pop();
	for (int i=1; i<=n; i++) PQ.push({H[i], i});
	int ans=0;
	pair <int, int> temp;
	while (PQ.top().first>2)
	{
		temp=PQ.top();
		PQ.pop();
		if (H[temp.second]!=temp.first) continue;
		
	//	cerr<<temp.second<<'\n';
		ans++;
		H[par[temp.second]]=1;
		for (int i=0; i<dsk[par[temp.second]].size(); i++) H[dsk[par[temp.second]][i]]=min(H[dsk[par[temp.second]][i]], (int)2);
	}
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: