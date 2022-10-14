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
struct node
{
	int x,y,w,id;
	bool operator <(const node &u)const
	{
		return abs(w)==abs(u.w)?w<u.w:abs(w)<abs(u.w); 
	}
}q[333],t[333];
const int maxn=333;
int fa[maxn];
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    fa[fx]=fy;
}
void S(int x)
{
    up(i,1,x)fa[i]=i;
}
int f[2010101],tot;
vector<int>v[2001002];
ll query(ll x)
{
	int pos=lower_bound(f+1,f+tot+1,x)-f;
	ll ans=0;
	fp v[pos] pf ans+=abs(x-q[to].w);
	return ans;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		up_(m)
		{
			int x,y,z;
			rd(x);rd(y);rd(z);
			q[i].x=x;q[i].y=y;q[i].w=z;q[i].id=i;
		}
		up_(m)
		{
			upm
			{
				int x=abs(q[i].w-q[j].w),y=min(q[i].w,q[j].w);
				if(x%2==0)
				{
					f[++tot]=y+x/2;
				}
				else
				{
					f[++tot]=y+x/2;
					f[++tot]=y+(x+1)/2;
				}
			}
		}
		f[++tot]=0;f[++tot]=100000000ll;
		sort(f+1,f+tot+1);
		int qq=unique(f+1,f+tot+1)-f-1;
		tot=qq;
		up(i,1,tot)
		{
			up(j,1,m)
			{
				t[j].x=q[j].x;t[j].y=q[j].y;t[j].w=q[j].w-f[i];t[j].id=q[j].id;
			}
			S(55);
			sort(t+1,t+m+1);
			up(j,1,m)
			{
				int x=find(t[j].x),y=find(t[j].y);
				if(find(x)==find(y))continue;
				else
				{
					fa[x]=y;
					v[i].ep(t[j].id);
				}
			}
		}
		int p,a,b,c;rd(p);rd(k);rd(a);rd(b);rd(c);
		ll nw;
		ll u=0;
		up(i,1,p)
		{
			nw=read();
			u^=query(nw);
		}
		up(i,p+1,k)
		{
			nw=(1ll*nw*a+b)%c;
			u^=query(nw);
		}
		opl(u);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/