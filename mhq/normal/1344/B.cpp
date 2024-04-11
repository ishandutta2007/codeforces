#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxN = 1005;
char c[maxN][maxN];
int n, m;
int degR[maxN], degC[maxN];
int mnR[maxN], mnC[maxN];
int mxR[maxN], mxC[maxN];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool used[maxN][maxN];
void dfs(int i, int j) {
    used[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 1 || ni > n || nj < 1 || nj > m || c[ni][nj] == '.' || used[ni][nj]) continue;
        dfs(ni, nj);
    }
}
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mnR[i] = m + 1;
    }
    for (int i = 1; i <= m; i++) {
        mnC[i] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == '#') {
                degR[i]++;
                degC[j]++;
                mxR[i] = max(mxR[i], j);
                mxC[j] = max(mxC[j], i);
                mnC[j] = min(mnC[j], i);
                mnR[i] = min(mnR[i], j);
            }
        }
    }
    bool hasA = false;
    bool hasB = false;
    for (int i = 1; i <= n; i++) {
        hasA |= (degR[i] == 0);
    }
    for (int i = 1; i <= m; i++) {
        hasB |= (degC[i] == 0);
    }
    if (hasA != hasB) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (degR[i]) {
            if (degR[i] != mxR[i] - mnR[i] + 1) {
                cout << -1;
                return 0;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (degC[i]) {
            if (degC[i] != mxC[i] - mnC[i] + 1) {
                cout << -1;
                return 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!used[i][j] && c[i][j] == '#') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;

    return 0;
}