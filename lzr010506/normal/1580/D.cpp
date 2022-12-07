#include <bits/stdc++.h>
using namespace std;
using LL = long long;
vector<int> cartesian_tree(vector<int>& v) {
    int n = v.size();
    vector<int> p(n, -1);
    stack<int> s;
    for (int i = 0, t = -1; i < n; i += 1) {
        for(t = -1; not s.empty() and v[s.top()] > v[i]; s.pop())
            t = s.top();
        if (not s.empty()) p[i] = s.top();
        if (t != -1) p[t] = i;
        s.push(i);
    }
    return p;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    auto p = cartesian_tree(v);
    vector<int> L(n, -1), R(n, -1), size(n);
    vector<vector<LL>> dp(n, vector<LL>(n + 1));
    int r = 0;
    for (int i = 0; i < n; i += 1) {
        //cout << i << " " << p[i] << endl;
        if (p[i] != -1) {
            if (p[i] >= i) L[p[i]] = i;
            else R[p[i]] = i;
        }  
        else r = i;
    }
    function<void(int)> dfs = [&](int u) {
        size[u] = 1;
        if (L[u] != -1) {
            dfs(L[u]);
            size[u] += size[L[u]];
        }
        if (R[u] != -1) {
            dfs(R[u]);
            size[u] += size[R[u]];
        }
        //cout << u << " " << size[u] << endl;
        for (int i = 1; i <= size[u]; i += 1) dp[u][i] = -1E18;
        dp[u][1] = (LL)m * v[u] - v[u];
        if (L[u] != -1) {
            for (int i = 1; i <= size[L[u]]; i += 1) {
                dp[u][i] = max(dp[u][i], dp[L[u]][i]);
                dp[u][i + 1] = max(dp[u][i + 1], dp[L[u]][i] - (LL)(2 * i + 1) * v[u] + (LL)m * v[u]);
            }
        }
        if (R[u] != -1) {
            for (int i = 1; i <= size[R[u]]; i += 1) {
                dp[u][i] = max(dp[u][i], dp[R[u]][i]);
                dp[u][i + 1] = max(dp[u][i + 1], dp[R[u]][i] - (LL)(2 * i + 1) * v[u] + (LL)m * v[u]);
            }
        }
        if (L[u] != -1 and R[u] != -1) {
            for (int i = 1; i <= size[L[u]]; i += 1)
                for (int j = 1; j <= size[R[u]]; j += 1) {
                    dp[u][i + j] = max(dp[u][i + j], dp[L[u]][i] + dp[R[u]][j] - (LL) i * j * 2 * v[u]);
                    dp[u][i + j + 1] = max(dp[u][i + j + 1], dp[L[u]][i] + dp[R[u]][j] - (LL) (i * j * 2 + 2 * i + 2 * j + 1) * v[u] + (LL)m * v[u]);
                }
        }
    };
    dfs(r);
    cout << dp[r][m] << " ";
    return 0;
}