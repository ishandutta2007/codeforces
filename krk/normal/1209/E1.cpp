#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 13;
const int Maxm = 2005;
const int Inf = 1000000000;

int T;
int n, m;
bool was[Maxm];
vector <ii> seq;
vector <int> spec;
int B[Maxn][Maxm];
int cur, dp[2][1 << Maxn][Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(was, was + Maxm, false);
        seq.clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                seq.push_back(ii(B[i][j], j));
            }
        sort(seq.rbegin(), seq.rend());
        spec.clear();
        for (int i = 0; i < seq.size() && spec.size() < n; i++) if (!was[seq[i].second]) {
            spec.push_back(seq[i].second);
            was[seq[i].second] = true;
        }
        for (int i = 0; i < 2; i++)
            for (int a = 0; a < 1 << n; a++)
                for (int b = 0; b < n; b++)
                    for (int c = 0; c < n; c++)
                        dp[i][a][b][c] = -Inf;
        for (int b = 0; b < n; b++)
            dp[cur][0][b][0] = 0;
        for (int i = 0; i < spec.size(); i++) {
            int col = spec[i];
            for (int a = 0; a < 1 << n; a++)
                for (int b = 0; b < n; b++)
                    for (int c = 0; c < n; c++) if (dp[cur][a][b][c] >= 0) {
                        int val = dp[cur][a][b][c]; dp[cur][a][b][c] = -Inf;
                        dp[cur][a][b][c + 1] = max(dp[cur][a][b][c + 1], val);
                        if (!(a & 1 << c)) {
                            val += B[(b + c) % n][col];
                            dp[cur][a | 1 << c][b][c + 1] = max(dp[cur][a | 1 << c][b][c + 1], val);
                        }
                    }
            for (int a = 0; a < 1 << n; a++)
                for (int b = 0; b < n; b++) if (dp[cur][a][b][n] >= 0) {
                    int val = dp[cur][a][b][n]; dp[cur][a][b][n] = -Inf;
                    for (int c = 0; c < n; c++)
                        dp[!cur][a][c][0] = max(dp[!cur][a][c][0], val);
                }
            cur = !cur;
        }
        printf("%d\n", dp[cur][(1 << n) - 1][0][0]);
    }
    return 0;
}