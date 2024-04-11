//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 150005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int cnt,rt;
struct node
{
	ll k,b;
}tr[15000005];
int lson[15000005],rson[15000005];
int a[N];
ll F[N],dis[N],s[N],dis1[N];
int dep[N],siz[N],son[N];
vector<int>G[N];
ll B=300000000000ll;
ll ans;
int n;
inline void ad(int x,int y)
{
	G[x].push_back(y);
}
inline ll calc(node p,ll x)
{
	return p.b+p.k*x;
}
void update(int &k,ll l,ll r,node now)
{
	if (!k)
	{
		k=++cnt;
		tr[k]=now;lson[k]=0,rson[k]=0;
		return;
	}
	ll mid=l+(r-l)/2;
	if (calc(tr[k],mid)<calc(now,mid))
	{
		swap(now,tr[k]);
	}
	if (l==r) return;
	if (tr[k].k<now.k)
	{
		update(rson[k],mid+1,r,now);
	} else
	{
		update(lson[k],l,mid,now);
	}
}
ll query(int &k,ll l,ll r,ll i)
{
	if (!k) return -inf;
	ll res=calc(tr[k],i),mid=l+(r-l)/2;
	if (i<=mid)
	{
		res=max(res,query(lson[k],l,mid,i));
	} else res=max(res,query(rson[k],mid+1,r,i));
	return res;
}
void dfs(int k,int fa)
{
	F[k]=fa;
	dep[k]=dep[fa]+1;
	dis[k]=dis[fa]+dep[k]*a[k];
	s[k]=s[fa]+a[k];
	dis1[k]=dis1[fa]+s[fa]+a[k];
	siz[k]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
}
inline void work(int k,int rot)
{
	ll now=query(rt,-B,B,dep[k]-dep[rot]-(dep[rot]-1));
	now-=1ll*dis[F[rot]];
	now-=1ll*(s[F[rot]])*(dep[k]-dep[rot]);
	now+=1ll*(s[F[rot]])*(dep[rot]-1);
	now+=1ll*dis1[k];
	now-=1ll*dis1[rot];
	now-=1ll*(dep[k]-dep[rot])*s[rot];
//	cout<<"?"<<k<<" "<<rot<<" "<<now<<" "<<endl;
	ans=max(ans,now);
}
inline void work1(int k,int rot)
{
	ll now=query(rt,-B,B,-s[rot]+s[k]-s[F[rot]]);
//	cout<<"?"<<k<<" "<<rot<<" "<<now<<" "<<" "<<dis1[3]-dis1[2]<<endl;
	now+=1ll*(dep[rot]-1)*(s[F[rot]]);
	now-=1ll*dis1[F[rot]];
	now-=1ll*(dep[rot]-1)*(s[k]-s[rot]);
//	cout<<"?"<<k<<" "<<rot<<" "<<now<<" "<<endl;
	now+=1ll*dis[k]-dis[rot];
	now-=1ll*(s[k]-s[rot])*dep[rot];
//	cout<<"?"<<k<<" "<<rot<<" "<<now<<" "<<dis[4]-dis[2]-5*(dep[k]-dep[rot])<<endl;
	ans=max(ans,now);
}
void que(int k,int fa,int rot)
{
	work(k,rot);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		que(u,k,rot);
	}
}
void que1(int k,int fa,int rot)
{
	work1(k,rot);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		que1(u,k,rot);
	}
}
void ins(int k,int fa)
{
	node now;
	now.k=s[k],now.b=dis[k];
	update(rt,-B,B,now);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		ins(u,k);
	}
}
void ins1(int k,int fa)
{
	node now;
	now.k=dep[k],now.b=dis1[k];
	update(rt,-B,B,now);
	for (auto u:G[k])
	{
		if (u==fa) continue;
		ins1(u,k);
	}
}
void dfs1(int k,int fa)
{
	for (auto u:G[k])
	{
		if(u==fa||u==son[k]) continue;
		dfs1(u,k);
		cnt=0;rt=0;
	}
	if (son[k]) dfs1(son[k],k);
	node now;
	now.k=s[k],now.b=dis[k];
	update(rt,-B,B,now);
	work(k,k);
	for (auto u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		que(u,k,k);
		ins(u,k);
	}
}
void dfs2(int k,int fa)
{
	for (auto u:G[k])
	{
		if(u==fa||u==son[k]) continue;
		dfs2(u,k);
		cnt=0;rt=0;
	}
	if (son[k]) dfs2(son[k],k);
	node now;
	now.k=dep[k],now.b=dis1[k];
	update(rt,-B,B,now);
	work1(k,k);
	for (auto u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		que1(u,k,k);
		ins1(u,k);
	}
}
signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	for (int i=1;i<=n;i++) a[i]=read();
	dfs(1,0);
	dfs1(1,0);
	cnt=0,rt=0;
	dfs2(1,0);
	writeln(ans);
}
/*
4
1 2
2 3
2 4
1 4 3 5
*/