// Lynkcat.
// Problem: D1. Permutation Weight (Easy Version)
// URL: https://codeforces.com/contest/1685/problem/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
#define N 205
using namespace std;
int n,fa[N],p[N],ip[N];
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
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i];
		ip[p[i]]=i;
		merge(i,p[i]);
	}
	for (int i=1;i+1<=n;i++)
		if (gf(i)!=gf(i+1))
		{
			p[ip[i]]=i+1;
			p[ip[i+1]]=i;
			swap(ip[i],ip[i+1]);
			merge(i,i+1);
		}
	poly ans;
	int now=1;
	do
	{
		ans.push_back(now);
		now=p[now];
	}while (now!=1);
	reverse(ans.begin(),ans.end());
	for (auto u:ans) cout<<u<<" ";
	cout<<endl;
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