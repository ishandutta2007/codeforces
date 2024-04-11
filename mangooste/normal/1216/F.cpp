#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const ll INF = 1e12;
vector<ll> tree;

void upd(int v, int vl, int vr, int pos, ll new_val) {
    if (pos < vl || vr <= pos) {
        return;
    } else if (vr - vl == 1) {
        tree[v] = new_val;
    } else {
        int vm = (vl + vr) / 2;
        upd(2 * v, vl, vm, pos, new_val);
        upd(2 * v + 1, vm, vr, pos, new_val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

ll get_min(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L) {
        return INF;
    } else if (L <= vl && vr <= R) {
        return tree[v];
    } else {
        int vm = (vl + vr) / 2;
        return min(get_min(2 * v, vl, vm, L, R), get_min(2 * v + 1, vm, vr, L, R));
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = i + 1;
    }
    vector<array<ll, 2>> dp(n);
    dp[0][0] = cost[0];
    if (s[0] == '0') {
        dp[0][1] = INF;
    } else {
        dp[0][1] = cost[0];
    }
    tree.resize(4 * n, INF);
    upd(1, 0, n, 0, dp[0][1]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + cost[i], get_min(1, 0, n, max(0, i - k), i));
        if (s[i] == '0') {
            dp[i][1] = INF;
        } else {
            if (i - k <= 0) {
                dp[i][1] = cost[i];
            } else {
                dp[i][1] = min(get_min(1, 0, n, max(0, i - k - 1 - k), i), dp[i - k - 1][0]) + cost[i];
            }
        }
        upd(1, 0, n, i, dp[i][1]);
    }
    cout << min(dp.back()[0], dp.back()[1]) << '\n';
}