#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 5e4 + 10;
int can[15];
int dp[maxN][1025];
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int trans[1025][10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        can[u] |= (1 << v);
        can[v] |= (1 << u);
    }
    for (int i = 0; i < 10; i++) {
        can[i] |= (1 << i);
    }
    dp[0][1023] = 1;
    for (int mask = 0; mask < 1024; mask++) {
        for (int x = 0; x < 10; x++) {
            if (mask & (1 << x)) {
                int new_mask = (1 << x);
                for (int z = 0; z < x; z++) {
                    if (!(can[x] & (1 << z))) {
                        new_mask |= (1 << z);
                    }
                }
                for (int z = x + 1; z < 10; z++) {
                    if ((mask & (1 << z)) || (!(can[x] & (1 << z)))) {
                        new_mask |= (1 << z);
                    }
                }
                trans[mask][x] = new_mask;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < 1024; mask++) {
            for (int x = 0; x < 10; x++) {
                if (mask & (1 << x)) {
                    dp[i + 1][trans[mask][x]] = sum(dp[i + 1][trans[mask][x]], dp[i][mask]);
                }
            }
        }
    }
    int s = 0;
    for (int i = 0; i < 1024; i++) {
        s = sum(s, dp[n][i]);
    }
    cout << s << '\n';
    return 0;
}