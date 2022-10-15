//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct node
{
	int x,y,col;
}sta[N<<2];
int G[N],n,m,K,q,c[N],e[N],Col[N];
pa E[N];
int tp;
int lst[N];
vector<int>g[N<<2];
struct Union_set
{
	int fa[N<<1],h[N<<1];
	int gf(int x)
	{
		if (x==fa[x]) return x;
		return gf(fa[x]);
	}
	inline void merge(int x,int y,int cc)
	{
		x=gf(x),y=gf(y);
		if (x==y) return;
		if (h[x]>h[y]) swap(x,y);
		h[y]+=h[x];
		fa[x]=y;
		sta[++tp]={x,y,cc};
	}
}U[51];
int id(int x,int y)
{
	if (y==0) return x;
	return x+n;
}
void update(int k,int l,int r,int L,int R,int d)
{
	if (L<=l&&r<=R)
	{
//		cout<<"ins "<<k<<" "<<l<<" "<<r<<" "<<d<<endl;
		g[k].push_back(d);
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,R,d);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,d);
}
void slove(int k,int l,int r)
{
	int lsttp=tp;
	for (auto u:g[k])
	{
		int x=E[u].fi,y=E[u].se,z=Col[u];
		U[z].merge(id(x,0),id(y,1),z);
		U[z].merge(id(x,1),id(y,0),z);
//		cout<<"merge "<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<z<<endl;
	}
	if (l==r)
	{
		int x=E[e[l]].fi,y=E[e[l]].se,z=c[l];
		if (U[z].gf(id(x,0))!=U[z].gf(id(y,0)))
		{
			puts("YES");
			Col[e[l]]=z;
		} else
		{
			puts("NO");
		}
		if (l+1<=lst[l]-1)
		update(1,1,q,l+1,lst[l]-1,e[l]);
//		cout<<"!!!"<<k<<" "<<e[l]<<" "<<l+1<<" "<<lst[l]-1<<" "<<U[z].gf(1)<<" "<<U[z].gf(5)<<" "<<U[z].gf(3)<<" "<<z<<endl;
	} else
	{
		slove(k<<1,l,l+(r-l)/2);
		slove(k<<1|1,l+(r-l)/2+1,r);
	}
	while (tp!=lsttp)
	{
		int x=sta[tp].x,y=sta[tp].y,z=sta[tp].col;
		U[z].h[y]-=U[z].h[x];
		U[z].fa[x]=x;
		tp--;
	}
}
signed main()
{
	n=read(),m=read();K=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		E[i].fi=read(),E[i].se=read();
	}
	for (int i=1;i<=q;i++)
	{
		e[i]=read(),c[i]=read();
		lst[G[e[i]]]=i;
		G[e[i]]=i;
		lst[i]=q+1;
	}
	for (int j=1;j<=K;j++)
	for (int i=1;i<=2*n;i++) U[j].fa[i]=i,U[j].h[i]=1;
	slove(1,1,q);
}
/*

*/