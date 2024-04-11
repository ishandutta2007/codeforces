#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n , s1[2010] , s2[2010] , s3[2010];
char c[2010];
LL fac[2010] , inv[2010] , dp[2010][2010] , ans;

LL fast_mod(LL x , LL y)
{
    LL ret = 1;
    x %= mod;
    while (y)
    {
        if (y&1) ret = (ret*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return ret;
}

void init(int x)
{
    fac[0] = 1;
    for (int i = 1 ; i <= x ; i++)
        fac[i] = (fac[i-1]*i)%mod;
    inv[x] = fast_mod(fac[x],mod-2);
    for (int i = x-1 ; i >= 0 ; i--)
        inv[i] = (inv[i+1]*(i+1))%mod;
}

LL C(int x , int y)
{
	if (x < y) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main()
{
	int i , j;
	cin >> c+1;
	n = strlen(c+1);
	init(n);
	for (i = 0 ; i <= n ; i++)
		for (j = i ; j >= 0 ; j--)
			dp[i][j] = (dp[i][j+1]+C(i,j))%mod;
	for (i = 1 ; i <= n ; i++)
	{
		s1[i] = s1[i-1];
		s2[i] = s2[i-1];
		s3[i] = s3[i-1];
		if (c[i] == '(') s1[i]++;
		else if (c[i] == ')') s2[i]++;
		else s3[i]++;
	}
	for (i = 1 ; i <= n ; i++)
		if (c[i] != ')')
			for (j = s1[i-1]+1 ; j <= min(s1[i-1]+s3[i-1]+1,s3[n]-s3[i]+s2[n]-s2[i]) ; j++)
				ans = (ans+C(s3[i-1],j-s1[i-1]-1)*dp[s3[n]-s3[i]][max(0,j-(s2[n]-s2[i]))]%mod)%mod;
	cout << ans << "\n";
	return 0;
}