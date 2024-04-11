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
const int mod=1e9+7,maxn=1e6+20;
int f[10],b[maxn];
int dp1[maxn],dp2[maxn],dp3[maxn],v[maxn];
signed main()
{
	f[0]=1;up(i,1,9)f[i]=f[i-1]*10;
	int T=1;
	while(T--)
	{
		n=read();b[0]=1;up(i,1,n)b[i]=(b[i-1]*2)%mod;
		up(i,1,n)
		{
			int x=read();
			dp1[x]++;
			dp2[x]+=x;
			dp3[x]+=x*x;
			dp1[x]%=mod;
			dp2[x]%=mod;
			dp3[x]%=mod;
		}
		up(j,0,5)
		{
			pu(i,999999,0)
			{
				if((i/f[j])%10!=9)
				{
					dp1[i]+=dp1[i+f[j]];
					dp2[i]+=dp2[i+f[j]];
					dp3[i]+=dp3[i+f[j]];
					dp1[i]%=mod;
					dp2[i]%=mod;
					dp3[i]%=mod;
				}
			}
		}
		up(i,0,999999)
		{
			int nw=(dp2[i]*dp2[i]%mod-dp3[i]+mod+mod+mod)%mod*(mod/2+1)%mod;
			if(dp1[i])v[i]=b[dp1[i]-1]*(dp3[i]+nw)%mod;
		}
		up(j,0,5)
		{
			up(i,0,999999)
			{
				if((i/f[j])%10!=9)
				{
					v[i]-=v[i+f[j]];
					v[i]+=mod;
					v[i]%=mod;
				}
			}
		}
		int ans=0;
		up(i,0,999999)
		{
			ans^=(v[i]*i);
		}
		cout<<ans;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/