#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 40;

int n, k, u, v;
long long ans = 0, dp[2 * N][2 * N];
vector<pair<string, int>> ve[2 * N];
string s;

bool check(int u, string s, int v) {
    if (s == "=") {
        return u == v;
    } else if (s == "<=") {
        return u <= v;
    } else if (s == ">=") {
        return u >= v;
    } else if (s == "<") {
        return u < v;
    } else {
        return u > v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    while (k--) {
        cin >> u >> s >> v;
        ve[u].push_back({s, v});
        switch (s[0]) {
            case '<': s[0] = '>'; break;
            case '>': s[0] = '<'; break;
        }
        ve[v].push_back({s, u});
    }
    dp[0][2 * n + 1] = 1;
    for (int cur = 1; cur <= n; cur++) {
        for (int l = 0; l <= 2 * cur; l++) {
            int r = 2 * n + 1 - (2 * cur - l);
            if (l >= 2 && cur < n) {
                bool chk = true;
                for (pair<string, int> &con : ve[l - 1]) {
                    int v = 0;
                    if (con.se < l - 1 || con.se >= r) {
                        v = -1;
                    } else if (con.se > l && con.se < r) {
                        v = 1;
                    }
                    if (!check(0, con.fi, v)) {
                        chk = false;
                    }
                }
                for (pair<string, int> &con : ve[l]) {
                    int v = 0;
                    if (con.se < l - 1 || con.se >= r) {
                        v = -1;
                    } else if (con.se > l && con.se < r) {
                        v = 1;
                    }
                    if (!check(0, con.fi, v)) {
                        chk = false;
                    }
                }
                if (chk) {
                    dp[l][r] += dp[l - 2][r];
                }
            }
            if (r <= 2 * n - 1 && cur < n) {
                bool chk = true;
                for (pair<string, int> &con : ve[r]) {
                    int v = 0;
                    if (con.se <= l || con.se > r + 1) {
                        v = -1;
                    } else if (con.se > l && con.se < r) {
                        v = 1;
                    }
                    if (!check(0, con.fi, v)) {
                        chk = false;
                    }
                }
                for (pair<string, int> &con : ve[r + 1]) {
                    int v = 0;
                    if (con.se <= l || con.se > r + 1) {
                        v = -1;
                    } else if (con.se > l && con.se < r) {
                        v = 1;
                    }
                    if (!check(0, con.fi, v)) {
                        chk = false;
                    }
                }
                if (chk) {
                    dp[l][r] += dp[l][r + 2];
                }
            }
            if (l >= 1 && r <= 2 * n) {
                bool chk = true;
                for (pair<string, int> &con : ve[l]) {
                    int v = 0;
                    if (con.se < l || con.se > r) {
                        v = -1;
                    } else if (con.se > l && con.se < r) {
                        v = 1;
                    }
                    if (!check(0, con.fi, v)) {
                        chk = false;
                    }
                }
                for (pair<string, int> &con : ve[r]) {
                    int v = 0;
                    if (con.se < l || con.se > r) {
                        v = -1;
                    } else if (con.se > l && con.se < r) {
                        v = 1;
                    }
                    if (!check(0, con.fi, v)) {
                        chk = false;
                    }
                }
                if (chk) {
                    dp[l][r] += dp[l - 1][r + 1];
                }
            }
        }
    }
    for (int i = 0; i <= 2 * n; i++) {
        ans += dp[i][i + 1];
    }
    cout << ans;
}