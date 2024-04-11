#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll inf64 = 1e18;

ll slow(int n, int m, vector<int> a) {
    ll res = -inf64;
    vector<vector<int>> mn(n, vector<int>(n, 1 << 31));
    for (int l = 0; l < n; l++) {
        mn[l][l] = a[l];
        for (int r = l + 1; r < n; r++)
            mn[l][r] = min(mn[l][r - 1], a[r]);
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != m)
            continue;
        ll cost = 0;
        vector<int> in;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask)
                in.push_back(i);
        }
        for (int i : in)
            cost += 1ll * a[i] * m;
        for (int i : in) {
            for (int j : in) {
                cost -= mn[min(i, j)][max(i, j)];
            }
        }
        res = max(res, cost);
    }
    return res;
}

ll fast(int n, int m, vector<int> a) {
    vector<vector<int>> argmin(n, vector<int>(n, -1));
    for (int l = 0; l < n; l++) {
        int x = -1;
        for (int r = l; r < n; r++) {
            if (x == -1 || a[x] > a[r])
                x = r;
            argmin[l][r] = x;
        }
    }

    vector<vector<pii>> g;

    {
        queue<tuple<int, int, int>> q;
        g.emplace_back();
        q.push({0, n - 1, 0});
        while (!q.empty()) {
            auto [l, r, v] = q.front();
            q.pop();
            int mid = argmin[l][r];
            int xv = a[mid];
            if (l < mid) {
                int to = (int) g.size();
                g.emplace_back();
                g[v].emplace_back(to, a[argmin[l][mid - 1]] - xv);
                q.push({l, mid - 1, to});
            }
            if (mid < r) {
                int to = (int) g.size();
                g.emplace_back();
                g[v].emplace_back(to, a[argmin[mid + 1][r]] - xv);
                q.push({mid + 1, r, to});
            }
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, -inf64));
    vector<int> sz(n);
    for (int v = n - 1; v >= 0; v--) {
        sz[v] = 1;
        for (auto [to, w] : g[v])
            sz[v] += sz[to];
    }

    function<void(int)> dfs = [&](int v) {
        dp[v][0] = 0;
        dp[v][1] = 0;
        int cur = 1;
        for (auto [to, w] : g[v]) {
            dfs(to);
            vector<ll> hlp(min(m, sz[v]) + 1, -inf64);
            for (int c = 0; c <= sz[v] && c <= m; c++)
                hlp[c] = dp[v][c];
            for (int c_was = 0; c_was <= sz[v] && c_was <= m && c_was <= cur; c_was++) {
                for (int c_to = 0; c_to <= sz[to] && c_was + c_to <= sz[v] && c_was + c_to <= m; c_to++) {
                    int c_now = c_was + c_to;
                    hlp[c_now] = max(hlp[c_now], dp[v][c_was] + dp[to][c_to] + 1ll * w * c_to * (m - c_to));
                }
            }
            for (int c = 0; c <= sz[v] && c <= m; c++)
                dp[v][c] = max(dp[v][c], hlp[c]);
            cur += sz[to];
        }
    };
    dfs(0);

    return dp[0][m];
}

void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll res = fast(n, m, a);
//#ifdef DEBUG
//    ll sl = slow(n, m, a);
//    cout << "slow = " << sl << "\n";
//#endif
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}