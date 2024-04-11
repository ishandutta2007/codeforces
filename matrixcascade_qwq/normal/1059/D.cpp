/*
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
And in that light,I find deliverance.
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
int x[101010],y[101010];
const double eps=5e-7;
int check(double p)
{
	double l=-1e18,r=1e18;
	up(i,1,n)
	{
		if(y[i]>2*p)return 0;
		double rd=sqrt(1.0*(2*p-1.0*y[i])*1.0*y[i]);
		l=max(l,(double)(x[i]-rd));
		r=min(r,(double)(x[i]+rd));
	}return l<r;
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)x[i]=read(),y[i]=read();
		int p1=0,p2=0;
		up(i,1,n)
		{
			if(y[i]>=0)++p1;
			else ++p2;
		}
		if(p1!=n&&p2!=n)
		{
			puts("-1");
			return 0;
		}
		if(p2==n)
		{
			up(i,1,n)y[i]*=-1;
		}
		double l=0,r=1e18+10;
		int TT=200;
		while(TT--)
		{
			double mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid;
		}
		printf("%.6lf",l);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/