#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int n, m, k;
const int maxN = 3e5 + 10;
vector<int> vec[maxN];
bool bad[maxN];
vector<int> bck[maxN];
bool mark_bad[maxN];
bool used[maxN];
void go(int v) {
    used[v] = true;
    for (int z : bck[v]) {
        if (!mark_bad[z]) {
            mark_bad[z] = true;
            for (int to : vec[z]) {
                bad[to] = true;
                if (!used[to]) {
                    go(to);
                }
            }
        }
    }
}
int nxt[maxN];
vector<int> g[maxN];
void dfs(int v, vector<int>& cmp) {
    cmp.emplace_back(v);
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, cmp);
        }
    }
}
int cnt[maxN];
int gg[maxN];
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        vec[i].resize(sz);
        for (int& t : vec[i]) {
            cin >> t;
            if (!bck[t].empty() && bck[t].back() == i) {
                bad[t] = true;
            }
            bck[t].emplace_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        if (bad[i] && !used[i]) {
            go(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!mark_bad[i]) {
            for (int z = 0; z + 1 < vec[i].size(); z++) {
                if (nxt[vec[i][z]] != 0 && nxt[vec[i][z]] != vec[i][z + 1]) {
                    bad[vec[i][z]] = true;
                }
                nxt[vec[i][z]] = vec[i][z + 1];
                g[vec[i][z]].emplace_back(vec[i][z + 1]);
                g[vec[i][z + 1]].emplace_back(vec[i][z]);
            }
        }
    }
    memset(used, 0, sizeof used);
    for (int i = 1; i <= k; i++) {
        if (bad[i] && !used[i]) {
            go(i);
        }
    }
    memset(used, 0, sizeof used);
    for (int i = 1; i <= k; i++) {
        if (!used[i] && !bad[i]) {
            vector<int> cmp;
            dfs(i, cmp);
            bool ok = true;
            int f = 0;
            for (int z : cmp) {
                if (nxt[z] == 0) f++;
                else {
                    cnt[nxt[z]]++;
                    if (cnt[nxt[z]] > 1) ok = false;
                }
            }
            if (f != 1) ok = false;
            if (ok) {
                gg[cmp.size()]++;
            }
        }
    }
    vector<pair<int,int>> trans;
    for (int i = 1; i <= m; i++) {
        if (gg[i]) {
            trans.emplace_back(gg[i], i);
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (auto& it : trans) {
            if (i >= it.second) dp[i] = sum(dp[i], mult(dp[i - it.second], it.first));
        }
    }
    cout << dp[m];
    return 0;
}