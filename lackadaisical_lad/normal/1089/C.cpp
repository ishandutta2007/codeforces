#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int ask(int v) {
    cout << v << endl;
    string s;
    int w;
    cin >> s;
    if (s == "FOUND") {
        return -1;
    }
    cin >> w;
    return w;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, 1e9));
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int prev;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            v--;
            if (j) {
                g[prev][v] = 1;
                g[v][prev] = 1;
            }
            prev = v;
        }
    }
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        const int N = 500;
        bitset<N> cand;
        for (int i = 0; i < n; i++) {
            cand[i] = 1;
        }
        while (true) {
            int best = 1e9;
            int bestV = -1;
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    if (cand[j]) {
                        sum += g[i][j];
                    }
                }
                if (sum < best) {
                    best = sum;
                    bestV = i;
                }
            }
            int w = ask(bestV + 1);
            if (w == -1) {
                break;
            }
            w--;
            for (int i = 0; i < n; i++) {
                if (cand[i] && g[i][bestV] < g[i][w]) {
                    cand[i] = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}