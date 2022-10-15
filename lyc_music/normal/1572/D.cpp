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
#define N 2000005
#define M 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int cc=1;
int cnt;
int a[N];
int S,T;
struct edge
{
	int to,nx,cap,fl,cost;
}G[M<<1];
#undef int 
pair<int,pa>E[21000005];
#define int ll
int dis[N],mn[N],inq[N],lst[N];
int hd[N];
int bl[N];
int MF,MC;
void ad(int x,int y,int fl,int fy)
{
	// assert(cc<=20000);
	// cout<<x<<"->"<<y<<" "<<fy<<endl;
	G[++cc].to=y;
	G[cc].nx=hd[x];
	G[cc].cap=fl;
	G[cc].fl=0;
	G[cc].cost=fy;
	hd[x]=cc;
	
	// assert(cc<=20000);
	G[++cc].to=x;
	G[cc].nx=hd[y];
	G[cc].cap=0;
	G[cc].fl=0;
	G[cc].cost=-fy;
	hd[y]=cc;
}
int SPFA()
{
	queue<int>q;
	for (int i=0;i<(1<<n)+3;i++) dis[i]=inf,mn[i]=inf,inq[i]=0,lst[i]=0;
	q.push((1<<n));
	dis[(1<<n)]=0;
	inq[(1<<n)]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=0;
		for (int i=hd[u];i;i=G[i].nx)
			if (G[i].fl<G[i].cap&&dis[G[i].to]>dis[u]+G[i].cost)
			{
				dis[G[i].to]=dis[u]+G[i].cost;
				mn[G[i].to]=min(mn[u],G[i].cap-G[i].fl);
				if (!inq[G[i].to]) q.push(G[i].to),inq[G[i].to]=1;
				lst[G[i].to]=i;
			}
	}
	if (dis[T]==inf) return 0;
	MF+=mn[T];
	MC+=mn[T]*dis[T];
	int now=T;
	while (now!=S)
	{
		G[lst[now]].fl+=mn[T];
		G[lst[now]^1].fl-=mn[T];
		now=G[lst[now]^1].to;
	}
	return 1;
}
void BellaKira()
{
	n=read(),m=read();
	for (int i=0;i<(1<<n);i++) a[i]=read();
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<n;j++)
			if ((i>>j)%2==0)
			{
				if (__builtin_popcount(i)&1)
					E[++cnt]=mp(-a[i]-a[i^(1<<j)],mp(i,i^(1<<j)));
				else 
					E[++cnt]=mp(-a[i]-a[i^(1<<j)],mp(i^(1<<j),i));
			}
	nth_element(E+1,E+min(cnt,m*(2*n-1)),E+cnt+1);
	S=(1<<n),T=(1<<n)+2;
	for (int i=1;i<=min(cnt,m*(2*n-1));i++)
	{
		ad(E[i].se.fi,E[i].se.se,1,E[i].fi);
		bl[E[i].se.fi]=1;
		bl[E[i].se.se]=1;
	}
	for (int i=0;i<(1<<n);i++)
		if (bl[i])
		ad(S,i,1,0);
	for (int i=0;i<(1<<n);i++)
		if (bl[i])
		ad(i,(1<<n)+1,1,0);
	ad((1<<n)+1,T,min((1ll<<(n-1)),m),0);
	// if (n==20) return;
	while (SPFA())
	{
	}
	
	writeln(-MC);		
	// writeln(MF);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/