#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const int INF = 1000 * 1000 * 1000 + 7;
const int MAXD = 517;
const int MAXS = 5107;

int dp[MAXS][MAXD];
vector<int> rv[MAXD];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);

    for (int i = 0; i < MAXS; i++) {
        for (int j = 0; j < MAXD; j++) {
            dp[i][j] = INF;
        }
    }

    int s, d;
    cin >> d >> s;

    for (int i = 0; i < d; i++) {
        rv[(10 * i) % d].push_back(i);
    }

    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= d; j++) {
            dp[i][j] = INF;
        }
    }

    dp[s][0] = 0;
    queue<pair<int, int> > q;
    q.emplace(s, 0);
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int dg = 0; dg <= min(9, x); dg++) {
            int my = (y + 10 * d - dg) % d;
            for (int yy : rv[my]) {
                int xx = x - dg;
                if (dp[xx][yy] > dp[x][y] + 1) {
                    dp[xx][yy] = dp[x][y] + 1;
                    q.emplace(xx, yy);
                }
            }
        } 
    }

    if (dp[0][0] == INF) {
        cout << -1 << "\n";
    } else {
        int x = 0, y = 0;
        while (dp[x][y] != 0) {
            for (int i = 0; i <= 9; i++) {
                if (dp[x + i][(10 * y + i) % d] == dp[x][y] - 1) {
                    cout << i;
                    x += i;
                    y = (10 * y + i) % d;
                    break;
                }
            }
        }
        cout << "\n";
    }
	
    return 0;
}