#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

ll a = 15654;
char ask(ll x, ll y) {
#ifdef DEBUG
    if (x % a >= y % a)
        return 'x';
    else
        return 'y';
#else
    cout << "? " << x << ' ' << y << endl;
    char res;
    cin >> res;
    return res;
#endif
}

void solve() {
    while (true) {
        string state;
        cin >> state;
        if (state == "end")
            break;
        ll l = 1, r = 1;
        for (int i = 0; i < 30; i++) {
            ll x = 1LL << (i + 1);
            ll y = 1LL << i;
            char res = ask(x, y);
            if (res == 'y') {
                l = y + 1;
                r = x;
                break;
            }
        }
        ll top = r;
        while (r > l) {
            ll mid = (l + r) / 2;
            char res = ask(mid, top);
            if (res == 'y') {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << "! " << l << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}