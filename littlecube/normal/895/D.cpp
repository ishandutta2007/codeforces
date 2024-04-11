#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string a, b;
ll fac[1000005], rfac[1000005];

inline int fpow(ll n, ll b)
{
    if (n == 1)
        return b;
    if (n % 2)
        return fpow(n - 1, b) * b % MOD;
    ll h = fpow(n / 2, b);
    return h * h % MOD;
}

int solve(string &a, string &b)
{
    int cnt[26] = {0}, ans = 0;
    for (int i = 0; i < a.length(); i++)
        cnt[a[i] - 'a']++;
    for (int i = 0; i < a.length(); i++)
    {
        int old = -1;
        ll tmp = fac[a.length() - 1 - i];
        for (int j = 0; j < 26; j++)
            tmp = (tmp * rfac[cnt[j]]) % MOD;
        for (int j = 0; j < b[i] - 'a'; j++)
            if (cnt[j])
            {
                if (old >= 0)
                    cnt[old]++;
                cnt[j]--, old = j;
                ans = (ans + (((tmp * fac[cnt[j] + 1]) % MOD) * rfac[cnt[j]] % MOD)) % MOD;
            }
        if (cnt[b[i] - 'a'])
        {
            cnt[b[i] - 'a']--;
            if (old >= 0)
                cnt[old]++;
        }
        else if (b[i] - 'a' > old)
            return ans;
    }
    return ans;
}

signed main()
{
    fast;
    fac[0] = 1, rfac[0] = 1;
    fac[1] = 1, rfac[1] = 1;
    for (ll i = 2; i <= 1000003; i++)
        fac[i] = (fac[i - 1] * i) % MOD, rfac[i] = fpow(MOD - 2, fac[i]);
    cin >> a >> b;
    cout << (solve(a, b) - solve(a, a) - 1 + MOD) % MOD << '\n';
}