#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

inline void upd(int &x, int y)  {
    if (x < y) {
        x = y;
    }
}

const int N = 1e6 + 5;

int n, m;
int dp[N][3][3];
int cnt[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for (int x, i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    fill((int*)dp, (int*)dp + N * 3 * 3, -inf);

    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (x + y > cnt[i]) continue;
                int tmp = cnt[i];
                tmp -= x;
                tmp -= y;
                for (int c = 0; c < 3 && c <= tmp; c++) {
                    int hlp = dp[i - 1][x][y];
                    hlp += x;
                    hlp += (tmp - c) / 3;
                    upd(dp[i][y][c], hlp);
                }
            }
        }
    }

    int res = 0;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            upd(res, dp[m][x][y]);
        }
    }

    printf("%d\n", res);

    return 0;
}