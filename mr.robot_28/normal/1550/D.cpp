#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5;
int fact[N], fact1[N];
int cnk(int n, int k)
{
    return fact[n] * fact1[k] % mod * fact1[n - k] % mod;
}
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
signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
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
        int n, l, r;
        cin >> n >> l >> r;
        int cnt1 = 0, cnt2 = 0;
        int ans = 0;
        int it1 = 1, it2 = n;
        int k1 = min(1 - l, r - n);
        ans = k1 * cnk(n, n / 2) % mod;
        if(n % 2 != 0)
        {
            ans = ans * 2 % mod;
        }
        for(int i = k1 + 1; i <= n + k1; i++)
        {
            while(it1 <= n && it1 - i < l)
            {
                it1++;
                cnt1++;
            }
            while(it2 > 0 && it2 + i > r)
            {
                it2--;
                cnt2++;
            }
            if(n == 4)
            {
        //        cout << i << " " << cnt1 << " " << cnt2 << "\n";
            }
            if(cnt1 + cnt2 > n)
            {
                break;
            }
            if(min(cnt1, cnt2) > (n / 2) || max(cnt1, cnt2) > (n + 1) / 2)
            {
                break;
            }
            int ost = n - cnt1 - cnt2;
            if(cnt1 <= (n + 1) / 2 && cnt2 <= (n / 2))
            {
                int ost1 = (n + 1) / 2 - cnt1;
                ans = (ans + cnk(ost, ost1)) % mod;
            }
            if((cnt1 > (n + 1) / 2 || cnt2 > (n / 2) || n % 2 != 0) && cnt1 <= (n / 2) && cnt2 <= (n + 1) / 2)
            {
                int ost1 = (n / 2) - cnt1;
                ans = (ans + cnk(ost, ost1)) % mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}