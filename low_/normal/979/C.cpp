#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

int Decn[mn*3], par[mn*3], H[mn*3];
int n, x, y;
vector <int> dsk[mn*3];

void DFS(int u)
{
	Decn[u]=1;
	for (int i=0; i<dsk[u].size(); i++) if (par[u]!=dsk[u][i])
	{
		par[dsk[u][i]]=u;
		H[dsk[u][i]]=H[u]+1;
		DFS(dsk[u][i]);
		Decn[u]+=Decn[dsk[u][i]];
	}
}

int LCA(int a, int b)
{
	if (H[a]<H[b]) return LCA(b, a);
	
	while (H[a]!=H[b]) a=par[a];
	
	while (a!=b) a=par[a], b=par[b];
	
	return a;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>x>>y;
	int a, b;
	for (int i=1; i<=n; i++) Decn[i]=0;
	
	for (int i=1; i<n; i++)
	{
		cin>>a>>b;
		dsk[a].push_back(b);
		dsk[b].push_back(a);
	}
	
	for (int i=1; i<=n; i++) par[i]=-1, H[i]=1;
	DFS(x);
	
//	for (int i=1; i<=n; i++) cout<<par[i]<<" "<<Decn[i]<<"\n";
	int l=LCA(x, y), lx=Decn[x], ly=Decn[y];
	
	if (l==x)
	{
		int t1=y;
		while (par[t1]!=x) t1=par[t1];
		lx-=Decn[t1];
	}
	else if (l==y)
	{
		int t1=x;
		while (par[t1]!=y) t1=par[t1];
		ly-=Decn[t1];
	}
	cout<<(n*(n-1))-lx*ly;
}