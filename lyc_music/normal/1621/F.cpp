// Lynkcat.
// Problem: F. Strange Instructions
// URL: https://codeforces.com/contest/1621/problem/F
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
//#define N
using namespace std;
int n,a,b,c;
string st;
int s[2];
poly g[2];
int typ1(int L,int R)
{
	poly g0=g[0],g1=g[1];
	int l=0,l1=0;
	int ans=0;
	int sm=0;
	int res=s[1]-g[1].size();
	if (L>1||R>1||(s[0]-L-R)>g[0].size()) ans=max(ans,a);
	for (int i=0;;i++)
	{
		while (l<g[0].size()&&g[0][l]<=1) l++;
		if (res)
		{
			if (l>=g[0].size())
			{
				if (L>1) sm+=a,L--;
				else
				if (R>1) sm+=a,R--;
				else
				if (g[0].size())
				{
					sm-=c;
					g[0].pop_back();
					g[1][g[1].size()-2]+=g[1].back();
					g[1].pop_back();
					res++;
				} else
				if (L)
				{
					L--;
					sm-=c;
				} else
				if (R)
				{
					R--;
					sm-=c;
				} else break;
			} else
			{
				g[0][l]--;
				sm+=a;
			}
			sm+=b;
		} else
		{
			if (l1>=g[0].size()) break;
			if (g[0][l1]==1)
			{
				l1++;
				sm-=c;
				res++;
			} else break;
			sm+=b;
		}
		res--;
		while (l<g[0].size()&&g[0][l]<=1) l++;
		if (L>1||R>1||(l<g[0].size())) ans=max(ans,sm+a);
		else ans=max(ans,sm);
	}
	g[0]=g0,g[1]=g1;
	return ans;
}
int typ2(int L,int R)
{
	poly g0=g[0],g1=g[1];
	int l=0,l1=0;
	int ans=0;
	int sm=0;
	int res=s[1]-g[1].size();
	if (!res) return 0;
	res--;
	sm+=b;
	ans=max(ans,sm);
	for (int i=0;;i++)
	{
		while (l<g[0].size()&&g[0][l]<=1) l++;
		if (res)
		{
			if (l>=g[0].size())
			{
				if (L>1) sm+=a,L--;
				else
				if (R>1) sm+=a,R--;
				else
				if (g[0].size())
				{
					sm-=c;
					g[0].pop_back();
					g[1][g[1].size()-2]+=g[1].back();
					g[1].pop_back();
					res++;
				} else
				if (L)
				{
					L--;
					sm-=c;
				} else
				if (R)
				{
					R--;
					sm-=c;
				} else break;
			} else
			{
				g[0][l]--;
				sm+=a;
			}
			sm+=b;
		} else
		{
			if (l1>=g[0].size()) break;
			if (g[0][l1]==1)
			{
				l1++;
				sm-=c;
				res++;
			} else break;
			sm+=b;
		}
		res--;
		while (l<g[0].size()&&g[0][l]<=1) l++;
		if (L>1||R>1||(l<g[0].size())) ans=max(ans,sm+a);
		else ans=max(ans,sm);
	}
	g[0]=g0,g[1]=g1;
	return ans;
}
void BellaKira()
{
	g[0].clear(),g[1].clear(),s[0]=0,s[1]=0;
	cin>>n>>a>>b>>c;
	cin>>st;
	int nowx=st[0]-'0',nowy=1;
	int L=0,R=0,lst=0;
	for (auto u:st) s[u-'0']++;
	for (int i=1;i<st.size();i++)
	{
		if (st[i]!=st[i-1])
		{
			if (lst==0&&nowx==0)
			{
				L=nowy;
			} else
			{
				g[nowx].push_back(nowy);
			}
			nowx=st[i]-'0';
			nowy=1;
			lst=i;
		} else nowy++;
	}
	sort(g[0].begin(),g[0].end());
	sort(g[1].begin(),g[1].end());
	if (nowx==0) R=nowy;
	else 
		g[nowx].push_back(nowy);
	cout<<max(typ1(L,R),typ2(L,R))<<endl;
			
			
			
				
				
			
			
		
			
			
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