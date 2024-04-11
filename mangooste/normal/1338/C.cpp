#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

ll get1(ll n) {
    if (n == 1)
        return 1;
    for (ll i = 1;; i++) {
        ll cur_cnt = 3LL * (1LL << 2LL * i);
        ll pref = (1LL << 2LL * i) - 1;
        if (n - pref > cur_cnt)
            continue;
        n -= pref;
        n /= 3LL;
        n++;
        return pref + n;
    }
}

ll get2(ll n, ll L, ll R, ll cur_power) {
    if (L == R)
        return L;
    ll block_len = (1LL << cur_power - 2LL);
    if (n <= block_len)
        return get2(n, L, L + block_len - 1, cur_power - 2);
    n -= block_len;
    if (n <= block_len)
        return get2(n, L + 2 * block_len, L + 3 * block_len - 1, cur_power - 2);
    n -= block_len;
    if (n <= block_len)
        return get2(n, L + 3 * block_len, L + 4 * block_len - 1, cur_power - 2);
    n -= block_len;
    return get2(n, L + block_len, L + 2 * block_len - 1, cur_power - 2);
}

ll get2(ll n) {
    if (n == 2)
        return 2;
    for (ll i = 1;; i++) {
        ll cur_cnt = 3LL * (1LL << 2LL * i);
        ll pref = (1LL << 2LL * i) - 1;
        if (n - pref > cur_cnt)
            continue;
        ll L = (1LL << 2LL * i + 1LL);
        ll R = L + (1LL << 2LL * i) - 1;
        n -= pref;
        n /= 3LL;
        n++;
        return get2(n, L, R, 2LL * i);
    }
}

void solve() {
    ll n;
    cin >> n;
    if (n % 3 == 1)
        cout << get1(n) << '\n';
    else if (n % 3 == 2)
        cout << get2(n) << '\n';
    else
        cout << (get1(n - 2) ^ get2(n - 1)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // vector<char> used(10000, 0);
    // for (int i = 0; i < 1000; i++) {
    //     for (int j = 1; j < 10000; j++) {
    //         if (used[j])
    //             continue;
    //         bool fnd = false;
    //         for (int k = 1; k < 10000; k++) {
    //             int z = (j ^ k);
    //             if (used[k] || used[z])
    //                 continue;
    //             if (z > 0 && j != k && j != z && k != z) {
    //                 used[j] = used[k] = used[z] = 1;
    //                 fnd = true;
    //                 cout << j << ' ' << k << ' ' << z << '\n';
    //                 break;
    //             }
    //         }
    //         if (fnd)
    //             break;
    //     }
    // }
    int t;
    cin >> t;
    while (t--)
        solve();
}