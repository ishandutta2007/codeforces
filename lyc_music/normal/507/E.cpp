//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
pa dis[N],E[N];
int val[N];
int n,m;
int ans[N];
priority_queue<pair<pa,int>>q;
struct node
{
	int x,y,z;
	node(int a,int b,int c){x=a,y=b,z=c;};
};
vector<node>G[N];
void ad(int x,int y,int w,int id)
{
	G[x].push_back(node(y,w,id));
}
void dfs(int k)
{
	if (k==1) return;
	for (auto U:G[k])
	{
		int u=U.x,w=U.y,z=U.z;
		if (dis[k].fi-1==dis[u].fi&&dis[k].se-w==dis[u].se)
		{
			ans[z]=1;
			dfs(u);
			return;
		}
	}
}
void LYC_music()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		z^=1;
		val[i]=z;
		ad(x,y,z,i);
		ad(y,x,z,i);
		E[i]={x,y};
	}
	for (int i=1;i<=n;i++) dis[i]={inf,inf};
	dis[1]={0,0};
	q.push(mp(mp(0,0),1));
	while (!q.empty())
	{
		pa u=q.top().fi;
		int now=q.top().se;
		q.pop();
		u.fi=-u.fi,u.se=-u.se;
		if (u!=dis[now]) continue;
		for (auto U:G[now])
		{
			int v=U.x,w=U.y;
			if (dis[v]>mp(dis[now].fi+1,dis[now].se+w))
			{
				dis[v]=mp(dis[now].fi+1,dis[now].se+w);
				q.push(mp(mp(-dis[v].fi,-dis[v].se),v));
			}
		}
	}
//	writeln(dis[n].fi);
	dfs(n);
	vector<pair<int,pa>>g;
	for (int i=1;i<=m;i++)
	{
		if (val[i]==1&&ans[i]==1)
		{
			g.push_back(mp(E[i].fi,mp(E[i].se,1)));
		} else
		if (!ans[i]&&val[i]==0) g.push_back(mp(E[i].fi,mp(E[i].se,0)));
	}
	writeln(g.size());
	for (auto u:g) writesp(u.fi),writesp(u.se.fi),writeln(u.se.se);
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/