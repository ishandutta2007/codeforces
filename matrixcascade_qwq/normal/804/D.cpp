/*
.
,?
*/
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
#define edge1 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot,w[maxn<<1];\
void add(int a,int b,int c)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;w[tot]=c;\
}
#define Mod998 const int mod=998244353;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define Mod1e9 const int mod=1e9+7;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define DSU int fa[maxn];\
int find(int x)\
{\
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);\
}\
void merge(int x,int y)\
{\
    int fx=find(x),fy=find(y);\
    if(fx==fy)return;\
    fa[fx]=fy;\
}\
void S(int x)\
{\
    up(i,1,x)fa[i]=i;\
}
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
void print(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}


#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
/*
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	//do sth
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		//do sth
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)update(ls,l,mid,ql,qr);
	if(mid<qr)update(rs,mid+1,r,ql,qr);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)
	{
		query(ls,l,mid,ql,qr);
	}
	if(mid<qr)
	{
		query(rs,mid+1,r,ql,qr);
	}
	return;
}
*/
const int maxn=202020;
int bel[202020],blo,l[202020],dep[202020],r[202020],dep2[202020],siz[202020];
int f[202020],len[202020];
vector<int>v[maxn],vv[maxn];
vector<int>g[maxn];
void dfs(int x,int fa)
{
	siz[blo]++;
	bel[x]=blo;
//	if(!fa)dep[x]=1;
	if(dep[x]>=dep[l[blo]])
	{
		l[blo]=x;
	}
	fp v[x] pf
	{
		if(to==fa)continue;
		dep[to]=dep[x]+1;
		dfs(to,x);
	}
}
void dfs1(int x,int fa)
{
//	if(!fa)dep[x]=1;
	if(dep[x]>=dep[r[blo]])
	{
		r[blo]=x;
	}
	fp v[x] pf
	{
		if(to==fa)continue;
		dep[to]=dep[x]+1;
		dfs1(to,x);
	}
}
void dfs2(int x,int fa)
{
//	if(!fa)dep2[x]=1;
	len[x]=max(dep[x],dep2[x]);
	fp v[x] pf
	{
		if(to==fa)continue;
		dep2[to]=dep2[x]+1;
		dfs2(to,x);
	}
}
map<pii,int>mp;
int solve(int x,int y)
{
	if(mp.find(mkp(x,y))!=mp.end())return mp[mkp(x,y)];
	if(mp.find(mkp(y,x))!=mp.end())return mp[mkp(y,x)];
	int mx=max(f[x],f[y]);
//	cout<<mx;edl;
	int as=0;
	if(siz[x]>siz[y])swap(x,y);
	for(auto i:vv[x])
	{
		int l=0,r=vv[y].size()-1,ans=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(i+vv[y][mid]+1<=mx)ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans==-1)
		{
			as+=g[y][siz[y]-1];as+=(siz[y])*(i+1);
		}
		else
		{
			as+=(ans+1)*mx;
//			cout<<ans;edl;
			as+=(g[y][siz[y]-1]-g[y][ans]);
//			cout<<g[y][siz[y]-1]-g[y][ans];edl;
			as+=(siz[y]-ans-1)*(i+1);
		}
	}
	mp[mkp(x,y)]=as;
	return as;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;int q;rd(q);
		upm
		{
			int x,y;rd(x);rd(y);
			v[x].ep(y);v[y].ep(x);
		}
		int tots=0;
		upn
		{
			if(!bel[i])
			{
				++blo;
				dfs(i,0);
				dep[l[blo]]=0;
				dfs1(l[blo],0);
//				if(blo==1)cout<<dep[1],edl;
				dfs2(r[blo],0);
				f[blo]=dep[r[blo]];
		//		opl(siz[blo]);edl;
//				sum[blo]=1.0*sum[blo]/siz[blo];
				tots+=siz[blo];
			}
		}
		upn vv[bel[i]].ep(len[i]);
		up(i,1,blo)sort(vv[i].begin(),vv[i].end());
		up(i,1,blo)
		{
			g[i].ep(vv[i][0]);
			up(j,1,vv[i].size()-1)g[i].ep(g[i][j-1]+vv[i][j]);
//			up(j,0,g[i].size()-1)cout<<g[i][j]<<" ";mc;
		}
//		up(i,1,blo)
//		{
//			fp vv[i] pf cout<<to<<" ";mc;
//		}
		assert(tots==n);
		while(q--)
		{
			int x,y;rd(x);rd(y);
			int ans;
			if(bel[x]==bel[y])puts("-1");
			else
			{
				ans=solve(bel[x],bel[y]);
				double ass=ans;
//				cout<<siz[bel[x]]<<" "<<siz[bel[y]];edl;
				ass/=(1.0*siz[bel[x]]*siz[bel[y]]);
				printf("%.9lf\n",ass);
			}
		}
		
	}
}
/*

*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/