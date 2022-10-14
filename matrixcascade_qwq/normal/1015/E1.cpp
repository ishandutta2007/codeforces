/*
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
And in that light,I find deliverance.
*/

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
char c[1010][1010];
struct node
{
	int x,y,l;
};
node b[1010][1010];
bool vis[1010][1010];
bool u[1010][1010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,n)scanf("%s",c[i]+1);
		up(i,1,n)
		{
			up(j,1,m)
			{
				if(c[i][j]=='.')continue;
				int x1=i,x2=i,x3=j,x4=j;
				int nw=0;
				while(1)
				{
					if(c[x1][j]!='*'||c[x2][j]!='*'||c[i][x3]!='*'||c[i][x4]!='*')break;
					nw++;
					x1++;x2--;x3++;x4--;
				}
				nw--;
				
				if(nw==0)continue;
				x1=i,x2=i,x3=j,x4=j;
				b[i][j]=(node){i,j,nw};
				u[i][j]=1;
				while(1)
				{
					if(c[x1][j]!='*'||c[x2][j]!='*'||c[i][x3]!='*'||c[i][x4]!='*')break;
					vis[x1][j]=vis[x2][j]=vis[i][x3]=vis[i][x4]=1;
					x1++;x2--;x3++;x4--;
				}
			}
		}
		up(i,1,n)
		{
			up(j,1,m)
			{
				if(c[i][j]=='*'&&!vis[i][j])
				{
					puts("-1");return 0;
				}
			}
		}
		int ww=0;
		up(i,1,n)
		{
			up(j,1,m)
			{
				if(u[i][j])++ww;
			}
		}
		cout<<ww<<'\n'; 
		up(i,1,n)
		{
			up(j,1,m)
			{
				if(u[i][j])
				{
					printf("%d %d %d\n",b[i][j].x,b[i][j].y,b[i][j].l);
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