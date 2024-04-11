#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

// #define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

vector<vector<char>> G;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;
    G.resize(n, vector<char>(n, 0));
    forn(i, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v][u] = G[u][v] = 1;
    }
    if (n < 7) return cout << m << '\n', 0;
    int mn = (n + m) * 10;
    forn(v, n) for (int u = v + 1; u < n; u++) {
        int cur = 0;
        forn(i, n) cur += (G[i][v] && G[i][u]);
        mn = min(mn, cur);
    }
    cout << m - mn << '\n';
}