#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
#define int long long

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 100;
int fact[N], fact1[N];
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
    return fact[n] * fact1[n - k] % mod * fact1[k] % mod;
}
signed main()
{
   // ifstream cin("rt.txt.txt");
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    fact1[N - 1] = power(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--)
    {
        fact1[i] = fact1[i + 1] * (i + 1) % mod;
    }
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int sum = 1;
        for(int p = 1; p <= n; p++)
        {
            if(1 + (p - 1) * k > n)
            {
                break;
            }
            sum += power(cnk(n, p), mod - 2) * cnk(n - (k - 1) * (p - 1), p) % mod;
            if(sum >= mod)
            {
                sum -= mod;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}