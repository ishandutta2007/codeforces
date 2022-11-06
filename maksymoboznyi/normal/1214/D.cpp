#include <bits/stdc++.h>

using namespace std;

int n, m, M = 1e9 + 9;
vector<vector<char> > a;
vector<vector<int> > is, b, k1, k2;

bool check(int x, int y) {
    return x > 0 && y > 0 && a[x][y] == '.' && !is[x][y];
}

void dfs(int x, int y) {
    is[x][y] = 1;
    if (check(x - 1, y))
        dfs(x - 1, y);
    if (check(x, y - 1))
        dfs(x, y - 1);
}

int main()
{
    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    is.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dfs(n, m);
    if (!is[1][1]) {
        cout << 0;
        return 0;
    }
    if (n == 1 || m == 1) {
        cout << 1;
        return 0;
    }
    int kol = (a[1][2]== '.') + (a[2][1] == '.');
    if (kol == 1) {
        cout << 1;
        return 0;
    }
    kol = (a[n - 1][m] == '.') + (a[n][m - 1] == '.');
    if (kol == 1) {
        cout << 1;
        return 0;
    }
    k1.resize(n + 2, vector<int>(m + 2));
    k2.resize(n + 2, vector<int>(m + 2));
    b.resize(n + 2, vector<int>(m + 2));
    k1[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i + j != 2 && a[i][j] == '.')
                k1[i][j] = (k1[i - 1][j] + k1[i][j - 1]) % M;
    k2[n][m] = 1;
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            if (i + j != n + m && a[i][j] == '.')
                k2[i][j] = (k2[i + 1][j] + k2[i][j + 1]) % M;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i + j != 2 && i + j != n + m && k1[n][m] == 1ll * k1[i][j] * k2[i][j] % M)
                b[i][j]++;
    M = 1702824723;
    k1[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i + j != 2 && a[i][j] == '.')
                k1[i][j] = (1ll * k1[i - 1][j] + k1[i][j - 1]) % M;
    k2[n][m] = 1;
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            if (i + j != n + m && a[i][j] == '.')
                k2[i][j] = (1ll * k2[i + 1][j] + k2[i][j + 1]) % M;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i + j != 2 && i + j != n + m && k1[n][m] == 1ll * k1[i][j] * k2[i][j] % M && b[i][j] == 1) {
                cout << 1;
                return 0;
            }
    cout << 2;
    return 0;
}