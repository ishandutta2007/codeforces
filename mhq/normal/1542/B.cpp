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
    int tst;
    cin >> tst;
    while (tst--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if (1 % b == n % b) {
            cout << "YES\n";
        }
        else {
            bool ok = false;
            if (a > 1) {
                ll z = 1;
                while (z <= n) {
                    z *= a;
                    if (z > n) break;
                    if (z % b == n % b) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}