#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 30005, MX = 5, Q = 3E5 + 5;

int n, c, q, t, a[N], ans[Q], pos[Q];
long long dp[N][MX], lex[Q], off[MX], cnt[MX + 1];
vector<pair<int, int>> cur, eve[N];
vector<int> dl[N];
set<pair<long long, int>> pro[MX];

void init() {
    fill(dp[0], dp[0] + MX, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < MX; j++) {
            for (int k = 0; k <= j && k < i; k++) {
                dp[i][j] += dp[i - k - 1][j - k];
            }
        }
    }
}

int lower(long long u) {
    for (int i = 1; i <= MX; i++) {
        if (cnt[i] > u) {
            return i - 1;
        }
    }
}

void solve() {
    for (int i = 0; i < MX; i++) {
        pro[i].clear();
    }
    fill(off, off + MX, 0);
    cin >> n >> c >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> pos[i] >> lex[i]; lex[i]--;
        if (lex[i] >= dp[n][c]) {
            ans[i] = -1;
        } else {
            eve[1].push_back({i, c});
            dl[pos[i]].push_back(i);
            ans[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto [ind, cos] : eve[i]) {
            pro[cos].insert({lex[ind] + off[cos], ind});
        }
        eve[i].clear();
        cur.clear();
        for (int j = 0; j <= c; j++) {
            if (i + j <= n) {
                cur.push_back({a[i + j], j});
            }
            sort(cur.begin(), cur.end());
            long long l, r;
            for (int k = 0; k < cur.size(); k++) {
                auto [_, cos] = cur[k];
                cnt[k + 1] = cnt[k] + dp[n - (i + cos + 1) + 1][j - cos];
                if (cos == 0) {
                    l = cnt[k]; r = cnt[k + 1];
                }
            }
            while (!pro[j].empty() && pro[j].begin()->fi - off[j] < l) {
                auto [cl, ind] = *pro[j].begin(); pro[j].erase(pro[j].begin());
                if (ans[ind] != 0) {
                    continue;
                }
                int p = lower(cl - off[j]);
                auto [_, cos] = cur[p];
                if (i + cos >= pos[ind]) {
                    ans[ind] = a[2 * i + cos - pos[ind]];
                } else {
                    lex[ind] = cl - off[j] - cnt[p];
                    eve[i + cos + 1].push_back({ind, j - cos});
                }
            }
            while (!pro[j].empty() && prev(pro[j].end())->fi - off[j] >= r) {
                auto [cl, ind] = *prev(pro[j].end()); pro[j].erase(prev(pro[j].end()));
                if (ans[ind] != 0) {
                    continue;
                }
                int p = lower(cl - off[j]);
                auto [_, cos] = cur[p];
                if (i + cos >= pos[ind]) {
                    ans[ind] = a[2 * i + cos - pos[ind]];
                } else {
                    lex[ind] = cl - off[j] - cnt[p];
                    eve[i + cos + 1].push_back({ind, j - cos});
                }
            }
            off[j] += l;
        }
        for (int ind : dl[i]) {
            if (ans[ind] == 0) {
                ans[ind] = a[i];
            }
        }
        dl[i].clear();
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) {
        solve();
    }
}