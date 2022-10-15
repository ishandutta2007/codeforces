// Problem: O. Circular Maze
// URL: https://codeforces.com/contest/1662/problem/O
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
//~~
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
#define N 100005
using namespace std;
poly S[N];
poly S1[N];
int vis[N];
vector<pa>G[N];
int n;
int fa[100005];
int f[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	fa[x]=y;
}
int id(int x,int y)
{
	x++,y++;
	return (x-1)*360+y;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		char ch;
		int x,y,z;
		cin>>ch>>x>>y>>z;
		if (ch=='C') G[x-1].push_back(mp(y,z));
		else
		{
			S[x].push_back(z);
			S1[y].push_back(z);
		}
	}
	for (int i=1;i<=7920;i++) fa[i]=i;
	for (int i=0;i<360;i++) vis[i]=0,f[i]=0;
	for (int now=0;now<=21;now++)
	{
		for (auto u:S[now])
		{
			vis[u]++;
		}
		for (auto u:S1[now])
		{
			vis[u]--;
		}
		for (int i=0;i<360;i++)	f[i]=1;
		for (auto u:G[now])
		{
			int j=u.fi;
			while (j!=u.se)
			{
				f[j]=0;
				j=(j+1)%360;
			}
		}
		for (int i=0;i<360;i++)
			if (vis[i]==0)
			{
				merge(id(now,i),id(now,(i-1+360)%360));
			}
		if (now==21) break;
		for (int i=0;i<360;i++)
			if (f[i])
			{
				merge(id(now,i),id(now+1,i));
			}
	}
	int ans=0;
	for (int i=0;i<360;i++)
		for (int j=0;j<360;j++)
		if (gf(id(21,i))==gf(id(0,j))) ans=1;
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	for (int now=0;now<=21;now++)
		G[now].clear(),S[now].clear(),S1[now].clear();
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/