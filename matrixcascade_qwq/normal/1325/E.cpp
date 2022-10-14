#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
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
#define edge1 int head[maxn],to[maxn],nxt[maxn],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn],nxt[maxn],tot,w[maxn];\
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
const int N=2e5+10;
int a[N];
const int maxn=2e6+10;
bool e[maxn];
int p[maxn],tot=0;
int mp[maxn];
void sieve(int n)
{
    e[1]=1;
    up(i,2,n)
    {
        if(!e[i])
        {
            p[++tot]=i;mp[i]=tot;
        }
        up(j,1,tot)
        {
            if(p[j]*i>n)break;
            e[p[j]*i]=1;
            if(i%p[j]==0)break;
        }
    }
}
int ans;
vector<int>v[maxn];
bool vis[maxn],vs[maxn];
int dis[maxn];
void bfs(int s)
{
	up(i,0,tot)vis[i]=0,dis[i]=-1;
	queue<pii>q;
	vis[s]=1;
	dis[s]=0;
	q.push(mkp(s,10101015));
	while(!q.empty())
	{
		
	//	mc;
		auto nw=q.front();int x=nw.fi,fa=nw.se;q.pop();vis[x]=1;
	//	if(q.size()>=10000001)cout<<x<<" "<<fa<<" "<<dis[x],assert(0);
	//	cout<<x;edl;
		fp v[x] pf
		{
			if(to==fa)continue;
			if(dis[to]!=-1)
			{
				chkmin(ans,dis[x]+dis[to]+1);
				
			//	cout<<dis[x]<<" "<<dis[to];edl;
			}
			else
			{
				dis[to]=dis[x]+1;q.push(mkp(to,x));vis[to]=1;
			}
		}
	}
}
signed main()
{
	sieve(maxn-10);ans=1e9;//cout<<mp[2];
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(a[i]);
		mii mmp;
		upn
		{
			for(int j=1;p[j]*p[j]<=a[i];++j)
			{
				if(a[i]%(p[j]*p[j])==0)
				{
					while(a[i]%(p[j]*p[j])==0)a[i]/=(p[j]*p[j]);
				}
			}
		}
		upn
		{
			int nw=a[i];
			int x=-1,y=-1;
			for(int j=1;p[j]*p[j]<=a[i];++j)
			{
				if(nw%p[j]==0)
				{
					
					if(x==-1)x=mp[p[j]];
					else y=mp[p[j]];
					while(nw%p[j]==0)nw/=p[j];
				}
			}
	//		mp[nw]
			if(nw>1)
			{
				if(x==-1)x=mp[nw];
				else y=mp[nw];
			}
			if(x==-1&&y==-1)
			{
				puts("1");return 0;
			}
			if(y==-1)y=0;v[x].ep(y);v[y].ep(x);//cout<<x<<" "<<y;edl;
			assert(x<=1000000),assert(y<=1000000);assert(x>=0);assert(y>=0);
		}
		upn
		{
			int nw=a[i];
			for(int j=1;p[j]*p[j]<=a[i];++j)
			{
				if(nw%(p[j]*p[j])==0)
				{
					while(nw%(p[j]*p[j])==0)nw/=(p[j]*p[j]);
				}
			}
			if(nw==1)
			{
				puts("1");return 0;
			}
			mmp[nw]++;
		}//if(n>=50000)return 0;
		fp mmp pf
		{
			if(to.se>1)
			{
				puts("2");return 0;
			}
		}//if(n==100000)return 0;
		up(i,0,tot)
		{
			if(p[i]>1000)break;
			bfs(i);
		}if(ans>100000000)ans=-1;
		if(ans==2)assert(0);
		opd(ans);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/