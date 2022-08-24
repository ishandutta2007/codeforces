#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
void dfs(int v, vector<vector<int>>& g, vector<int>& ord, vector<bool>& used) {
    used[v] = true;
    for (int x : g[v]) {
        if (!used[x]) {
            dfs(x, g, ord, used);
        }
    }
    ord.emplace_back(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> a(n);
        vector<ll> real_val(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            real_val[i] = a[i];
            a[i] %= mod;
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            g[x].emplace_back(y);
        }
        vector<bool> used(n, false);
        const ll INF = 1e12;
        int ans = -1;
//        cout << " HI " << endl;
        for (int iter = 0; iter < n + m; iter++) {
            vector<ll> cop = real_val;
//            cout << " GGG " << end
            bool fnd = false;
            for (int i = 0; i < n; i++) {
                if (real_val[i] > 0) {
                    fnd = true;
                    cop[i] -= 1;
                    a[i] = sub(a[i], 1);
                    for (int x : g[i]) {
                        cop[x] += 1;
                        a[x] = sum(a[x], 1);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                real_val[i] = min(cop[i], INF);
            }
            if (!fnd) {
                ans = iter;
                break;
            }
        }
        if (ans != -1) {
            cout << ans << '\n';
        }
        else {
            ans = n + m;
            vector<int> ord;
            vector<bool> used(n, false);
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    dfs(i, g, ord, used);
                }
            }
            vector<int> f(n);
            f[ord[0]] = 1;
            for (int x : ord) {
                for (int y : g[x]) {
                    f[x] = sum(f[x], f[y]);
                }
            }
            for (int i = 0; i < n; i++) {
                ans = sum(ans, mult(a[i], f[i]));
            }
            cout << ans << '\n';
        }
    }
    return 0;
}