/*
qwq
*/


//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
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
#define mkp make_pair
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
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
#define mid ((l+r)>>1)
const int maxn=604040;

int ls[maxn],rs[maxn],cnt=0;
int tot=0;
int lf[maxn],rf[maxn];
int head[maxn*4],to[maxn*4],nxt[maxn*4],w[maxn*4];
void add(int a,int b,int c)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	w[tot]=c;
}
int r1,r2;
void build1(int &p,int l,int r)
{
	if(!p)p=++cnt;
	if(l==r)
	{
		lf[l]=p;return;
	}
	build1(ls[p],l,mid);
	build1(rs[p],mid+1,r);
	if(ls[p])add(ls[p],p,0);
	if(rs[p])add(rs[p],p,0);
}
void build2(int &p,int l,int r)
{
	if(!p)p=++cnt;
	if(l==r)
	{
		rf[l]=p;return;
	}
	build2(ls[p],l,mid);
	build2(rs[p],mid+1,r);
	if(ls[p])add(p,ls[p],0);
	if(rs[p])add(p,rs[p],0);
}
void update1(int p,int l,int r,int ql,int qr,int f,int w)
{
	if(ql<=l&&r<=qr)
	{
		add(f,p,w);return;
	}
	if(ql<=mid)update1(ls[p],l,mid,ql,qr,f,w);
	if(mid<qr)update1(rs[p],mid+1,r,ql,qr,f,w);
}
void update2(int p,int l,int r,int ql,int qr,int f,int w)
{
	if(ql<=l&&r<=qr)
	{
		add(p,f,w);return;
	}
	if(ql<=mid)update2(ls[p],l,mid,ql,qr,f,w);
	if(mid<qr)update2(rs[p],mid+1,r,ql,qr,f,w);
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
int v[maxn*4];
priority_queue<node>q;
int dis[maxn*4];
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

signed main()
{
	int T=1;
	while(T--)
	{
		int q,s;rd(n);rd(q);rd(s);
		build1(r1,1,n);build2(r2,1,n);
		upn
		{
			add(lf[i],rf[i],0);add(rf[i],lf[i],0);
		}
		while(q--)
		{
			int v,l,r,w;
			int opt=read();
			if(opt==1)
			{
				rd(v);rd(l);rd(w);
				add(lf[v],rf[l],w);
			}
			else if(opt==2)
			{
				rd(v);rd(l);rd(r);rd(w);	
				update1(r2,1,n,l,r,lf[v],w);
			}
			else
			{
				rd(v);rd(l);rd(r);rd(w);
				update2(r1,1,n,l,r,rf[v],w);
			}
		}
		dij(lf[s]);
		upn
		{
			if(dis[rf[i]]>=1000000000000ll)dis[rf[i]]=-1;
			opls(dis[rf[i]]);
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/