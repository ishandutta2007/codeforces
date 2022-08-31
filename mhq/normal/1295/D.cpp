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
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll a, m;
        cin >> a >> m;
        ll d = __gcd(a, m);
        a /= d;
        m /= d;
        ll phi = 1;
        for (int i = 2; 1LL * i * i <= m; i++) {
            if (m % i == 0) {
                phi *= (i - 1);
                m /= i;
                while (m % i == 0) {
                    phi *= i;
                    m /= i;
                }
            }
        }
        if (m > 1) phi *= m - 1;
        cout << phi << '\n';
    }
    return 0;
}