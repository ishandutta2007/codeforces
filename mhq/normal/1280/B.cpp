#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int x;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
char a[65][65];
int r, c;
void solve() {
    cin >> r >> c;
    int cntA = 0, cntP = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') cntA++;
            else cntP++;
        }
    }
    if (cntA == 0) {
        cout << "MORTAL\n";
        return ;
    }
    if (cntP == 0) {
        cout << "0\n";
        return ;
    }
    for (int v : {0, r - 1}) {
        bool ok = true;
        for (int j = 0; j < c; j++) {
            if (a[v][j] != 'A') ok = false;
        }
        if (ok) {
            cout << "1\n";
            return;
        }
    }
    for (int v : {0, c - 1}) {
        bool ok = true;
        for (int j = 0; j < r; j++) {
            if (a[j][v] != 'A') ok = false;
        }
        if (ok) {
            cout << "1\n";
            return;
        }
    }
    for (int v : {0, r - 1}) {
        for (int u : {0, c - 1}) {
            if (a[v][u] == 'A') {
                cout << "2\n";
                return;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        bool ok = true;
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 'A') ok = false;
        }
        if (ok) {
            cout << "2\n";
            return;
        }
    }

    for (int i = 0; i < c; i++) {
        bool ok = true;
        for (int j = 0; j < r; j++) {
            if (a[j][i] != 'A') ok = false;
        }
        if (ok) {
            cout << "2\n";
            return;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 'A' && (i == 0 || i == r - 1 || j == 0 || j == c - 1)) {
                cout << "3\n";
                return;
            }
        }
    }
    cout << "4\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}