#include <bits/stdc++.h>

using namespace std;

int n, m;
long long x[300005], y[300005];
long long ans[300005];
int ord[300005];
long long sx[300005], sy[300005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i], ord[i] = i;
    sort(ord + 1, ord + n + 1, [](int a, int b) { return x[a] - y[a] > x[b] - y[b]; });
    for (int i = 1; i <= n; ++i) {
        int id = ord[i];
        sx[i] = sx[i-1] + x[id];
        sy[i] = sy[i-1] + y[id];
    }
    for (int i = 1; i <= n; ++i) {
        int id = ord[i];
        ans[id] = x[id] * (i - 1) + y[id] * (n - i);
        ans[id] += sy[i - 1] + sx[n] - sx[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        long long ret = min(x[u] + y[v], x[v] + y[u]);
        ans[u] -= ret, ans[v] -= ret;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}