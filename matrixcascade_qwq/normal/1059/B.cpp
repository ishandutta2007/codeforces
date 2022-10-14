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
char ch[1010][1010];
int a[1010][1010],vis[1010][1010],c[1010][1010];
int dx[9]={0,0,1,1,1,-1,-1,-1},dy[9]={1,-1,0,1,-1,0,1,-1};
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,n)cin>>ch[i]+1;
		up(i,1,n)
		{
			up(j,1,m)if(ch[i][j]=='#')a[i][j]=1;
		}
		up(i,1,n)
		{
			up(j,1,m)
			{
				if(ch[i][j]=='.')
				{
					up(k,0,7)
					{
						vis[i+dx[k]][j+dy[k]]=1;
					}
				}
			}
		}
		up(i,2,n-1)
		{
			up(j,2,m-1)
			{
				if(vis[i][j]==0)
				{
					up(k,0,7)
					{
						c[i+dx[k]][j+dy[k]]=1;
					}
				}
			}
		}
		up(i,1,n)
		{
			up(j,1,m)
			{
				if(a[i][j]!=c[i][j])
				{
					puts("NO");
					return 0;
				}
			}
		}YES;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/