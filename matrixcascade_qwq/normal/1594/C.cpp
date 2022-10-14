//MatrixCascade AFO.
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
int a[101010];
const int mod=1e9+7;
char c[333330];
signed main()
{
	int T=read();
	while(T--)
	{
		char ch;
		n=read();cin>>ch;scanf("%s",c+1);
		int x=0;
		up(i,1,n)
		{
			if(c[i]!=ch)++x;
		}
		if(x==0)
		{
			puts("0");
			continue;
		}
		if(c[n]==ch)
		{
			puts("1");
			printf("%lld\n",n);
		}
		else
		{
			pu(i,n-1,n/2+1)
			{
				if(c[i]==ch)
				{
					puts("1");
					printf("%lld\n",i);
					error;
				}
			}
			puts("2");
			printf("%lld %lld\n",n,n-1);
			def;
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