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
int a[1010][6];
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)
		{
			up(j,1,5)
			{
				scanf("%d",&a[i][j]);
			}
		}
		up(i,1,5)
		{
			up(j,1,5)
			{
				if(i==j)continue;
				vector<int>v1,v2,v3;
				up(k,1,n)
				{
					if(a[k][i]&&a[k][j])v3.emplace_back(k);
					else if(a[k][i])v1.emplace_back(k);
					else if(a[k][j])v2.emplace_back(k); 
				}
				if(v1.size()+v2.size()+v3.size()!=n)
				{
					continue;
				}
				int x=v2.size(),y=v1.size();
				if(x>y)swap(x,y);
				if(x+v3.size()>=y)
				{
					YES;
					error;
				}
			}
		}
		NO;
		def;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/