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
int a[15];
int dp[(1<<14)+1];
int b1[20],b2[20];
int inv[2020020];
int t1,t2;
const int mod=1e9+7;
signed main()
{
	int T=1;
	inv[1]=1;
    inv[0]=1;
    up(i,2,2000000)
        inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	while(T--)
	{
		n=read();
		up(i,0,n-1)a[i]=read();
		int m=(1<<n)-1;
		up(i,1,m)
		{
			dp[i]=1;
			for(int j=(i-1)&i;j;j=(j-1)&i)
			{
				int k=i-j;
				t1=t2=0;
				up(p,0,n-1)
				{
					if(j&(1<<p))
					{
						b1[++t1]=p;
					}
					if(k&(1<<p))
					{
						b2[++t2]=p;
					}
				}
				int nw=dp[j];
				up(f1,1,t1)
				{
					up(f2,1,t2)
					{
						nw*=a[b1[f1]];nw%=mod;
						nw*=inv[a[b1[f1]]+a[b2[f2]]];nw%=mod;
					}
				}
				dp[i]+=mod,dp[i]-=nw,dp[i]%=mod;
			}
		}
		int sum=0;
		up(i,1,m)
		{
			t1=t2=0;
			up(p,0,n-1)
			{
				if(i&(1<<p))
				{
					b1[++t1]=p;
				}
				if((m^i)&(1<<p))
				{
					b2[++t2]=p;
				}
			}
			int nw=dp[i];
			up(f1,1,t1)
			{
				up(f2,1,t2)
				{
					nw*=a[b1[f1]];nw%=mod;
					nw*=inv[a[b1[f1]]+a[b2[f2]]];nw%=mod;
				}
			}
			nw*=t1;nw%=mod;
			sum+=nw;sum%=mod;
		}
		cout<<sum;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/