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
int dp[(1<<20)+1][21];
const int mod=1e9+7;
int ans=0;
signed main()
{
	cin>>n;
	string s;
	cin>>s;
	up(i,0,(1<<n)-1)if(s[i]=='1')dp[i][0]=1;
	up(j,0,n-1)
	{
		up(i,0,(1<<n)-1)
		{
			dp[i][j+1]=dp[i][j]*2+dp[i^(1<<j)][j];
			dp[i][j+1]%=mod;
		}
	}
	up(i,0,(1<<n)-1)if(s[i]=='1')ans+=dp[i][n],ans%=mod;
	cout<<ans*3%mod;
}