#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
int n;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
vector<int> gg[maxN];
int fenw[maxN];
int get(int r) {
    int ans = 0;
    while (r > 0) {
        ans = sum(ans, fenw[r]);
        r &= (r - 1);
    }
    return ans;
}
void upd(int v, int by) {
    while (v <= n) {
        fenw[v] = sum(fenw[v], by);
        v = (v | (v - 1)) + 1;
    }
}
int dp[maxN];
int up[maxN];
int cur_dp[maxN];
void solve() {
    cin >> n;
    vector<int> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t.emplace_back(a[i]);
    }
    sort(t.begin(), t.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin() + 1;
        assert(a[i] <= n);
    }
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        gg[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        gg[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) fenw[i] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = sum(1, get(a[i] - 1));
        upd(a[i], dp[i]);
    }
    for (int i = 1; i <= n; i++) {
        fenw[i] = 0;
    }
    for (int i = n; i >= 1; i--) {
        up[i] = sum(1, get(n - a[i]));
        upd(n + 1 - a[i], up[i]);
    }
    for (int i = 1; i <= n; i++) fenw[i] = 0;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] > lst) {
            vector<int> all;
            for (int z = lst; z < a[i]; z++) {
                for (int u : gg[z]) {
                    if (u < i) {
                        all.emplace_back(u);
                    }
                }
            }
            sort(all.begin(), all.end());

            cur_dp[i] = 1;
            upd(n + 1 - a[i], cur_dp[i]);
            for (int t = all.size() - 1; t >= 0; t--) {
                cur_dp[all[t]] = get(n - a[all[t]]);
                upd(n + 1 - a[all[t]], cur_dp[all[t]]);
                ans = sum(ans, mult(dp[all[t]], sub(up[all[t]], cur_dp[all[t]])));
            }
            upd(n + 1 - a[i], sub(0, cur_dp[i]));
            for (int t = all.size() - 1; t >= 0; t--) {
                upd(n + 1 - a[all[t]], sub(0, cur_dp[all[t]]));
            }
            lst = a[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}