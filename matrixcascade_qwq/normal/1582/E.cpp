//MatrixCascade AFO.
//qqqqqqqqqqqqqq

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
int a[101010],sum[101010];
int f[101010][500];

signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read(),sum[i]=sum[i-1]+a[i];
		up(i,0,n+1)
		{
			for(int j=0;j*(j+1)/2<=n;++j)
			{
				f[i][j]=0;
			}
		}
		int i;
		for(i=1;i*(i+1)/2<=n;++i)
		{
			int ff=1;
			int p=n-(i+1)*i/2+1;
			pu(j,p,1)
			{
				int q=(sum[j+i-1]-sum[j-1]);
				if(f[i+j][i-1]>q||i==1)
				{
					f[j][i]=q;ff=0;
					f[j][i]=max(f[j][i],f[j+1][i]);
				}f[j][i]=max(f[j][i],f[j+1][i]);
			}
			if(ff)
			{
				error;
			}
		}
		def;
		cout<<i-1<<'\n';
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/