#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int val[18][18];
const int maxP = (1 << 18) + 2;
int cost[maxP];
bool good_add[maxP];
bool good_mask[maxP];
int prv[maxP];
int dp[maxP];
const int INF = 1e9;
int a[18];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        val[x][y] = w;
    }
    for (int i = 0; i < (1 << n); i++) {
        good_mask[i] = true;
        good_add[i] = true;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int p = 0; p < n; p++) {
                    if (val[j][p]) {
                        if (!(i & (1 << p))) {
                            cost[i] += val[j][p];
                        }
                        else {
                            good_add[i] = false;
                        }
                    }
                    if (val[p][j]) {
                        if (!(i & (1 << p))) {
                            good_mask[i] = false;
                        }
                    }
                }
            }
        }
    }
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        dp[i] = INF;
        if (!good_mask[i]) {
            continue;
        }
        for (int sb = i; sb > 0; sb = i & (sb - 1)) {
            if (good_add[sb]) {
                if (dp[i] > dp[i ^ sb] + cost[i ^ sb]) {
                    dp[i] = dp[i ^ sb] + cost[i ^ sb];
                    prv[i] = i ^ sb;
                }
            }
        }
    }
    assert(dp[(1 << n) - 1] < INF);
    int cur = (1 << n) - 1;
    int st = 1;
    while (cur != 0) {
        int p = prv[cur];
        int lft = cur ^ p;
        for (int j = 0; j < n; j++) {
            if (lft & (1 << j)) {
                a[j] = st;
            }
        }
        cur = p;
        st++;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}