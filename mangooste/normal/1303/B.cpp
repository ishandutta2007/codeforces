#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using ll = long long;
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, g, b;
        cin >> n >> g >> b;
        ll need = (n + 1) / 2;
        ll res = 0;
        if (need <= g) {
            res = need;
            if (res < n) {
                res += n - res;
            }
        } else if (need % g == 0) {
            ll num = need / g - 1;
            res += num * (g + b);
            res += g;
            if (res < n) {
                res += n - res;
            }
        } else {
            ll num = need / g;
            res += num * (g + b);
            res += need % g;
            if (res < n) {
                res += n - res;
            }
        }
        cout << res << '\n';
    }
}