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

int N, K, arr[35005], dp[55][35005], seg[140005], lazy[140005], mdf[35005], cnt[35005];

int query(int idx, int L, int R, int a, int b)
{
    if (a <= L && R <= b)
        return lazy[idx] + seg[idx];
    if (b < L || R < a)
        return 0;
    seg[idx] = lazy[idx] + seg[idx];
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
    int mid = (L + R) / 2;

    return max(query(idx * 2, L, mid, a, b), query(idx * 2 + 1, mid + 1, R, a, b));
}

void modify(int idx, int L, int R, int a, int b, int val)
{
    if (a <= L && R <= b)
    {
        lazy[idx] += val;
        return;
    }
    if (b < L || R < a)
        return;
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
    int mid = (L + R) / 2;
    modify(idx * 2, L, mid, a, b, val);
    modify(idx * 2 + 1, mid + 1, R, a, b, val);
    seg[idx] = max(lazy[idx * 2] + seg[idx * 2], lazy[idx * 2 + 1] + seg[idx * 2 + 1]);
}

signed main()
{
    //fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        mdf[i] = cnt[arr[i]];
        cnt[arr[i]] = i;
    }
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= 4 * N; j++)
            seg[j] = (lazy[j] = 0);

        for (int j = 0; j < N; j++)
            modify(1, 0, N, j + 1, j + 1, dp[i - 1][j]);

        for (int j = 1; j <= N; j++)
        {
            modify(1, 0, N, mdf[j] + 1, j, 1);
            dp[i][j] = query(1, 0, N, 0, j);
        }
    }
    cout << dp[K][N] << '\n';
}