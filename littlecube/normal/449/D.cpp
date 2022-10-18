/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;
// 7
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll mxA = 1048575, mxlgA = 20;
ll N, arr[1000005], dp[mxA + 1], co[mxA + 1], ans;

ll fastpow(ll b, ll p)
{
    ll a = 1;
    while (p > 0)
    {
        if (p & 1)
            a = a * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return a;
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[mxA - arr[i]]++;
    }
    for (int j = 0; j < 20; j++)
        for (int i = 0; i <= mxA; i++)

            if (i & (1 << j))
                dp[i] += dp[i ^ (1 << j)];

    for (int i = 0; i <= mxA; i++)
        dp[i] = (fastpow(2, dp[i]) - 1 + MOD) % MOD;

    co[0] = 1;

    for (int j = 0; j < 20; j++)
        for (int i = 0; i <= mxA; i++)
            if (i & (1 << j))
                dp[i] = (dp[i] - dp[i ^ (1 << j)] + MOD) % MOD;

    cout << dp[mxA] << '\n';
}