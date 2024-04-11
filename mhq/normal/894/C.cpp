#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) b %= a;
        else a %= b;
    }
    return a + b;
}
int m;
int a[1005];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int curgcd = a[1];
    for (int i = 1; i <= m; i++) {
        curgcd = gcd(curgcd, a[i]);
    }
    bool ok = false;
    for (int i = 1; i <= m; i++) {
        if (a[i] == curgcd) ok = true;
    }
    if (ok == false) {
        cout << -1;
        return 0;
    }
    cout << 2 * m << '\n';
    for (int i = 1; i <= 2 * m; i++) {
        if (i % 2 == 1) cout << curgcd << " ";
        else cout << a[i / 2] << " ";
    }
    return 0;
}