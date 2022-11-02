#include<bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
constexpr int mod = 998244353;
using LL = long long;
int n, m;
int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= m; j += 1)
                a[i][j] = 0;
        }
        a[1][1] = a[1][m] = a[n][1] = a[n][m] = 1;
        for (int i = 3; i < m - 1; i += 2) {
            a[1][i] = 1;
            a[n][i] = 1;
        }
        for (int i = 3; i < n - 1; i += 2) {
            a[i][1] = 1;
            a[i][m] = 1;
        }
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= m; j += 1)
                cout << a[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}
/*

*/