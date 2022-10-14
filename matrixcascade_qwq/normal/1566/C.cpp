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
int c1[101010],c2[101010];
int dp[101010][2];
int f(int x,int y)
{
	int nw=0;
	if(x>y)swap(x,y);
	if(nw==x)++nw;
	if(nw==y)++nw;
	return nw;
}
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		up(i,1,n)scanf("%1lld",&c1[i]);
		up(i,1,n)scanf("%1lld",&c2[i]);
		up(i,1,n)c1[i]+=c2[i];
		int nw=0;c1[n+1]=3;
		up(i,1,n)
		{
			if(c1[i]==1)nw+=2;
		}
		
		for(int i=1;i<=n;)
		{
			if(c1[i]==0)
			{
				if(c1[i+1]==2)
				{
					nw+=2;
					i++;i++;
				}
				else
				{
					nw++;
					i++;
				}
			}
			else if(c1[i]==2)
			{
				if(c1[i+1]==0)
				{
					nw+=2;
					i++;i++;
				}
				else
				{
					i++;
				}
			}
			else ++i;
		}
		cout<<nw<<'\n';
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/