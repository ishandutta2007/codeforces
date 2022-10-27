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

vector <int> dsk[mn];
int m, n;

bool bus_topol()
{
	int c1=0, c2=0;
	
	for (int i=1; i<=n; i++) 
	{
		if (dsk[i].size()==1) c1++;
		else if (dsk[i].size()==2) c2++;
	}
	
	return (c1==2 && c2==(n-2));
}

bool ring_topol()
{
	int c2=0;
	for (int i=1; i<=n; i++) if (dsk[i].size()==2) c2++;
	return (c2==n);
}

bool star_topol()
{
	int c1=0, cn=0;
	for (int i=1; i<=n; i++) 
	{
		if (dsk[i].size()==1) c1++;
		else if (dsk[i].size()==n-1) cn++;
	}
	
	return (c1==n-1 && cn==1);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int u, v;
	for (int i=0; i<m; i++)
	{
		cin>>u>>v;
		
		dsk[u].push_back(v);
		dsk[v].push_back(u);
		
		
	}
	
	if (bus_topol()) cout<<"bus ";
	else if (star_topol()) cout<<"star ";
	else if (ring_topol()) cout<<"ring ";
	else cout<<"unknown ";
	
	cout<<"topology";
}