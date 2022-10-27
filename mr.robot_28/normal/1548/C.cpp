#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e6;
const int mod = 1e9 + 7;
int fact[N + 1];
int fact1[N + 1];
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
int cnk(int n, int k)
{
    return fact[n] * fact1[k] % mod *fact1[n - k] % mod;
}
int dp[3 * N][3];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    fact[0] = 1;
    for(int i = 1; i <= 3 * n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    fact1[3 * n] = power(fact[n * 3], mod - 2);
    for(int i = n * 3 - 1; i >= 0; i--)
    {
        fact1[i] = fact1[i + 1] * (i + 1) % mod;
    }
    int inv3 = power(3, mod - 2);
    dp[0][0] = dp[0][1] = dp[0][2] = n;
    for(int x = 1; x < n * 3; x++)
    {
        int a = cnk(3 * n, x + 1);
        int b = dp[x - 1][0];
        int c = dp[x - 1][1];
        dp[x][0] = (3 * mod + a - 2 * b - c) % mod * inv3 % mod;
        dp[x][1] = dp[x][0] + b;
        dp[x][2] = dp[x][1] + c;
        dp[x][1] %= mod;
        dp[x][2] %= mod;
    }
    dp[n * 3][0] = dp[n * 3][1] = dp[3 * n][2] = 0;
    while(q--)
    {
        int x;
        cin >> x;
      //  cout << cnk(3 * n, x) << " ";
        cout << (dp[x][0] + cnk(3 * n, x)) % mod << "\n";
    }
    return 0;
}