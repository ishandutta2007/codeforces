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
        int mn = 9;
        int n;
        cin >> n;
        if (n < 100) {
            cout << n % 10 << '\n';
        }
        else {
            while (n) {
                mn = min(mn, n % 10);
                n /= 10;
            }
            cout << mn << '\n';
        }
    }
    return 0;
}