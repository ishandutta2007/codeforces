#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

const ll MOD = 998244353LL;

ll get_even(ll L, ll R) {
    if (R == L)
        return (L + 1 & 1);
    ll ans = 0;
    if (L & 1)
        L++;
    if (!(R & 1))
        R--, ans++;
    ans += (R - L + 1) / 2;
    return ans;
}

ll get_odd(ll L, ll R) {
    if (R == L)
        return (L & 1);
    ll ans = 0;
    if (L & 1)
        L++, ans++;
    if (!(R & 1))
        R--;
    ans += (R - L + 1) / 2;
    return ans;
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

void add(ll& a, ll b) {
    a += b;
    while (a >= MOD)
        a -= MOD;
}

ll bin_pow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b & 1)
        return mult(bin_pow(a, b - 1), a);
    ll mid = bin_pow(a, b / 2);
    return mult(mid, mid);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll n, m, L, R;
    cin >> n >> m >> L >> R;

    ll even = get_even(L, R), odd = get_odd(L, R);
    ll N = n * m;

    ll all_can = bin_pow(R - L + 1, N);

    if (n * m & 1)
        return cout << all_can << '\n', 0;

    if (odd == even)
        return cout << (MOD + all_can - mult(bin_pow(odd, N), bin_pow(2, N - 1))) % MOD << '\n', 0;

    cout << (MOD + (all_can + 1) * bin_pow(2, MOD - 2)) % MOD << '\n', 0;
}