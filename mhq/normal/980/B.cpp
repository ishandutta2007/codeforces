#include <bits/stdc++.h>
using namespace std;
int n, k;
bool pos[10][150];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    if (k & 1) {
        pos[2][(n + 1) / 2] = true;
        k--;
        for (int i = (n + 1) / 2 - 1; i >= 2; i--) {
            if (k == 0) break;
            pos[2][i] = true;
            pos[2][(n + 1) - i] = true;
            k -= 2;
            if (k == 0) break;
            pos[3][i] = true;
            pos[3][n + 1 - i] = true;
            k -= 2;
        }
    }
    else {
        for (int i = 2; i <= (k / 2) + 1; i++) {
            pos[2][i] = true;
            pos[3][i] = true;
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
        if (pos[i][j]) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}