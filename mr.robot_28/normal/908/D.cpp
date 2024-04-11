#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
const int mod = 1e9 + 7;
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b % 2 == 1)
    {
        return a * power(a, b - 1) % mod;
    }
    int t = power(a, b / 2);
    return t * t % mod;
}
int dp[1005][1005];
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, pa, pb;
	cin >> k >> pa >> pb;
	int p1 = pa * power(pa + pb, mod - 2) % mod;
	int p2 = pb * power(pa + pb, mod - 2) % mod;
//	cout << p1 << " " << p2 << "\n";
	dp[1][0] = 1;
	int ans = 0;
	for(int i = 1; i < 1005; i++)
    {
        for(int j = 0; j < 1005; j++)
        {
            if(dp[i][j])
            {
                if(i + j >= k)
                {
              //      cout << i << " " << j << " " << dp[i][j] <<  "\n";
     //           cout << p1 * power((1 - p1 + mod) % mod, 2 * (mod - 2)) % mod << "\n";
                ans += dp[i][j] * p2 % mod * ((i + j) * power((1 - p1 + mod) % mod, mod - 2) % mod + p1 * power((1 - p1 + mod) % mod, 2 * (mod - 2)) % mod) % mod;
                if(ans >= mod)
                {
                    ans -= mod;
                }
                }
                else
                {
                    dp[i + 1][j] += dp[i][j] * p1 % mod;
                    if(dp[i + 1][j] >= mod)
                    {
                        dp[i + 1][j]-= mod;
                    }
                    dp[i][j + i] += dp[i][j] * p2 % mod;
                    if(dp[i][j + i] >= mod)
                    {
                        dp[i][j + i] -= mod;
                    }
                }
            }
        }
    }
    cout << ans;
	return 0;
}