/*
qwq
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
const int maxn=(1<<18)+10;
int dp[maxn][111];
int b[20];
signed main()
{
	int T=1;
	while(T--)
	{
		string s;
		cin>>s;m=read();
	n=s.size();
		int nw=1;
		up(i,0,s.size()-1)
		{
			b[s[i]-'0']++;nw*=b[s[i]-'0'];s[i]-='0';
		}
		dp[0][0]=1;
		up(i,0,(1<<n)-1)
		{
			up(j,0,n-1)
			{
				if(i&(1<<j))continue;
				if(!s[j]&&!i)continue;
				up(t,0,m-1)
				{
					dp[i^(1<<j)][(t*10+s[j])%m]+=dp[i][t];
				}
			}
		}
		cout<<dp[(1<<n)-1][0]/nw;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/