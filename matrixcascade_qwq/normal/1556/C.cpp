//This code is made by Yiran Empty.
//GrandMaster When??

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
int a[2020];
int f[2020],g[2020];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		int ans=0;
		up(i,1,n)
		{
			if(i&1)f[i]=f[i-1]+a[i];
			else f[i]=f[i-1]-a[i];
		}
		up(i,1,n)
		{
			if(i&1)
			{
				int nw=0;
				int pw=1e18+10;
				up(j,i+1,n)
				{
					int w=f[j-1]-f[i];
					if(j&1)
					{
						nw+=a[j];
						pw=min(pw,nw);
					}
					else
					{
						int u=max(-pw,1ll);
						if(u<=a[i]&&min(a[i],a[j]-w)>=u)
						{
							ans+=min(a[i],a[j]-w);
							ans-=u;
							ans++;
						}
						nw-=a[j];
						pw=min(pw,nw);
					}
				}
			}
		}
		cout<<ans;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/