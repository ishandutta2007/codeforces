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
#define mn 100005
#define FLN "test"

int n, m, k, s;
int Prod[mn];
vector <int> dsk[mn];
int Dist[mn][105];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<mn; i++) for (int j=0; j<105; j++) Dist[i][j]=inf;
	cin>>n>>m>>k>>s;
	for (int i=1; i<=n; i++) cin>>Prod[i];
	int u, v;
	for (int i=1; i<=m; i++)
	{
		cin>>u>>v;
		dsk[u].push_back(v);
		dsk[v].push_back(u);
	}
	
	queue <int> Q;
	for (int c=1; c<=k; c++)
	{
		for (int i=1; i<=n; i++) if (Prod[i]==c) Dist[i][c]=0, Q.push(i);
		while (!Q.empty())
		{
			int t1=Q.front();
			Q.pop();
			
			for (int j:dsk[t1]) if (Dist[j][c]==inf)
			{
				Dist[j][c]=Dist[t1][c]+1;
				Q.push(j);
			}
		}
	}
	
	vector <int> V;
	for (int i=1; i<=n; i++)
	{
		V.clear();
		for (int c=1; c<=k; c++) V.push_back(Dist[i][c]);
		int ans=0;
		sort(V.begin(), V.end());
		for (int i=0; i<s; i++) ans+=V[i];
		cout<<ans<<' ';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: