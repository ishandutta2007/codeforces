#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int a[4][4] = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};
int ans[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n / 4; i++) {
        for (int j = 0; j < n / 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int p = 0; p < 4; p++) {
                    ans[i * 4 + k][j * 4 + p] = a[k][p] + 16 * i + 16 * j * (n / 4);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}