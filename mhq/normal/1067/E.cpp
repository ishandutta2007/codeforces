#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(pw(a, b - 1), a);
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 5 * (int)1e5 + 10;
vector < int > g[maxN];
int ans = 0;
const int inv2 = (mod + 1) / 2;
int dfs(int v, int par) {
    int pr = 1;
    for (int to : g[v]) {
        if (to == par) continue;
        int take_pr = dfs(to, v);
        pr = mult(pr, sum(take_pr, mult(inv2, sub(1, take_pr))));
    }
    ans = sum(ans, sub(1, pr));
    return sub(1, pr);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << mult(ans, pw(2, n));
    return 0;
}