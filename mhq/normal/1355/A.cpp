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
        ll a;
        ll k;
        cin >> a >> k;
        k--;
        while (k > 0) {
            string f = to_string(a);
            int mn = 9;
            int mx = 0;
            for (char& c : f) {
                mn = min(mn, c - '0');
                mx = max(mx, c - '0');
            }
            if (mn == 0) break;
            a += mn * mx;
            k--;
        }
        cout << a << '\n';
    }
    return 0;
}