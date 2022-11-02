#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int MAXM = 10010;

int n, m;
int sze[MAXN], val[MAXN][MAXN], sum[MAXN], pre[MAXN][MAXN];
int dp[MAXM], best[MAXN];

void setmax(int& a, int b) { if (a < b) a = b; }

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> sze[i];
        for (int j=0; j<sze[i]; j++) {
            cin >> val[i][j];
            sum[i] += val[i][j];
            pre[i][j+1] = pre[i][j] + val[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        memset(best, 0, sizeof(best));
        for (int j=0; j<sze[i]; j++)
            for (int k=j; k<=sze[i]; k++)
                setmax(best[sze[i] - k + j], sum[i] - pre[i][k] + pre[i][j]);

        for (int j=m; j>=0; j--)
            for (int k=1; k<=sze[i]; k++) {
                int j1 = j + k;
                if (j1 <= m)
                    setmax(dp[j1], dp[j] + best[k]);
            }
    }

    cout << dp[m] << '\n';
    return 0;
}