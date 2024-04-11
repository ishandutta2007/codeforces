/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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
// using namespace __gnu_pbds;

ll n, q, A[300005], B[300005], mod, fib[300005], unfib[300005], sum;

signed main()
{
    fast;
    cin >> n >> q >> mod;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];
    for (int i = 1; i <= n; i++)
        A[i] = (A[i] - B[i] + mod) % mod;
    for (int i = n; i >= 1; i--)
    {
        if (i >= 2)
            A[i] = (A[i] - A[i - 1] - A[i - 2] + 2 * mod) % mod;
        sum += A[i];
    }
    fib[1] = fib[2] = (1 % mod);
    for (int i = 3; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    for (int i = 1; i <= n; i++)
        unfib[i] = (mod - fib[i]) % mod;
    for (int i = 1; i <= q; i++)
    {
        char t;
        int l, r, a, b, c;
        cin >> t >> l >> r;
        a = (t == 'A' ? fib[1] : unfib[1]);
        b = (t == 'A' ? unfib[r - l + 2] : fib[r - l + 2]);
        c = (t == 'A' ? unfib[r - l + 1] : fib[r - l + 1]);
        sum -= A[l] + A[r + 1] + A[r + 2];
        A[l] = (A[l] + a) % mod;
        if (r + 1 <= n)
            A[r + 1] = (A[r + 1] + b) % mod;
        if (r + 2 <= n)
            A[r + 2] = (A[r + 2] + c) % mod;
        sum += A[l] + A[r + 1] + A[r + 2];

        if (sum == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}