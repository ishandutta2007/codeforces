#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
vector < pair < int, int > > his_id[maxN];
vector < pair < int, int > > cyc[maxN];
bool used[maxN];
vector < int > cmp;
bool was[maxN];
int tot[maxN][2];
vector < int > our_ord;
vector < pair < int, int > > g[maxN][2];
int pos[maxN];
void dfs(int v) {
    used[v] = true;
    pos[v] = our_ord.size();
    our_ord.push_back(v);
    for (auto it : his_id[v]) {
        if (was[it.first]) continue;
        was[it.first] = true;
        for (auto p : cyc[it.first]) {
            if (used[p.first]) continue;
            dfs(p.first);
        }
    }
}
int combine(int neg, int val, int neg2, int val2) {
    return ((!val ^ neg) || (!val2 ^ neg2));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int val = 1;
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int a;
            cin >> a;
            if (a > 0) {
                if (cnt == 1) {
                    tot[a][0] ^= 1;
                }
                else {
                    his_id[a].emplace_back(i, 0);
                    cyc[i].emplace_back(a, 0);
                }
            }
            else {
                if (cnt == 1) {
                    tot[-a][1] ^= 1;
                }
                else {
                    his_id[-a].emplace_back(i, 1);
                    cyc[i].emplace_back(-a, 1);
                }
            }
        }
        if (cnt == 1) continue;
        if (cnt == 2 && cyc[i][0].first == cyc[i][1].first) {
            his_id[cyc[i][0].first].pop_back();
            his_id[cyc[i][0].first].pop_back();
            if (cyc[i][0].second == cyc[i][1].second) {
                tot[cyc[i][0].first][cyc[i][0].second] ^= 1;
            }
            else {
                val ^= 1;
            }
        }
        else {
            assert(!cyc[i].empty());
            for (int d = 0; d < 2; d++) {
                g[cyc[i][d].first][cyc[i][d].second].emplace_back(cyc[i][d ^ 1]);
            }
        }
    }
    int dp[2] = {1, 0};
    for (int i = 1; i <= m; i++) {
        if (!used[i]) {
            our_ord.clear();
            dfs(i);
            int our_dp[2][2][2] = {};
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    for (int c = 0; c < 2; c++) {
                        if (c == 0 && a == b) {
                            our_dp[a][b][c] = 1;
                        }
                        else {
                            our_dp[a][b][c] = 0;
                        }
                    }
                }
            }
            int tot_dp[2] = {0, 0};
            for (int it = 0; it < our_ord.size(); it++) {
                int nxt_dp[2][2][2] = {};
                for (int st_val = 0; st_val < 2; st_val++) {
                    for (int cur_val = 0; cur_val < 2; cur_val++) {
                        for (int ans = 0; ans < 2; ans++) {
                            if (!our_dp[st_val][cur_val][ans]) continue;
                            int cur_ans = ans;
                            cur_ans ^= tot[our_ord[it]][cur_val];
                            if (it + 1 < our_ord.size()) {
                                for (int will_val = 0; will_val < 2; will_val++) {
                                    int cop_ans = cur_ans;
                                    for (int b = 0; b < 2; b++) {
                                        for (auto& t : g[our_ord[it + 1]][b]) {
                                            if (pos[t.first] >= pos[our_ord[it + 1]]) continue;
                                            assert(pos[t.first] + 1 == pos[our_ord[it + 1]] || pos[t.first] == 0);
                                            if (pos[t.first] == 0) {
                                                cop_ans ^= combine(b, will_val, t.second, st_val);
                                            }
                                            else {
                                                cop_ans ^= combine(b, will_val, t.second, cur_val);
                                            }
                                        }
                                    }
                                    nxt_dp[st_val][will_val][cop_ans] = sum(nxt_dp[st_val][will_val][cop_ans],
                                        our_dp[st_val][cur_val][ans]);
                                }
                            }
                            else {
                                tot_dp[cur_ans] = sum(tot_dp[cur_ans], our_dp[st_val][cur_val][ans]);
                            }
                        }
                    }
                }
                for (int a = 0; a < 2; a++) {
                    for (int b = 0; b < 2; b++) {
                        for (int c = 0; c < 2; c++) {
                            our_dp[a][b][c] = nxt_dp[a][b][c];
                        }
                    }
                }
            }
            int nxt_dp[2] = {0, 0};
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    nxt_dp[a ^ b] = sum(nxt_dp[a ^ b], mult(dp[a], tot_dp[b]));
                }
            }
            for (int a = 0; a < 2; a++) dp[a] = nxt_dp[a];
        }
    }
    cout << dp[val];
    return 0;
}