#ifndef BZ
#pragma GCC optimize -O3
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

int n;

bool ask(int xl, int yl, int xr, int yr) {
    if (xl > n || yr == 0) {
        return false;
    }

    cout << "? " << xl << " " << yl << " " << xr << " " << yr << endl;
    cout.flush();

    string s;
    cin >> s;
    assert(s == "YES" || s == "NO");

    return s[0] == 'Y';
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    cin >> n;
    string ans;
    int cx = 1, cy = 1;
    while (cx + cy <= n) {
        if (ask(cx + 1, cy, n, n)) {
            ++cx;
            ans += 'D';
        } else {
            ++cy;
            ans += 'R';
        }
    }

    string rans;

    int px = n, py = n;
    while (px + py > n + 1) {
        if (ask(1, 1, px, py - 1)) {
            --py;
            rans += 'R';
        } else {
            --px;
            rans += 'D';
        }
    }

    assert(px == cx && py == cy);

    cout << "! " << ans + string(rans.rbegin(), rans.rend()) << endl;
    cout.flush();

    return 0;
}