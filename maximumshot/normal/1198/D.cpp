#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 55;

int n;
char s[N][N];
int dp[N][N][N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    fill((int*) dp, (int*) dp + N * N * N * N, inf);

    for (int li = n - 1; li >= 0; li--) {
        for (int ri = li; ri < n; ri++) {
            for (int lj = n - 1; lj >= 0; lj--) {
                for (int rj = lj; rj < n; rj++) {
                    dp[li][ri][lj][rj] = max(ri - li + 1, rj - lj + 1);
                    if (li == ri && lj == rj) {
                        dp[li][ri][lj][rj] = s[li][lj] == '#';
                        continue;
                    }
                    for (int qi = li; qi < ri; qi++) {
                        dp[li][ri][lj][rj] = min(
                            dp[li][ri][lj][rj],
                            dp[li][qi][lj][rj] + dp[qi + 1][ri][lj][rj]
                        );
                    }
                    for (int qj = lj; qj < rj; qj++) {
                        dp[li][ri][lj][rj] = min(
                            dp[li][ri][lj][rj],
                            dp[li][ri][lj][qj] + dp[li][ri][qj + 1][rj]
                        );
                    }
                }
            }
        }
    }

    cout << dp[0][n - 1][0][n - 1] << "\n";

    return 0;
}