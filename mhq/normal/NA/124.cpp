#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (a < c || b < c) {
        cout << -1;
        return 0;
    }
    int all = a + b - c;
    if (all >= n) {
        cout << -1;
        return 0;
    }
    cout << n - all;
    return 0;
}