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
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int mod=1e9+7;
int a[202020],p;
int fib[202020],vis[202020];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rd(p);
		mii mp;
		upn rd(a[i]),mp[a[i]]=i;
		sort(a+1,a+n+1);
		fib[0]=fib[1]=1;
		up(i,2,p) fib[i]=(fib[i-1]+fib[i-2])%mod;
		up(i,1,p)fib[i]+=fib[i-1],fib[i]%=mod;
		upn
		{
			int nw=a[i];
			while(nw>=1)
			{
				if(nw&1)
				{
					nw--;
					nw/=2;
				}
				else
				{
					if(nw%4!=0)break;
					nw/=4;
				}
				if(mp.count(nw))vis[i]=1;
			}
		}
		int sum=0;
		upn
		{
			if(vis[i])continue;
			int nw=a[i],ans=0;
			while(nw)
			{
				nw/=2;ans++;
			}
			sum+=fib[p-ans];
			sum%=mod;
//			if((1ll<<nw)==a[i])
//			{
//				sum--;sum+=mod;sum%=mod;
//			}
		}
		opl(sum);edl;
	}
}
/*
1y+0
2y+1
4y+0 4y+3
8y+1 8y+4 8y+7
16y+0 12 3 9 15
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/