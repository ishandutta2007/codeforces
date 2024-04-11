#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MOD = 1E9 + 7;

int n, d, p;
long long ans = 0, inv[N], tmp[N], c[N][N], f[N][N], g[N];
vector<int> adj[N];

void init() {
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        adj[p].push_back(i);
    }
    init();
    for (int u = n; u >= 1; u--) {
        for (int i = 1; i <= n; i++) {
            f[u][i] = 1;
        }
        for (int &v : adj[u]) {
            for (int i = 1; i <= n; i++) {
                (f[u][i] *= f[v][i]) %= MOD;
            }
        }
        for (int i = 1; i <= n; i++) {
            (f[u][i] += f[u][i - 1]) %= MOD;
        }
    }
    for (int i = 1; i <= min(n, d); i++) {
        long long cur = 1;
        for (int j = 1; j <= i; j++) {
            (cur *= inv[j]) %= MOD;
            (cur *= (d - j + 1)) %= MOD;
        }
        g[i] = f[1][i];
        for (int j = 1; j < i; j++) {
            (g[i] -= g[j] * c[i][j]) %= MOD;
        }
        (ans += cur * g[i]) %= MOD;
    }
    cout << (ans + MOD) % MOD;
}