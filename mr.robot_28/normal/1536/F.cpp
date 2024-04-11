#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 1;
const int mod = 1e9 + 7;
int fact[N], ifact[N];
int cnk(int n, int k)
{
    if(n < k)
    {
        return 0;
    }
    return fact[n] * ifact[n - k] % mod * ifact[k] % mod;
}
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t = power(a, b/ 2);
        return t * t % mod;
    }
    return a * power(a, b - 1) % mod;
}
signed main()
{
   // ifstream cin("rt.txt.txt");
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int n;
    cin >> n;
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    ifact[N - 1] = power(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    }
    int ans = 0;
    for(int moves = 2; moves <= n; moves += 2)
    {
        int coeff = cnk(moves, n - moves);
//        cout << moves << " " << n - moves << " ";
  //      cout << coeff << " " << fact[moves - 1] << "\n";
        ans = (ans + coeff * fact[moves - 1]) % mod;
    }
    cout << ans * 2 * n % mod;
    return 0;
}