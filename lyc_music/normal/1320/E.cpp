//The Hunting Party - Keys To The Kingdom
//~
#pragma GCC optimize(3,2)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dep[N],st[N][25],dfn[N],DFN;
int fh[N];
vector<int>G[N];
vector<pa>G1[N];
int n,Q;
int tp,sta[N];
pa dis[N];
int spd[N];
priority_queue<pair<pa,int>>q;
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
void ad1(int x,int y)
{
	int w=dep[y]-dep[x];
	G1[x].push_back(mp(y,w));
	G1[y].push_back(mp(x,w));
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) x=st[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	return st[x][0];
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	dfn[k]=++DFN;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
void What_will_Diana_eat_today()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	dfs(1,0);
//	if(n>50) return;
	for (int i=1;i<=n;i++)
		dis[i]=mp(inf,inf);
	Q=read();
	while (Q--)
	{
		int K=read(),M=read();
		vector<int>nowa,Gall,nowq;
		for (int i=1;i<=K;i++)
		{
			int x=read(),y=read();
			spd[i]=y;
			dis[x]=mp(0,i);
			fh[x]=0;
//			if (n<=50)
//			{
				nowa.push_back(x);
				q.push(mp(mp(0,-i),x));
//			}
		}
		for (int i=1;i<=M;i++)
		{
			int x=read();
//			if (n<=50)
//			{
				nowa.push_back(x);
				nowq.push_back(x);
//			}
		}
		sort(nowa.begin(),nowa.end(),cmp);
//		if (n<=50){
		tp=0;
		if (nowa[0]!=1) sta[++tp]=1;
		Gall=nowa;
		if (nowa[0]!=1) Gall.push_back(1);
		for (auto u:nowa)
		{
			if (!tp||tp==1) 
			{
				sta[++tp]=u;
				continue;
			}
			int x=lca(u,sta[tp]);
			if (x==sta[tp])
			{
				sta[++tp]=u;
				continue;
			}
			while (tp>1&&dfn[x]<dfn[sta[tp-1]])
			{
				ad1(sta[tp-1],sta[tp]);
				tp--;
			}
			if (x==sta[tp])
			{
				sta[++tp]=u;
			} else
			{
				ad1(x,sta[tp]);
				sta[tp]=x;
				Gall.push_back(x);
				sta[++tp]=u;
			}
		}
		while (tp>1)
		{
			ad1(sta[tp-1],sta[tp]);
			tp--;
		}
		while (!q.empty())
		{
			int k=q.top().se;
			pa ndis=q.top().fi;
			ndis.fi=-ndis.fi;
			ndis.se=-ndis.se;
			q.pop();
			if (dis[k]!=ndis) continue;
			for (auto U:G1[k])
			{
				pa nfk=ndis;
				int w=U.se;
				int u=U.fi;
				int fh1=fh[k]+w;
				nfk.fi=(fh1+spd[nfk.se]-1)/spd[nfk.se];
				if (dis[u]>nfk)
				{
					dis[u]=nfk;
					fh[u]=fh1;
					nfk.fi=-nfk.fi;
					nfk.se=-nfk.se;
					q.push(mp(nfk,u));
				}
			}
		}
//		}
		
		for (auto u:nowq) writesp(dis[u].se);
		
		puts("");
		for (auto u:Gall) vector<pa>().swap(G1[u]),dis[u]={inf,inf},fh[u]=inf;
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/