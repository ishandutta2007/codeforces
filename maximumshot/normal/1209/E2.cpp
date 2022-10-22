#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 12;
const int M = 2005;

int n, m;
int a[2 * N][M], aa[2 * N][M];
int dp[M][1 << N];
int _bit[1 << N];
vector<int> _bits[1 << N];
int f[1 << N], col_mx[M];

void solve() {
    cin >> n >> m;

    for (int j = 1; j <= m; j++) {
        col_mx[j] = 0;
    }

    vector<int> ord(m);
    for (int j = 1; j <= m; j++) {
        ord[j - 1] = j;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i + n][j] = a[i][j];
            col_mx[j] = max(col_mx[j], a[i][j]);
        }
    }

    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return col_mx[i] > col_mx[j];
    });

    if (m > n) ord.resize(n), m = n;

    for (int it = 0; it < (int) ord.size(); it++) {
        int j = ord[it];
        for (int i = 0; i < 2 * n; i++) {
            aa[i][it + 1] = a[i][j];
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = aa[i][j];
        }
    }

    fill((int *) dp, (int *) dp + (1 << N) * M, 0);

    for (int j = 1; j <= m; j++) {
        for (int sh = 0; sh < n; sh++) {
            fill(f, f + (1 << N), 0);
            for (int mask = 0; mask < (1 << n); mask++) {
                f[mask] = dp[j - 1][mask];
                for (int i : _bits[mask]) {
                    f[mask] = max(f[mask], f[mask ^ (1 << i)] + a[i + sh][j]);
                }
            }
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[j][mask] = max(dp[j][mask], f[mask]);
            }
        }
    }
    cout << dp[m][(1 << n) - 1] << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    for (int i = 0; i < N; i++) {
        _bit[1 << i] = i;
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if ((1 << i) & mask) {
                _bits[mask].push_back(i);
            }
        }
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}