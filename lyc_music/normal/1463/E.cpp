//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>g[N],G[N];
int fa[N],siz[N],ru[N];
int tim;
int Nxt[N];
int lst[N],nxt[N],fn[N],A[N];
int n,m;
int H[N];
queue<int>q;
void ad(int x,int y)
{
	g[x].push_back(y);
}
void ad1(int x,int y)
{
	G[x].push_back(y);
	ru[y]++;
}
int gf(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=(gf(fa[x]));
}
void merge(int x,int y)
{
	if (siz[x]>siz[y]) swap(x,y);
		siz[y]+=siz[x];
		for (auto u:g[x])
		{
			g[y].push_back(u);
		}
		g[x].clear();
		siz[x]=0;
		fa[x]=y;
}
void LYC_music()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x) ad(i,x);
		Nxt[i]=x;
	}
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if (nxt[x]||lst[y]) puts("0"),exit(0);
		nxt[x]=y;
		lst[y]=x;
//		if (gf(Nxt[x])==gf(y)) puts("0"),exit(0);
		x=gf(x),y=gf(y);
		if (x==y) puts("0"),exit(0);
		merge(x,y);
	}
	for (int i=1;i<=n;i++)
		if (siz[i])
		{
//			cout<<"?"<<i<<endl;
			for (auto u:g[i])
			{
				if (gf(i)!=gf(u))
				ad1(gf(i),gf(u));
			}
		}
	for (int i=1;i<=n;i++)		
		if (siz[i]&&!ru[i])q.push(i);
	tim=n;
	while (!q.empty())
	{
		int u=q.front();
		tim-=siz[u];
		H[u]=tim;
//		cout<<"!"<<u<<" "<<H[u]<<endl;
		q.pop();
		for (auto v:G[u])
		{
			ru[v]--;
			if (!ru[v]) q.push(v);
		}
	}
//	cout<<tim<<endl;
	if (tim!=0) puts("0"),exit(0);
	for (int i=1;i<=n;i++)
		if (!lst[i])
		{
			if (fn[i]) continue;
			int x=gf(i),y=0,now=i;
//			cout<<"?"<<i<<" "<<H[x]<<endl;
			while (nxt[now])
			{
//				cout<<now<<" "<<nxt[now]<<endl;
				if (fn[now]) puts("0"),exit(0);
				fn[now]=y+1+H[x];
				y++;
				now=nxt[now];
			}
			fn[now]=y+1+H[x];
		}
	for (int i=1;i<=n;i++)
		if (fn[Nxt[i]]>fn[i]) puts("0"),exit(0);
	for (int i=1;i<=n;i++) A[fn[i]]=i;
	for (int i=1;i<=n;i++) writesp(A[i]);
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