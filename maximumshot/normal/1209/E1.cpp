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
int a[N][M];
int dp[1 << N][M];
int best[M][1 << N];
int value[M][1 << N];
int _bit[1 << N];

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int mask = 1; mask < (1 << n); mask++) {
            int b = _bit[mask & -mask];
            value[j][mask] = value[j][mask ^ (1 << b)] + a[b][j];
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            best[j][mask] = 0;
            for (int sh = 0; sh < n; sh++) {
                int score = 0;
                for (int i = 0; i < n; i++) {
                    if ((1 << i) & mask) {
                        score += a[(sh + i) % n][j];
                    }
                }
                best[j][mask] = max(best[j][mask], score);
            }
        }
    }

    fill((int*) dp, (int*) dp + (1 << N) * M, 0);

    for (int j = 1; j <= m; j++) {
        for (int now = 0; now < (1 << n); now++) {
            for (int was = now; was >= 0; was = (was - 1) & now) {
                int cur = now ^ was;
                dp[j][now] = max(dp[j][now], dp[j - 1][was] + best[j][cur]);
                if (!was) break;
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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}