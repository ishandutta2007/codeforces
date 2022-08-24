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
        ll n;
        cin >> n;
        while (true) {
            ll s = 0;
            ll ns = n;
            while (ns) {
                s += (ns % 10);
                ns /= 10;
            }
            if (__gcd(s, n) > 1) {
                cout << n << '\n';
                break;
            }
            n++;
        }
    }
    return 0;
}