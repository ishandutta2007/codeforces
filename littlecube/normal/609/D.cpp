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
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
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

ll N, M, K, s, ai, amin, bi, bmin;
pll a[200005], b[200005];
vector<pll> A = {{0, 0}}, B = {{0, 0}};

void bs(int L, int R)
{
    if (L == R)
    {
        if (L == N + 1)
            cout << -1;
        else
        {
            cout << L << '\n';
            for (int i = max(0LL, (ll)(K - B.size() + 1)); i <= min(K, (ll)A.size() - 1); i++)
                if (A[i].F * a[L].F + B[K - i].F * b[L].F <= s)
                {
                    for (int j = 1; j <= i; j++)
                        cout << A[j].S << " " << a[L].S << '\n';
                    for (int j = 1; j <= K - i; j++)
                        cout << B[j].S << " " << b[L].S << '\n';
                    return;
                }
        }
        return;
    }
    int mid = (L + R) / 2;
    for (int i = max(0LL, (ll)(K - B.size() + 1)); i <= min(K, (ll)A.size() - 1); i++)
        if (A[i].F * a[mid].F + B[K - i].F * b[mid].F <= s)
        {
            bs(L, mid);
            return;
        }
    bs(mid + 1, R);
}

signed main()
{
    fast;
    cin >> N >> M >> K >> s;
    for (int i = 1; i <= N; i++)
        cin >> a[i].F, a[i].S = i;
    for (int i = 1; i <= N; i++)
        cin >> b[i].F, b[i].S = i;
    for (int i = 1; i <= M; i++)
    {
        ll t, c;
        cin >> t >> c;
        if (t == 1)
            A.pb(make_pair(c, i));
        else
            B.pb(make_pair(c, i));
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 2; i <= N; i++)
        a[i] = min(a[i - 1], a[i]);
    for (int i = 2; i <= N; i++)
        b[i] = min(b[i - 1], b[i]);

    for (int i = 1; i < A.size(); i++)
        A[i].F += A[i - 1].F;
    for (int i = 1; i < B.size(); i++)
        B[i].F += B[i - 1].F;

    bs(1, N + 1);
}