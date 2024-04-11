#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int b[105];
bool used[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    used[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            used[i][j] |= used[i - 1][j];
            if (j >= a[i] && j <= b[i] && used[i][j]) {
                for (int k = a[i]; k <= b[i]; k++) {
                    used[i][k] = true;
                }
            }
        }
    }
    if (used[n][m]) cout << "YES";
    else cout << "NO";
    return 0;
}