#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
const int mod = (int)1e9 + 7;
int n, k;
bool used[maxN];
vector < int > g[maxN];
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int dfs(int v) {
    used[v] = true;
    int val = 1;
    for (int to : g[v]) {
        if (used[to]) continue;
        val += dfs(to);
    }
    return val;
}
int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        if (!x) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int sz = dfs(i);
            ans = sum(ans, pw(sz, k));
        }
    }
    cout << sum(pw(n, k), mod - ans);
    return 0;
}