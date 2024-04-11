#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = 1000 * 1000 * 1000;
const int N = 88;

int dp[N][N][N][N];
vector<int> g[N];
vector<int> w[N];
int res = INF;

int calc(int l, int r, int k, int pos) {
    if (dp[l][r][k][pos] != -1)
        return dp[l][r][k][pos]; 
    if (k == 0) {
        return dp[l][r][k][pos] = 0;
    }
    dp[l][r][k][pos] = INF;
    for (int i = 0; i < (int)g[pos].size(); i++) {
        int to = g[pos][i];
        int len = w[pos][i];
        if (to <= l || to >= r || to == pos)
            continue;
        if (to > pos)
            dp[l][r][k][pos] = min(dp[l][r][k][pos], calc(pos, r, k - 1, to) + len);
        else
            dp[l][r][k][pos] = min(dp[l][r][k][pos], calc(l, pos, k - 1, to) + len);
    }
    return dp[l][r][k][pos];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].push_back(b);
        w[a].push_back(l);
    }
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            for (int t = 0; t <= k; t++)
                for (int p = 0; p <= n + 1; p++)
                    dp[i][j][t][p] = dp[i][j][t][p] = -1;
    for (int i = 1; i <= n; i++)
        res = min(res, calc(0, n + 1, k - 1, i));
    if (res == INF)
        res = -1;
    cout << res << endl;
}