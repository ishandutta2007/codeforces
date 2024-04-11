// Lynkcat.
// Problem: C. awoo's Favorite Problem
// URL: https://codeforces.com/contest/1697/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define N 200005
using namespace std;
int n;
string st,st1;
int fa[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void BellaKira()
{
	cin>>n;
	cin>>st>>st1;
	st=' '+st;
	st1=' '+st1;
	int x=0,y=0,z=0;
	for (auto u:st)
		if (u=='a') x++;
		else if (u=='b') y++;
		else if (u=='c') z++;
	for (auto u:st1)
		if (u=='a') x--;
		else if (u=='b') y--;
		else if (u=='c') z--;
	if (x||y||z) return cout<<"NO"<<endl,void();
	poly g;
	for (int i=1;i<=n;i++)
		if (st1[i]=='c') g.push_back(i);
	g.push_back(n+1);
	int oo=0;
	for (int i=1;i<=n;i++)
	{
		if (st[i]=='a')
		{
			fa[i]=i;
		} else
		if (st[i]=='b')
		{
			fa[i]=gf(i-1);
		} else
		{
			if (st[i]=='c')
			{
				fa[i]=gf(i-1);
				int now=fa[i]+1;
				if (now>g[oo]||i<g[oo]) return cout<<"NO"<<endl,void();
				oo++;
			}
		}
	}
	// cout<<"!"<<endl;
	string nowst="";
	
	for (auto u:st) if (u!='c') nowst+=u;
	int l=1,r=0;
	int nowl=1;
	for (auto u:g)
	{
		r=u;
		string pp="";
		for (int i=l;i<r;i++)
			pp+=st1[i];
		string pp1="";
		for (int i=nowl;i<nowl+r-l;i++)
			pp1+=nowst[i];
		nowl+=r-l;
		int x=0,y=0;
		// cout<<"?"<<l<<" "<<r-1<<" "<<pp<<" "<<pp1<<" "<<u<<endl;
		for (int i=0;i<pp.size();i++)
		{
			if (pp[i]=='b') x++;
			if (pp1[i]=='b') y++;
			if (y>x) return cout<<"NO"<<endl,void();
		}
		l=u+1;
	}
	cout<<"YES"<<endl;
		
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