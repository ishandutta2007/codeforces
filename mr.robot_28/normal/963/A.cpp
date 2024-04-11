#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
const int mod = 1e9 + 9;
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
//    ios::sync_with_stdio(0);
  //  cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int a1 = power(a, k);
    int b1 = power(b, k);
    a1 = power(a1, mod - 2);
    int sum = 0;
    string s;
    cin >> s;
    for(int i = 0; i < k; i++)
    {
        int val = power(a, n - i) * power(b, i) % mod;
        if(s[i] == '-')
        {
            val = -val;
        }
        sum += val;
        if(sum < 0)
        {
            sum += mod;
        }
        if(sum >= mod)
        {
            sum -= mod;
        }
    }
    int up = a1 * b1 % mod;
    if(up == 1)
    {
        cout << (1LL * sum * (n + 1) / k) % mod;
        return 0;
    }
    int up1 = power((1 - up + mod) %mod, mod - 2);
    int up2 = power(up, (n + 1) / k);
    up2 = (-up2 + 1 + mod) % mod;
    int ans = up2 * up1 % mod *sum % mod;
    cout << ans;
    return 0;
}