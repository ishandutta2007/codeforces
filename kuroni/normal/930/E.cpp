#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int MOD = 1E9 + 7;
 
int k, n, m, l, r;
long long ans = 1, g[2];
deque<pair<int, long long>> f[2];
map<int, pair<int, int>> ma;
 
long long pw(long long u, int p) {
    long long ret = 1;
    for (int i = __lg(p); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (p >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n >> m;
    ma[1] = ma[k + 1] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        if (ma[l].fi == 0 || ma[l].fi > r + 1) {
            ma[l].fi = r + 1;
        }
        if (ma.count(r + 1) == 0) {
            ma[r + 1] = {0, 0};
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        if (ma[l].se == 0 || ma[l].se > r + 1) {
            ma[l].se = r + 1;
        }
        if (ma.count(r + 1) == 0) {
            ma[r + 1] = {0, 0};
        }
    }
    for (auto it = ma.begin(); it != ma.end(); it = next(it)) {
        int pos = it->fi;
        pair<int, int> cur = it->se;
        while (!f[0].empty() && f[0].front().fi <= pos) {
            (g[0] -= f[0].front().se) %= MOD;
            f[0].pop_front();
        }
        while (!f[1].empty() && f[1].front().fi <= pos) {
            (g[1] -= f[1].front().se) %= MOD;
            f[1].pop_front();
        }
        if (pos == k + 1) {
            break;
        }
        long long zer = (ans + g[0] + g[1]) * (pw(2, next(it)->fi - pos) - 2) % MOD;
        long long fir = (ans + g[1]) % MOD;
        long long sec = (ans + g[0]) % MOD;
        ans = zer;
        if (cur.fi == 0) {
            (ans += fir) %= MOD;
        } else {
            (g[0] += fir) %= MOD;
            while (!f[0].empty() && f[0].back().fi >= cur.fi) {
                (fir += f[0].back().se) %= MOD;
                f[0].pop_back();
            }
            f[0].push_back({cur.fi, fir});
        }
        if (cur.se == 0) {
            (ans += sec) %= MOD;
        } else {
            (g[1] += sec) %= MOD;
            while (!f[1].empty() && f[1].back().fi >= cur.se) {
                (sec += f[1].back().se) %= MOD;
                f[1].pop_back();
            }
            f[1].push_back({cur.se, sec});
        }
    }
    cout << ((ans + g[0] + g[1]) % MOD + MOD) % MOD;
}