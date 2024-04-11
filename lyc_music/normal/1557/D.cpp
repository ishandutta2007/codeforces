//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1000000005
#define mod 998244353
//#define int ll
#define N 3000005
using namespace std;
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>li,E[N];
struct node
{
	int l,r;
};
vector<node>G[N];
int n,m,ans,dis[N],s[N],ls[N],vis[N];
vector<pa>B[N],C[N];
set<int>S;
void ad(int x,int y)
{
	if (x==y) return;
	E[y].push_back(x);
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		node x;
		int y=read();
		x.l=read(),x.r=read();
		G[y].push_back(x);
		li.push_back(x.l),li.push_back(x.r);
	}
	sort(li.begin(),li.end());
	for (int i=1;i<=n;i++)
		for (auto x:G[i])
		{
			x.l=lower_bound(li.begin(),li.end(),x.l)-li.begin()+1;
			x.r=lower_bound(li.begin(),li.end(),x.r)-li.begin()+1;
			B[x.l].push_back({i,1});
			C[x.r+1].push_back({i,-1});
		}
	m=li.size();
	for (int i=1;i<=m;i++)
	{
		for (auto v:C[i])
		{
			s[v.fi]+=v.se;
			if (s[v.fi]==0)
			{
				S.erase(v.fi);
			}
		}
		for (auto v:B[i])
		{
			s[v.fi]+=v.se;
			if (s[v.fi]==1)
			{
				if (S.size()!=0){
				auto it=S.lower_bound(v.fi);
				if (it!=S.end())
				{
					ad(v.fi,(*it));
				}
				if (it!=S.begin())
				{
					it--;
					ad((*it),v.fi);
				}}
				S.insert(v.fi);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		dis[i]=1;ls[i]=i;
		for (auto u:E[i])
		{
			if (dis[u]+1>dis[i]) dis[i]=dis[u]+1,ls[i]=u;
		}
		if (dis[ans]<dis[i]) ans=i;
	}
	writeln(n-dis[ans]);
	while (ls[ans]!=ans)
	{
		vis[ans]=1;
		ans=ls[ans];
	}
	vis[ans]=1;
	for (int i=1;i<=n;i++) if (!vis[i]) writesp(i);
	
	
}
/*

*/