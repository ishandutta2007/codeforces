//Author : MatrixCascade

#pragma GCC optimize(3)
#pragma GCC target("sse2")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
const int maxn=1e5+10;
int a[maxn];
ll dp[maxn];
signed main()
{
	n=read();
	up(i,1,n)dp[i]=-1e17;
	up(i,1,n)
	{
		int x=read();
		down(j,i,1)
		{
			if(dp[j]<dp[j-1]+1ll*j*x)dp[j]=dp[j-1]+1ll*j*x;
			else break;
		}
	}
	ll ans=0;
	up(i,1,n)ans=max(ans,dp[i]);
	cout<<ans;
}