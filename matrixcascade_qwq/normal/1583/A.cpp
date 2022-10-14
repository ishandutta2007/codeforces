//MatrixCascade AFO.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
int a[202020];
int chk(int x)
{
	if(x==2)return 0;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)return 1;
	}return 0;
}
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		int sum=0;
		up(i,1,n)a[i]=read(),sum+=a[i];
		if(chk(sum))
		{
			cout<<n<<'\n';
			up(i,1,n)
			{
				cout<<i<<" ";
			}
			puts("");
		}
		else
		{
			up(i,1,n)
			{
				if(chk(sum-a[i]))
				{
					cout<<n-1<<'\n';
					up(j,1,i-1)cout<<j<<" ";
					up(j,i+1,n)cout<<j<<" ";
					puts("");
					break;
				}
			}
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