#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7, P = 16, N = 60;

int n, len = 0, a[N], ed[N], cnt[1 << P];
bool vis[N];
long long ans = 1, dp[N][1 << P], fct[N], inv[N], ifc[N];
vector<int> ve;

void init() {
    inv[1] = 1;
    for (int i = 2; i < n; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    fct[0] = ifc[0] = 1;
    for (int i = 1; i < n; i++) {
        fct[i] = fct[i - 1] * i % MOD;
        ifc[i] = ifc[i - 1] * inv[i] % MOD;
    }
}

void DFS(int u) {
    vis[u] = true;
    ve.push_back(a[u]);
    for (int i = 0; i < n; i++) {
        if (!vis[i] && (a[u] % a[i] == 0 || a[i] % a[u] == 0)) {
            DFS(i);
        }
    }
}

void reset(int p, int m) {
    for (int msk = 0; msk < (1 << p); msk++) {
        cnt[msk] = 0;
    }
    for (int i = 0; i <= m; i++) {
        for (int msk = 0; msk < (1 << p); msk++) {
            dp[i][msk] = 0;
        }
    }
}

int solve() {
    vector<int> s, t;
    sort(ve.begin(), ve.end());
    for (int i = 0; i < ve.size(); i++) {
        bool chk = false;
        for (int j = 0; j < i; j++) {
            if (ve[i] % ve[j] == 0) {
                chk = true;
                break;
            }
        }
        (chk ? t : s).push_back(ve[i]);
    }
    int p = s.size(), m = t.size();
    if (m == 0) {
        return 0;
    }
    reset(p, m);

    // SOS DP on count of mask
    for (int i = 0; i < m; i++) {
        ed[i] = 0;
        for (int j = 0; j < p; j++) {
            if (t[i] % s[j] == 0) {
                ed[i] ^= (1 << j);
            }
        }
        cnt[ed[i]]++;
    }
    for (int i = 0; i < p; i++) {
        for (int msk = 0; msk < (1 << p); msk++) {
            if (!(msk >> i & 1)) {
                cnt[msk ^ (1 << i)] += cnt[msk];
            }
        }
    }

    // answer dp
    for (int i = 0; i < m; i++) {
        dp[1][ed[i]]++;
    }
    for (int i = 1; i < m; i++) {
        for (int msk = 0; msk < (1 << p); msk++) {
            for (int j = 0; j < m; j++) {
                if ((ed[j] & msk) != ed[j] && (ed[j] & msk) != 0) {
                    (dp[i + 1][msk | ed[j]] += dp[i][msk]) %= MOD;
                }
            }
            (dp[i + 1][msk] += dp[i][msk] * (cnt[msk] - i)) %= MOD;
        }
    }
    long long ret = 0;
    for (int msk = 0; msk < (1 << p); msk++) {
        (ret += dp[m][msk]) %= MOD;
    }
    (ans *= ret * ifc[m - 1] % MOD) %= MOD;
    return m - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init();
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ve.clear();
            DFS(i);
            len += solve();
        }
    }
    (ans *= fct[len]) %= MOD;
    cout << ans;
}