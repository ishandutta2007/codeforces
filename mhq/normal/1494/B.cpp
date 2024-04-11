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
    while(tst--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool ok = false;
        for (int mask = 0; mask < 16; mask++) {
            int cu = u;
            int cr = r;
            int cl = l;
            int cd = d;
            for (int x = 0; x < 4; x++) {
                if (mask & (1 << x)) {
                    if (x == 0) {
                        cu--;
                        cr--;
                    }
                    else if (x == 1) {
                        cu--;
                        cl--;
                    }
                    else if (x == 2) {
                        cd--;
                        cr--;
                    }
                    else {
                        cd--;
                        cl--;
                    }
                }
            }
            if (cu < 0 || cr < 0 || cl < 0 || cd < 0) continue;
            if (cu > (n - 2) || cr > (n - 2) || cl > (n - 2) || cd > (n - 2)) continue;
            ok = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}