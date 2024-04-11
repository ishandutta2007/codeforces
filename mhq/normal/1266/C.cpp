#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int lcm(int a, int b) {
    return (a * b) / (__gcd(a, b));
}
int row[505], col[505];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int r, c;
    cin >> r >> c;
    if (r > 1) {
        for (int i = 1; i <= c; i++) {
            col[i] = i;
        }
        for (int i = 1; i <= r; i++) row[i] = i + c;
    }
    else if (c > 1) {
        for (int i = 1; i <= r; i++) {
            row[i] = i;
        }
        for (int i = 1; i <= c; i++) col[i] = i + r;
    }
    else {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << lcm(row[i], col[j]) << " ";
        }
        cout << '\n';
    }
    return 0;
}