// Problem: E1. Joking (Easy Version)
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.ml/contest/1746/problem/E1
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
// #define int ll
// #define N 
using namespace std;
int n;
int lst;
int Tot;
int query(poly g)
{
	if (g.empty()) return 0;
	cout<<"? "<<g.size()<<" ";
	for (auto u:g) cout<<u<<" ";
	cout<<endl;
	string st;
	cin>>st;
	return (st=="YES");
}
poly merge(poly x,poly y)
{
	for (auto u:y) x.push_back(u);
	return x;
}
void work(poly g)
{
	if (g.size()==1)
	{
		cout<<"! "<<g[0]<<endl;
		return;
	}
	// cerr<<"?"<<g.size()<<endl;
	if (g.size()==2)
	{
		int x=g[0];
		cout<<"! "<<x<<endl;
		string st;
		cin>>st;
		if (st==":)") return;
		cout<<"! "<<g[1]<<endl;
		cin>>st;
		return;
	}
	int x=(g.size()+3)/4;
	poly G[4];
	for (int i=0;i<g.size();i++)	
		G[i%4].push_back(g[i]);
	static int f[4];
	static int ps[4];
	static int ff[4];
	f[0]=query(merge(G[2],G[3]));
	f[1]=query(merge(G[1],G[3]));
	f[2]=query(merge(G[1],G[3]));
	f[3]=query(merge(G[2],G[3]));
	poly nxt;
	for (int i=0;i<4;i++)
	{
		bool bl=0;
		for (int j=0;j<4;j++)
		{
			if (i==0) 
			{
				ff[j]=f[j]^1;
			}
			else
			if (i==3)
			{
				ff[j]=f[j];
			}   else
			if (i==1)
			{
				ff[j]=(f[j])^(j==1||j==2)^1;
			} else
			{
				ff[j]=(f[j])^(j==0||j==3)^1;
			}
			if (j&&(ff[j]+ff[j-1]==0)) bl=1;
		} 
		if (bl) continue;
		for (auto u:G[i]) nxt.push_back(u);
	}		
	// lst=f[3];
	// cout<<"?"<<nxt.size()<<'\n';
	work(nxt);
}
void BellaKira()
{
	lst=1;
	cin>>n;
	poly g;
	for (int i=1;i<=n;i++) g.push_back(i);
	work(g);
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}