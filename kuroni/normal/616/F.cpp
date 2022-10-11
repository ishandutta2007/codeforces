#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5, LG = 21, MX = 2E6 + 5;
const long long INF = 1E18 + 7;

int n, lg, mx, u, cur = 0, cnt = 0, val[MX], len[MX], spr[MX][LG];
int dep[MX], pos[MX], par[MX];
long long ans = -INF, dp[MX];
char s[MX];
string t[N];
vector<int> rad, ve, di[MX], adj[MX];

void suffix_array() {
    lg = __lg(cur - 1) + 1;
    for (int i = cur + (1 << lg) - 1; i >= 0; i--) {
        rad.push_back(i);
    }
    sort(rad.begin(), rad.end(), [&](const int &u, const int &v) {
        return s[u] < s[v];
    });
    int cnt = 0;
    for (int i = 1; i < rad.size(); i++) {
        if (s[rad[i]] != s[rad[i - 1]]) {
            ++cnt;
        }
        spr[rad[i]][0] = cnt;
    }
    for (int i = 0; i < lg; i++) {
        for (int &v : rad) {
            if (v - (1 << i) >= 0) {
                v -= (1 << i);
                di[spr[v][i]].push_back(v);
            }
        }
        rad.clear();
        for (int i = 0; !di[i].empty(); i++) {
            for (int &v : di[i]) {
                rad.push_back(v);
            }
            di[i].clear();
        }
        int cnt = 0;
        for (int j = 1; j < rad.size(); j++) {
            int u = rad[j], v = rad[j - 1];
            if (spr[u][i] != spr[v][i] || spr[u + (1 << i)][i] != spr[v + (1 << i)][i]) {
                ++cnt;
            }
            spr[u][i + 1] = cnt;
        }
    }
}

int lcp(int u, int v) {
    int ret = 0;
    for (int i = lg; i >= 0; i--) {
        if (spr[u + ret][i] == spr[v + ret][i]) {
            ret += (1 << i);
        }
    }
    return ret;
}

void build_suffix_tree() {
    for (int i = 0; i < cur; i++) {
        if (s[i] != '\0') {
            ++cnt;
            dep[cnt] = len[i];
            dp[cnt] = val[i];
            pos[cnt] = i;
            ve.push_back(cnt);
        }
    }
    sort(ve.begin(), ve.end(), [&](const int &u, const int &v) {
        return spr[pos[u]][lg] < spr[pos[v]][lg];
    });
    for (int i = 1; i < ve.size(); i++) {
        int u = ve[i - 1], v = ve[i];
        int lca = min(lcp(pos[u], pos[v]), min(dep[u], dep[v]));
        int cur = u, pre = -1;
        while (dep[cur] > lca) {
            pre = cur;
            cur = par[cur];
        }
        if (dep[v] == lca) {
            par[v] = par[u];
            par[u] = -1;
            dp[v] += dp[u];
        } else if (dep[cur] == lca) {
            par[v] = cur;
        } else {
            par[v] = par[pre] = ++cnt;
            par[cnt] = cur;
            dep[cnt] = lca;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (par[i] != -1) {
            adj[par[i]].push_back(i);
        }
    }
}

void DFS(int u) {
    for (int &v : adj[u]) {
        DFS(v);
        dp[u] += dp[v];
    }
    ans = max(ans, dep[u] * dp[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> u;
        for (int j = 0; j < t[i].size(); j++) {
            char c = t[i][j];
            s[cur] = c;
            val[cur] = u;
            len[cur] = t[i].size() - j;
            ++cur;
        }
        ++cur;
    }
    suffix_array();
    build_suffix_tree();
    DFS(0);
    cout << ans;
}