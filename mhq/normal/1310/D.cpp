#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 85;
int a[maxN][maxN];
int n, k;
int SZ;
int lst[15];
bool used[maxN];
const int INF = (int)1e9 + 10;
int best = INF;
const int maxK = 7;
int dp[maxK][maxK];
int val[maxK][maxK];
vector < pair < int, int > > all[maxN][maxN];
void solve() {
    if (SZ == n) return;
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            val[i][j] = INF;
            for (int p = 0; p < all[lst[i]][lst[j]].size(); p++) {
                if (!used[all[lst[i]][lst[j]][p].second]) {
                    val[i][j] = all[lst[i]][lst[j]][p].first;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= k / 2; i++) {
        for (int j = 0; j < SZ; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int step = 0; step < k / 2; step++) {
        for (int a = 0; a < SZ; a++) {
            for (int b = 0; b < SZ; b++) {
                dp[step + 1][b] = min(dp[step + 1][b], dp[step][a] + val[a][b]);
            }
        }
    }
    best = min(best, dp[k / 2][0]);
    // cout << dp[k / 2][0] << '\n';
}
void rec(int v) {
    if (v == n + 1) {
        solve();
        return;
    }
    rec(v + 1);
    if (SZ + 1 <= k / 2) {
        lst[SZ] = v;
        used[v] = true;
        SZ++;
        rec(v + 1);
        used[v] = false;
        SZ--;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    //n = 80;
    //k = 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            //a[i][j] = (i != j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k) continue;
                all[i][j].emplace_back(a[i][k] + a[k][j], k);
            }
            sort(all[i][j].begin(), all[i][j].end());
        }
    }
    used[1] = true;
    lst[0] = 1;
    SZ = 1;
    rec(2);
    cout << best;
    return 0;
}