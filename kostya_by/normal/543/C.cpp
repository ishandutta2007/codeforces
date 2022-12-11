#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 22;
const int MAXM = 22;
const int INF = 1000000000;

int n, m;
int a[MAXN][MAXM];
int sum_a[MAXM][26];
int msk[MAXM][26];
string s[MAXN];

int f[2][1 << MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            int c = s[i][j] - 'a';
            sum_a[j][c] += a[i][j];
            msk[j][c] |= (1 << i);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (1 << n); j++) {
            f[i][j] = INF;
        }
    }

    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (f[0][mask] == INF) {
                continue;
            }

            f[1][mask] = min(f[1][mask], f[0][mask] );

            if (mask & (1 << i) ) {
                // f[1][mask] = min(f[1][mask], f[0][mask] );
                continue;
            }

            for (int j = 0; j < m; j++) {
                f[1][mask | (1 << i) ] = min(f[1][mask | (1 << i) ], f[0][mask] + a[i][j] );

                int c = s[i][j] - 'a';
                f[1][mask | msk[j][c] ] = min(f[1][mask | msk[j][c] ], f[0][mask] + sum_a[j][c] - a[i][j] );
            }
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            f[0][mask] = f[1][mask];
            f[1][mask] = INF;
        }
    }

    cout << f[0][(1 << n) - 1] << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}