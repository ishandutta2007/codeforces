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
char c[101010];
pair<int,int> q[101010];
int tot;
int ff[101010],g[101010],q1,q2;
#define mkp make_pair
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		scanf("%s",c+1);
		int ans=1010101001ll;
		up(i,'a','z')
		{
			tot=0;
			int pw=0;
			up(j,1,n)
			{
				if(c[j]!=i)
				{
					q[++tot]=mkp(j,c[j]);
					pw=0;
				}
				else ++pw;
			}
			int f=1;
			up(j,1,tot/2)
			{
				if(q[j].second!=q[tot-j+1].second)
				{
					f=0;
					break;
				}
			}
			if(f==0)continue;
			if(tot&1)
			{
			
				q1=0;q2=0;
				int w=0;
				up(j,1,q[tot/2+1].first)
				{
					if(c[j]!=i)
					{
						ff[++q1]=w;
						w=0;
					}
					else
					{
						++w;
					}
				}
				w=0;
				pu(j,n,q[tot/2+1].first)
				{
					if(c[j]!=i)
					{
						g[++q2]=w;
						w=0;
					}
					else
					{
						++w;
					}
				}
				int sum=0;
				up(j,1,q1)
				{
					sum+=abs(g[j]-ff[j]);
				}
				ans=min(ans,sum);
				
			}
			else
			{
				q1=0;q2=0;
				int w=0;
				up(j,1,q[tot/2].first)
				{
					if(c[j]!=i)
					{
						ff[++q1]=w;
						w=0;
					}
					else
					{
						++w;
					}
				}
				w=0;
				pu(j,n,q[tot/2+1].first)
				{
					if(c[j]!=i)
					{
						g[++q2]=w;
						w=0;
					}
					else
					{
						++w;
					}
				}
				int sum=0;
				up(j,1,q1)
				{
					sum+=abs(g[j]-ff[j]);
				}
				ans=min(ans,sum);
			}
		}
		if(ans>n)ans=-1;
		cout<<ans<<'\n';
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/