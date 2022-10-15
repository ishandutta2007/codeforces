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
#define N  200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fa[N];
poly G,g[N<<2];
int ans[N];
int vis[N];
int a[N];
int tr[N<<2];
pa E[N];
int n,q,len;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void gt(int k)
{
	for (auto u:g[k])
	{
		if (vis[u]) continue;
		G.push_back(u);
	}
}
void pushup(int k) {tr[k]=tr[k<<1]+tr[k<<1|1];}
void update(int k,int l,int r,int x)
{
	if (l==r)
	{
		tr[k]++;
		if (tr[k]>=r-l)
			gt(k);
		return;
	}
	int mid=l+(r-l)/2;
	if (x<=mid) update(k<<1,l,mid,x);
	else update(k<<1|1,mid+1,r,x);
	pushup(k);
	if (tr[k]>=r-l)
		gt(k);
}
void work(int k,int l,int r,int L,int R,int p)
{
	if (L<=l&&r<=R) return g[k].emplace_back(p),void();
	int mid=l+(r-l)/2;
	if (L<=mid) 
		work(k<<1,l,mid,L,R,p);
	if (R>mid) 
		work(k<<1|1,mid+1,r,L,R,p);
}
int query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2,res=0;
	if (L<=mid) res+=query(k<<1,l,mid,L,R);
	if (R>mid) res+=query(k<<1|1,mid+1,r,L,R);
	return res;
}
void BellaKira()
{
	n=read(),q=read();
	for (int i=1;i<=n+1;i++) fa[i]=i;
	while (q--)
	{
		int opt=read();
		if (opt==0)
		{
			int l=read(),r=read();
			int tp=read();
			if (tp==0)
			{
				int i=gf(l);
				for (;i<=r;)
				{
					a[i]=114514;
					update(1,1,n,i);
					fa[i]=gf(i+1);
					i=gf(i);
				}
			} else
			{
				E[++len]=mp(l,r);
				if (query(1,1,n,l,r)==r-l&&gf(l)<=r)
				{
					int ffa=gf(l);
					a[ffa]=1;
					fa[ffa]=gf(ffa+1);
					vis[len]=1;
				} else work(1,1,n,l,r,len);
			}
			for (auto u:G)
			{
				if (query(1,1,n,E[u].fi,E[u].se)==E[u].se-E[u].fi&&gf(E[u].fi)<=E[u].se)
				{
					if (vis[u]) continue;
					int ffa=gf(E[u].fi);
					a[ffa]=1;
					fa[ffa]=gf(ffa+1);
					vis[u]=1;
				}
			}
			G.clear();
		} else
		{
			int l=read();
			if (a[l]==1)
				puts("YES");
			else if (a[l]==0) puts("N/A");
			else puts("NO");
		}
	}
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