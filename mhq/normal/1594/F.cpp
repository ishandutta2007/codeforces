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
        ll s, n, k;
        cin >> s >> n >> k;
        if (s < k) {
            cout << "NO\n";
        }
        else if (s % k == 0) {
            if (s == k) {
                cout << "YES\n";
            }
            else {
                ll T = (s / k);
                ll z = (k - 1) * ((T + 1) / 2);
                z += (T / 2) + 1;
                if (z < (n + 1)) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
        else {
            ll cnt_big = (s % k) + 1;
            ll num_big = (s + k - 1) / k;
            ll cnt_small = k - cnt_big;
            ll num_small = s / k;
            ll z = cnt_big * ((num_big + 1) / 2) + cnt_small * ((num_small + 1) / 2);
            if (z < (n + 1)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}