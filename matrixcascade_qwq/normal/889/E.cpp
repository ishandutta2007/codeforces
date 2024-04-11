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
#define int long long
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
int a[202020],dp[202020];
signed main()
{
	n=read();
	down(i,n,1)a[i]=read();
	a[0]=1;
	down(i,n-1,1)a[i]=min(a[i],a[i+1]);
	up(i,1,n)
	{
		int nw;
		for(int j=a[i],p=0;j>=1;j%=a[nw])
		{
			nw=lower_bound(a+1,a+n+1,j)-a-1;
			dp[i]=max(dp[i],dp[nw]+(n-nw)*(j-j%a[nw]-a[nw])+p);
			p+=(n-nw)*(j-j%a[nw]);
		}
	}
	cout<<dp[n];
}