#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 18;
int n;
vector < int > get_part(int msk) {
    int cur = 1;
    vector < int > all;
    for (int i = 0; i < (n - 1); i++) {
        if (msk & (1 << i)) {
            cur++;
        }
        else {
            if (cur) {
                all.emplace_back(cur);
                cur = 1;
            }
        }
    }
    all.emplace_back(cur);
    sort(all.begin(), all.end());
    return all;
}
map < vector < int >, ll > mp;
char c[maxN][maxN];
ll dp[(1 << maxN) + 2][maxN];
ll val[(1 << maxN) + 2];
int bts[(1 << maxN) + 2];
ll go(int need) {
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) dp[(1 << i)][i] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int lst = 0; lst < n; lst++) {
            if (!dp[mask][lst]) continue;
            for (int nxt = 0; nxt < n; nxt++) {
                if (mask & (1 << nxt)) continue;
                if (need & (1 << (bts[mask] - 1))) {
                    if (c[lst][nxt] == '0') continue;
                }
                dp[mask | (1 << nxt)][nxt] += dp[mask][lst];
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += dp[(1 << n) - 1][i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    bts[0] = 0;
    cin >> n;
    for (int i = 1; i < (1 << n); i++) bts[i] = bts[i / 2] + (i & 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < (1 << (n - 1)); i++) {
        auto it = get_part(i);
        if (mp.find(it) == mp.end()) {
            ll d = go(i);
            val[i] = d;
            mp[it] = d;
        }
        else {
            val[i] = mp[it];
        }
    }

    for (int bit = 0; bit < (n - 1); bit++) {
        for (int mask = 0; mask < (1 << (n - 1)); mask++) {
            if (mask & (1 << bit)) {
                val[mask ^ (1 << bit)] -= val[mask];
            }
        }
    }
    for (int i = 0; i < (1 << (n - 1)); i++) cout << val[i] << " ";
    return 0;
}