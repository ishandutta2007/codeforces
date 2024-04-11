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

vector <int> dsk[mn];
int n;

bool star()
{
	int cn=0;
	
	for (int i=1; i<=n; i++) cn+=(dsk[i].size()>2);
	return (cn==1);
}

bool line()
{
	int c1=0, c2=0;
	
	for (int i=1; i<=n; i++) c1+=(dsk[i].size()==1), c2+=(dsk[i].size()==2);
	return (c1==2 && c2==n-2);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	int u, v;
	for (int i=1; i<n; i++) 
	{
		cin>>u>>v;
		dsk[u].push_back(v);
		dsk[v].push_back(u);
	}
	if (line())
	{
		cout<<"Yes\n"<<1<<"\n";
		for (int i=1; i<=n; i++) if (dsk[i].size()==1) cout<<i<<" ";
	}
	else if (star())
	{
		cout<<"Yes\n";
		int cen;
		for (int i=1; i<=n; i++) if (dsk[i].size()>2) cen=i;
		int ans=0;
		for (int i=1; i<=n; i++) if (dsk[i].size()==1) ans++;
		cout<<ans<<"\n";
		for (int i=1; i<=n; i++) if (dsk[i].size()==1) cout<<cen<<" "<<i<<" "<<"\n";
	}
	else cout<<"No";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: