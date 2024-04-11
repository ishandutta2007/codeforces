#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
const int maxN = 35;
const int maxK = 205;
ld dp[maxN][maxN][maxK];
int p[maxN];
int n, k;
vector < pair < int, int > > trans[maxN][maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (j > i) dp[i][j][0] = 1;
            else dp[i][j][0] = 0;
            for (int l = 1; l <= n; l++) {
                for (int r = l; r <= n; r++) {
                    int ni = i;
                    if (ni >= l && ni <= r) ni = l + r - ni;
                    int nj = j;
                    if (nj >= l && nj <= r) nj = l + r - nj;
                    trans[i][j].emplace_back(ni, nj);
                }
            }
        }
    }
    for (int step = 1; step <= k; step++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                for (auto t : trans[i][j]) {
                    dp[i][j][step] += dp[t.first][t.second][step - 1];
                }
                dp[i][j][step] /= trans[i][j].size();
            }
        }
    }
    ld ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i] < p[j]) ans += (1.0 - dp[i][j][k]);
            else ans += dp[i][j][k];
        }
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}