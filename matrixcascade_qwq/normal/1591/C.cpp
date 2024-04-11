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
#define fr for(auto to:
#define rf )
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
int a[202020];
int b[202020],c[202020];
signed main()
{
	int T=read();
	while(T--)
	{
		rd(n);rd(k);
		upn rd(a[i]);
		int q1=0,q2=0;
		upn
		{
			if(a[i]>0)b[++q1]=a[i];
			else c[++q2]=-1*a[i];
		}
		sort(b+1,b+q1+1);
		sort(c+1,c+q2+1);
		int ans1=0,mx=Max();
		for(int i=q1;i>=1;i-=k)
		{
			/*
			1
			9 3
			-5 -10 -15 6 5 8 3 7 4
			*/
			if(i<=k)
			{
				int w=Max();
				pu(j,i,1)w=max(w,b[i]);
				mx=max(mx,w);ans1+=w;
				break;
			}
			else
			{
				int w=Max();
				pu(j,i,i-k+1)w=max(w,b[i]);
				mx=max(mx,w);ans1+=w;
			}
		}
		int ans2=0,mxx=Max();
		for(int i=q2;i>=1;i-=k)
		{
			if(i<=k)
			{
				int w=Max();
				pu(j,i,1)w=max(w,c[i]);
				mxx=max(mxx,w);ans2+=w;
				break;
			}
			else
			{
				int w=Max();
				pu(j,i,i-k+1)w=max(w,c[i]);
				mxx=max(mxx,w);ans2+=w;
			}
		}
		cout<<ans1*2+ans2*2-max(mx,mxx);edl;
	}
}
/*
1
5 3
2 2 3 3 3
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/