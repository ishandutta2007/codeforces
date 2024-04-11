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
ll a[100005], b[100005], ans;

signed main()
{
    fast;
    cin >> N >> M;
    M += 2;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    b[1] = -1e10, b[M] = 1e10;
    for (int i = 2; i < M; i++)
        cin >> b[i];
    int idx = 1;
    for (int i = 1; i <= N; i++)
    {
        while (b[idx + 1] <= a[i])
            idx++;
        ans = max(ans, min(b[idx + 1] - a[i], a[i] - b[idx]));
    }
    cout << ans << '\n';
}