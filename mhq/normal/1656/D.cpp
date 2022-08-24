#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool check(ll n, ll k) {
    if (k < 2) return false;
    return (((2 * n) / k) >= k + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
       ll n;
       cin >> n;
       if (n % 2 == 1) {
           cout << 2 << '\n';
       }
       else {
           ll z = n;
           ll pw = 1;
           while (z % 2 == 0) {
               z /= 2;
               pw *= 2;
           }
           if (check(n, 2 * pw)) {
               cout << 2 * pw << '\n';
           }
           else if (check(n, z)) {
               cout << z << '\n';
           }
           else {
               cout << -1 << '\n';
           }


       }
    }
    return 0;
}