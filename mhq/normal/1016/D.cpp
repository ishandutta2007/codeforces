#include<bits/stdc++.h>
using namespace std;
const int maxN = 105;
int n, m;
int a[maxN], b[maxN];
int ans[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int row = 0;
    int col = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        row ^= a[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> b[j];
        col ^= b[j];
    }
    if (row != col) {
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= (n - 1); i++) {
        for (int j = 1; j <= m - 1; j++) ans[i][j] = 0;
    }
    for (int i = 1; i <= n - 1; i++) ans[i][m] = a[i];
    for (int j = 1; j <= m - 1; j++) ans[n][j] = b[j];
    ans[n][m] = (a[n] ^ b[m] ^ row);
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}