#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int ans = 720720, u;
            cin >> u;
            if ((i + j) % 2 == 1) {
                ans -= pow(u, 4);
            }
            cout << ans << " \n"[j == n];
        }
    }
}