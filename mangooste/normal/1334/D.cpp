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

void solve() {
    ll n, L, R;
    cin >> n >> L >> R;
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (ll i = 1; i < n; i++)
        pref[i] = pref[i - 1] + 2LL * (n - i);
    pref[n] = pref[n - 1] + 1LL;
    ll block_num = 1;
    for (ll i = L; i <= R; i++) {
        while (pref[block_num] < i)
            block_num++;
        ll pos = i - pref[block_num - 1];
        if (block_num == n) {
            cout << 1 << ' ';
            continue;
        }
        if (pos % 2)
            cout << block_num << ' ';
        else
            cout << block_num + pos / 2 << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) 
        solve();
}