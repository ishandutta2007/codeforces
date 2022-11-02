#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef long long ll;

int n, m, q;
bool adj[15][15];
vector<pii> ladj[15];
ll dp[1<<13][15];

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        if (a == b && a != c) {
            cout << "0\n";
            return 0;
        }
        ladj[a].push_back(pii(b, c));
        ladj[b].push_back(pii(a, c));
    }

    for (int i = 0; i < n; i++) dp[1<<i][i] = 1;
    
    for (int i = 0; i < 1<<n; i++)
        if (__builtin_popcount(i) >= 2)
            for (int j = 0; j < n; j++)
                if (i & 1<<j) {
                    int mask = i - (1<<j);
                    int x = mask & - mask;
                    mask -= x;
                    for (int k1 = mask, flag = 1; flag; k1 = (k1 - 1) & mask) {
                        if (!k1) flag = 0;
                        int k = k1 | x;
                        
                        bool good = 1;
                        for (int a = 0; a < n; a++) {
                            if (k & 1<<a)
                                for (pii p : ladj[a])
                                    if ((i - k) & 1<<p.A)
                                        if (p.B != j) {
                                            good = 0;
                                            break;
                                        }

                            if (!good) break;
                        }

                        if (!good) continue;

                        int r = -1;
                        for (int a = 0; a < n; a++)
                            if (k & 1<<a) {
                                if (adj[a][j]) {
                                    if (r == -1) r = a;
                                    else r = -2;
                                }

                                for (int b = 0; b < n; b++)
                                    if (b != j && ((i - k) & 1<<b))
                                        if (adj[a][b]) r = -2;
                            }

                        if (r == -1) {
                            for (int a = 0; a < n; a++)
                                if (k & 1<<a)
                                    dp[i][j] += dp[k][a] * dp[i - k][j];
                        } else if (r >= 0)
                            dp[i][j] += dp[k][r] * dp[i - k][j];
                    }
                }

    cout << dp[(1<<n) - 1][0] << '\n';
}