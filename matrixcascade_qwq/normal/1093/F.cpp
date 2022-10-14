//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
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
int len;
int a[101010];
const int mod=998244353;
int pos[190];
int sum[101010][102];
int dp1[101010][101],dp2[101010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),k=read(),len=read();
		up(i,1,n)a[i]=read();
		up(i,1,n)
		{
			if(a[i]==-1)sum[i][0]++;
			else sum[i][a[i]]++;
		}
		up(j,0,k)up(i,1,n)sum[i][j]+=sum[i-1][j];
		dp2[0]=1;
		up(i,1,n)
		{
			if(a[i]!=-1)
			{
				if(i<len)
				{
					dp1[i][a[i]]=dp2[i-1];
				}
				else if(sum[i-1][0]-sum[i-len][0]+sum[i-1][a[i]]-sum[i-len][a[i]]==len-1)
				{
					dp1[i][a[i]]=(dp2[i-1]-dp2[i-len]+dp1[i-len][a[i]]+mod)%mod;
				}
				else dp1[i][a[i]]=dp2[i-1];
			}
			//i-1-i+len-1
			else
			{
				up(j,1,k)
				{
					if(i<len)
					{
						dp1[i][j]=dp2[i-1];
					}
					else if(sum[i-1][0]-sum[i-len][0]+sum[i-1][j]-sum[i-len][j]==len-1)
					{
						dp1[i][j]=(dp2[i-1]-dp2[i-len]+dp1[i-len][j]+mod)%mod;
					}
					else dp1[i][j]=dp2[i-1];
				}
			}
			up(j,1,k)dp2[i]+=dp1[i][j],dp2[i]%=mod;
		}
		cout<<dp2[n];
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/