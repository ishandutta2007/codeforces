//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define il inline
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
#define inf 1e17
#define mod 998244353
#define Endl endl
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int vall=-100000,valr=100000;
int siz[N],son[N],n,a[N],b[N],dp[N];
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
struct node
{
	int k,b;
}Q[N];
struct
{
	node Nod[1500005];
	bool upt[1500005];
	vector<int>rb;
	int calc(node x,int y)
	{
		return y*x.k+x.b;
	}
	void update(int k,int l,int r,node x)
	{
		if (!upt[k]) 
		{
			upt[k]=1,Nod[k]=x;
			rb.push_back(k);
			return;
		}
		int mid=l+(r-l)/2;
		if (calc(Nod[k],mid)>calc(x,mid)) swap(x,Nod[k]);
		if (l==r) return;
		if (calc(Nod[k],l)>calc(x,l)) update(k<<1,l,mid,x);
		if (calc(Nod[k],r)>calc(x,r)) update(k<<1|1,mid+1,r,x);
	}
	int query(int k,int l,int r,int x)
	{
		if (!upt[k]) return inf;
		if (l==r) return x*Nod[k].k+Nod[k].b;
		if (l>r) puts("wtf");
		int res=x*Nod[k].k+Nod[k].b;
		if (x<=l+(r-l)/2) res=min(res,query(k<<1,l,l+(r-l)/2,x));
		else res=min(res,query(k<<1|1,l+(r-l)/2+1,r,x));
		return res;
	}
	void clear()
	{
		for (int u:rb)
		{
			Nod[u].k=Nod[u].b=0;upt[u]=0;
		}
		rb.clear();
	}

}tree;
void dfs(int k,int fa)
{
	siz[k]=1;son[k]=0;
	for (int u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
}
void ins(int k,int fa)
{ 
	tree.update(1,vall,valr,Q[k]);
	for (int u:G[k])
	{
		if (u==fa) continue;
		ins(u,k);
	}
}
void dfs1(int k,int fa)
{
	for (int u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		dfs1(u,k);
		tree.clear();
	}
	if (son[k]) dfs1(son[k],k);
	for (int u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		ins(u,k);
	}
	if (k!=1&&G[k].size()==1) dp[k]=0;
	else dp[k]=tree.query(1,vall,valr,a[k]);
	Q[k].k=b[k],Q[k].b=dp[k];
	tree.update(1,vall,valr,Q[k]);
}	
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=n;i++)
		b[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs(1,0);
	dfs1(1,0);
	for (int i=1;i<=n;i++) writesp(dp[i]);
}
/*
6
4 -8 9 -1 -2 -7
8 -7 -6 1 1 0
6 1
5 1
2 1
4 1
3 6
-28 0 0 0 0 42
*/