#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    vector<ll> tree(4 * n);
    Fun<void(int, int, int)> build = [&](int v, int vl, int vr) {
        if (vr - vl == 1) {
            tree[v] = a[vl];
        } else {
            int vm = (vl + vr) / 2;
            build(2 * v, vl, vm);
            build(2 * v + 1, vm, vr);
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        }
    };
    build(1, 0, n);
    const ll INF = 1e15;
    Fun<ll(int, int, int, int, int)> get = [&](int v, int vl, int vr, int L, int R) {
        if (R <= vl || vr <= L) {
            return INF;
        } else if (L <= vl && vr <= R) {
            return tree[v];
        } else {
            int vm = (vl + vr) / 2;
            return min(get(2 * v, vl, vm, L, R), get(2 * v + 1, vm, vr, L, R));
        }
    };
    vector<ll> min_sum(n);
    for (int i = c - 1; i < n; i++) {
        min_sum[i] = get(1, 0, n, i - (c - 1), i + 1);
    }
    vector<array<ll, 2>> dp(n + 1, {-INF, -INF});
    dp[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][0], dp[i][1]);
        if (i >= c - 1) {
            dp[i + 1][1] = max(dp[i + 1 - c][0], dp[i + 1 - c][1]) + min_sum[i];
        }
    }
    ll sum = accumulate(all(a), 0ll);
    cout << sum - max(dp[n][0], dp[n][1]) << '\n';
}