#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e3 + 3;

int n, a[N][N], dp[N][N], b[N][N], from[N][N];
int v1 = 0;
string p1 = "";

void go(int x, int y) {
    if (from[x][y] == 0)
        return;
    if (from[x][y] == 1)
        go(x - 1, y), p1 += 'D';
    else
        go(x, y - 1), p1 += 'R';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int p2 = -1, pi1 = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                pi1 = i, p2 = j, b[i][j] = 1e9;
            else
                while (a[i][j] % 2 == 0)
                    a[i][j] /= 2, b[i][j]++;
        }
    dp[1][1] = b[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + b[i][1];
        from[i][1] = 1;
        dp[1][i] = dp[1][i - 1] + b[1][i];
        from[1][i] = 2;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            if (dp[i - 1][j] < dp[i][j - 1])
                dp[i][j] = dp[i - 1][j] + b[i][j], from[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + b[i][j], from[i][j] = 2;
    go(n, n);
    v1 = dp[n][n];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            b[i][j] = 0;
            if (a[i][j] == 0)
                b[i][j] = 1e9 + 9;
            else
            while (a[i][j] % 5 == 0)
                a[i][j] /= 5, b[i][j]++;
        }
    dp[1][1] = b[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + b[i][1];
        from[i][1] = 1;
        dp[1][i] = dp[1][i - 1] + b[1][i];
        from[1][i] = 2;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            if (dp[i - 1][j] < dp[i][j - 1])
                dp[i][j] = dp[i - 1][j] + b[i][j], from[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + b[i][j], from[i][j] = 2;
    if (dp[n][n] < v1) {
        p1.clear();
        go(n, n);
        v1 = dp[n][n];
    }
    if (v1 > 1 && p2 != -1) {
        cout << "1\n";
        for (int i = 1; i < p2; i++)
            cout << "R";
        for (int j = 1; j < pi1; j++)
            cout << "D";
        for (int i = p2; i < n; i++)
            cout << "R";
        for (int i = pi1; i < n; i++)
            cout << "D";
    } else {
        cout << v1 << "\n" << p1;
    }
    return 0;
}