//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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

const int maxn=5e6+10;
int head[maxn*1],to[maxn*2],nxt[maxn*2],w[maxn*2],tot;
Mod998;
void add(int a,int b,int c)
{
    to[++tot]=b;
    nxt[tot]=head[a];
    head[a]=tot;
    w[tot]=c;
}
struct node
{
    int dis,nw;
    node(int diss,int nww)
    {
        dis=diss,nw=nww;
    }
    bool operator <(const node &q)const
    {
        return dis>q.dis;
    }
};
priority_queue<node>q;
int dis[maxn];
void dij(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push(node(0,s));
    while(!q.empty())
    {
        node ze=q.top();
        q.pop();
        int nw=ze.nw,val=ze.dis;
        if(val>dis[nw])continue;
        for(int i=head[nw];i;i=nxt[i])
        {
            int v=to[i];
            if(dis[nw]+w[i]<dis[v])
            {
                dis[v]=dis[nw]+w[i];

                q.push(node(dis[v],v));
            }
        }
    }   
}
int diss[1010101];
vector<pii>v[1010101];
int xx[303033],yy[303033];
void solve()
{
	up(i,1,n+n)diss[i]=1e18;
	priority_queue<node>q2;
	up(i,1,m)
	{
		v[xx[i]].ep(mkp(yy[i],1));
		v[yy[i]+n].ep(mkp(xx[i]+n,1));
	}
	up_(n)
	{
		v[i].ep(mkp(i+n,1e11));
		v[i+n].ep(mkp(i,1e11));
	}
	up(i,1,n)
	{
		if(dis[n*18+i]<=1e10)
		{
			diss[i]=dis[n*18+i];
//			cout<<i<<" "<<diss[i]<<"\n";
			q2.push(node(diss[i],i));
		}
	}//edl;
	while(!q2.empty())
	{
		auto pt=q2.top();q2.pop();
		int nw=pt.nw,val=pt.dis;
//		cout<<nw<<" "<<diss[nw];edl;
        if(val>diss[nw])continue;
//        cout<<nw<<" : ";
        for(auto [to,vl]:v[nw])
        {
//        	mc;
//			opls(to);
//			if(to==n)mc;
        	if(val+vl<diss[to])
        	{
        		diss[to]=val+vl;
        		q2.push(node(diss[to],to));
			}
		}//edl;
	}
//	mc;
	int ds=min(diss[n],diss[n+n]);
	int dst=ds/(100000000000ll);
	int ans=ds%(100000000000ll);
//	cout<<ds<<" "<<dst;edl;
	up(i,19,19+dst-1)
	{
		ans+=qpow(2,i-1);ans%=mod;
	}
	cout<<ans;
}

signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		up_(m)
		{
			int x,y;rd(x);rd(y);
			xx[i]=x;yy[i]=y;
			up(j,0,18)
			{
				if(j&1)add(j*n+y,j*n+x,1);
				else add(j*n+x,j*n+y,1);
			}
		}
		upn
		{
			up(j,1,19)
			{
				add((j-1)*n+i,j*n+i,qpow(2,j-1));
			}
		}
		int ans=1e10;
		dij(1);
		up(j,0,18)
		{
			chkmin(ans,dis[j*n+n]);
		}
		if(ans!=1e10)
		{
			cout<<ans;return 0;
		}
		solve();
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/

/*
50 49
1 3
6 46
47 25
11 49
47 10
26 10
12 38
45 38
24 39
34 22
36 3
21 16
43 44
45 23
2 31
26 13
28 42
43 30
12 27
32 44
24 25
28 20
15 19
6 48
41 7
15 17
8 9
2 48
33 5
33 23
4 19
40 31
11 9
40 39
35 27
14 37
32 50
41 20
21 13
14 42
18 30
35 22
36 5
18 7
4 49
29 16
29 17
8 37
34 46
*/