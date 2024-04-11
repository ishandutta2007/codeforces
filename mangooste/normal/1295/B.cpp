#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll k;
        cin >> n >> k;
        vector <ll> bal(n);
        for (int i = 0; i < n; i++) {
            bal[i] = (i == 0 ? 0 : bal[i - 1]);
            char cur;
            cin >> cur;
            bal[i] += (cur == '0' ? 1 : -1);
        }
        ll res = (ll)(k == 0);
        for (int i = 0; i < n; i++) {
            ll cur = bal[i];
            ll del = bal.back();
            if (cur == k && del == 0) {
                res = -1;
                break;
            }
            if (del != 0 && (k - cur) * del >= 0 && abs(k - cur) % del == 0) {
                res++;
            }
        }
        cout << res << '\n';
    }
}