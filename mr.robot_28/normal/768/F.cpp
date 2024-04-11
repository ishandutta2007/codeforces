#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int fact[N], fact1[N], inv[N];
void pre_calc()
{
    fact[0] = fact1[0] = inv[1] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 2; i < N; i++)
    {
        inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
    }
    for(int i = 1; i < N; i++)
    {
        fact1[i] = 1LL * fact1[i - 1] * inv[i] %mod;
    }
}
int C(int n,int k)
{
    if(k < 0 || n < k)
    {
        return 0;
    }
    return 1LL * fact[n] * fact1[n - k] % mod * fact1[k] % mod;
}
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b % 2 == 0)
    {
        int t = power(a, b / 2);
        return 1LL * t * t % mod;
    }
    else
    {
        return 1LL * a * power(a, b - 1) % mod;
    }
}
int funct(int f, int w, int h)
{
    if(w == 0)
    {
        return 1;
    }
    int ans = 0;
    for(int u = 1; u <= f + 1 && (h == 0 || u <= (w - 1) / h); u++)
    {
        ans += 1LL * C(f + 1, u) * C(w - h * u - 1, u - 1) % mod;
        ans %= mod;
    }
    return ans;
}
signed main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    pre_calc();
    int f, w, h;
    cin >> f >> w >> h;
    int a = funct(f, w, h);
    int b = C(f + w, w);
    cout << 1LL * a * power(b, mod - 2) % mod;
    return 0;
}