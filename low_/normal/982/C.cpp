#include<iostream>
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
#define mn 100005

int n;
vector <int> dsk[mn];
int decno[mn], par[mn];

void DFS(int u)
{
	for (int i=0; i<dsk[u].size();i++) if (dsk[u][i]!=par[u])
	{
		par[dsk[u][i]]=u;
		DFS(dsk[u][i]);
		decno[u]+=decno[dsk[u][i]];
	}
}


main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	if (n%2==1) 
	{
		cout<<-1;
		return 0;
	}
	
	
	int u, v;
	par[1]=-1;
	decno[1]=1;
	for (int i=1; i<n; i++)
	{
		cin>>u>>v;
		dsk[u].push_back(v);
		dsk[v].push_back(u);
		par[i+1]=-1;
		decno[i+1]=1;
	}
	
	DFS(1);
	int ans=0;
	for (int i=1; i<=n; i++) if (decno[i]%2==0) ans++;
	cout<<ans-1;
	
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: