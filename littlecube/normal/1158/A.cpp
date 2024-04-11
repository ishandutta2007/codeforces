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
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

int N, M;
ll ans, b[100005], g[100005];

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> b[i];
    for (int j = 1; j <= M; j++)
        cin >> g[j];
    sort(b + 1, b + 1 + N);
    sort(g + 1, g + 1 + M);
    if (b[N] > g[1])
        cout << -1;
    else
    {
        if (b[N] == g[1])
        {
            for (int i = 1; i <= N - 1; i++)
                ans += b[i] * M;
            for (int i = 1; i <= M; i++)
                ans += g[i];
        }
        else if (N >= 2 && M >= 2)
        {
            for (int i = 1; i <= N - 1; i++)
                ans += b[i] * M;
            for (int i = 1; i <= M; i++)
                ans += g[i];
            ans += b[N] - b[N - 1];
        }
        else
            ans = -1;
        cout << ans << '\n';
    }
}