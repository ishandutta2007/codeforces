#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[305][305];
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int nbr(int x, int y) {
    int ans = 0;
    if (x > 1) ++ans;
    if (x < n) ++ans;
    if (y > 1) ++ans;
    if (y < m) ++ans;
    return ans;
}
bool out(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}
int cnt(int x, int y) {
    int ans = 0;
    for (int t = 0; t < 4; ++t) {
        int nx = x + dx[t], ny = y + dy[t];
        if (!out(nx, ny)) ans += !!a[nx][ny];
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
        int bad = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (a[i][j] > nbr(i, j)) bad = 1;
        if (bad) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << nbr(i, j) << ' ';
            cout << endl;
        }
    }
    return 0;
}