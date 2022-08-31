#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    ll dx1, dy1, dx2, dy2;
    cin >> n;
    cin >> dx1 >> dy1 >> dx2 >> dy2;
    if (dx1 * dy2 == dx2 * dy1) {
        cout << "NO\n";
        return 0;
    }
    ll d1 = __gcd(abs(dx1), abs(dx2));
    ll d2 = __gcd(abs(dy1), abs(dy2));
    if (n % (d1 * d2) != 0) {
        cout << "NO\n";
        return 0;
    }
    n /= d1;
    n /= d2;
    dx1 /= d1; dx2 /= d1;
    dy1 /= d2; dy2 /= d2;
    ll D = abs(dx1 * dy2 - dx2 * dy1);
    if (D != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d1; j++) {
            for (int k = 0; k < d2; k++) {
                cout << j << " " << i * d2 + k << '\n';
            }
        }
    }

    return 0;
}