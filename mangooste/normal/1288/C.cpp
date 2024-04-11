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

const ll MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;
    int N = n + 2 * m - 1, M = 2 * m;
    vector<vector<ll>> C(N + 1, vector<ll>(M + 1));
    C[0][0] = 1;
    forn(i, N + 1) if (i != 0) {
        C[i][0] = 1;
        forn(j, M + 1) if (j != 0) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    // forn(i, N + 1)  { forn(j, M + 1) cout << C[i][j] << ' '; cout << "\n\n"; }
    cout << C[N][M] << '\n';
}