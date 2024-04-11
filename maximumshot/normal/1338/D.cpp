#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int dp[N][2];
int res;

void dfs(int v, int par = -1) {
    for (int i = 0; i < (int) g[v].size(); i++) {
        int to = g[v][i];
        if (to == par) {
            swap(g[v][i], g[v][(int) g[v].size() - 1]);
            g[v].pop_back();
            break;
        }
    }

    int mx1 = 0;
    int mx0 = 0;
    int child = 0;
    for (int to : g[v]) {
        child++;
        dfs(to, v);
        mx1 = max(mx1, dp[to][0]);
        mx0 = max(mx0, max(dp[to][0], dp[to][1]));
    }
    if (child > 0) {
        dp[v][1] = 1 + mx1;
        dp[v][0] = child - 1 + mx0;
    } else {
        dp[v][0] = 0;
        dp[v][1] = 1;
    }
}

void go(int v, int par, int par_dp0, int par_dp1) {
    int sz = (int) g[v].size();

    vector<int> mx1_pref(sz), mx1_suff(sz);
    vector<int> mx0_pref(sz), mx0_suff(sz);

    for (int i = 0; i < sz; i++) {
        int to = g[v][i];

        if (i > 0) {
            mx1_pref[i] = mx1_pref[i - 1];
            mx0_pref[i] = mx0_pref[i- 1];
        }

        mx1_pref[i] = max(mx1_pref[i], dp[to][0]);
        mx0_pref[i] = max(mx0_pref[i], max(dp[to][0], dp[to][1]));
    }

    for (int i = sz - 1; i >= 0; i--) {
        int to = g[v][i];

        if (i + 1 < sz) {
            mx1_suff[i] = mx1_suff[i + 1];
            mx0_suff[i] = mx0_suff[i + 1];
        }

        mx1_suff[i] = max(mx1_suff[i], dp[to][0]);
        mx0_suff[i] = max(mx0_suff[i], max(dp[to][0], dp[to][1]));
    }

    {
        int mx1 = 0, mx0 = 0, child = 0;

        if (sz > 0) {
            mx1 = mx1_pref.back();
            mx0 = mx0_pref.back();
        }

        if (par != -1) {
            mx1 = max(mx1, par_dp0);
            mx0 = max(mx0, max(par_dp0, par_dp1));
        }

        child = sz + (par != -1);

        int _dp0, _dp1;

        if (child > 0) {
            _dp1 = 1 + mx1;
            _dp0 = child - 1 + mx0;
        } else {
            _dp0 = 0;
            _dp1 = 1;
        }

        res = max(res, max(_dp0, _dp1));
    }

    for (int i = 0; i < sz; i++) {
        int to = g[v][i];

        int mx1 = 0;
        int mx0 = 0;

        if (i > 0) {
            mx1 = max(mx1, mx1_pref[i - 1]);
            mx0 = max(mx0, mx0_pref[i - 1]);
        }

        if (i + 1 < sz) {
            mx1 = max(mx1, mx1_suff[i + 1]);
            mx0 = max(mx0, mx0_suff[i + 1]);
        }

        if (par != -1) {
            mx1 = max(mx1, par_dp0);
            mx0 = max(mx0, max(par_dp0, par_dp1));
        }

        int child = sz - 1 + (par != -1);
        int _dp0, _dp1;

        if (child > 0) {
            _dp1 = 1 + mx1;
            _dp0 = child - 1 + mx0;
        } else {
            _dp0 = 0;
            _dp1 = 1;
        }

        go(to, v, _dp0, _dp1);
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    go(1, -1, 0, 0);

    cout << res << "\n";

    return 0;
}