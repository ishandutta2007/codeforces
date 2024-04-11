#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 100;
int fact[N+ 1], ifact[N + 1], d[N + 1][N + 1], ans[N + 1];
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t = power(a, b / 2);
        return t * t % mod;
    }
    return a * power(a, b - 1) % mod;
}
signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    d[0][0] = fact[0] = ifact[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    ifact[N] = power(fact[N], mod - 2);
    for(int i = N - 1; i >= 0; i--)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            d[i][j] = (d[i - 1][j - 1] * (i - j + 1) + j * d[i - 1][j]) % mod;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans[i] = (ans[i] + d[j][i] * ifact[j]) % mod;
        }
    }
    for(int i =1; i <= n; i++)
    {
        cout << ans[i] * fact[n] % mod << " ";
    }
    return 0;
}