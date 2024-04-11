// Lynkcat.
// Problem: C. Column Swapping
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n,m,p[N],pp[N];
void BellaKira()
{
	cin>>n>>m;
	vector<poly> a(n+5,vector<int>(m+5,0)),b;
	b=a;
	for (int j=1;j<=m;j++) pp[j]=0,p[j]=j;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
		stable_sort(p+1,p+m+1,[&](int x,int y)
		{
			return a[i][x]<a[i][y];
		});
	}
	int ans=0;
	// for (int j=1;j<=m;j++)  cout<<p[j]<<",";
	// cout<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			b[i][j]=a[i][p[j]];
		for (int j=1;j<m;j++)
			if (b[i][j]>b[i][j+1]) ans=-1;
		for (int j=1;j<=m;j++)
			if (a[i][j]!=b[i][j]) pp[j]=1;
	}
	if (ans==-1) 
	{
		cout<<-1<<endl;
		return;
	}
	poly g;
	for (int j=1;j<=m;j++)
		if (pp[j]) 
		{
			ans++;
			g.push_back(j);
		}
	// cout<<"?"<<g.size()<<endl;
	if (ans!=2&&ans!=0) cout<<"-1"<<endl;
	else
	{
		if (ans==0) cout<<1<<" "<<1<<endl;
		else
			cout<<g[0]<<" "<<g[1]<<endl;
	}
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}