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
    const ld pi = acos(-1.0);
    while (tst--) {
        int n;
        cin >> n;
        ld l = 0;
        ld r = (2 * pi) / (2 * n);
        ld R = 1 / (2 * sin(pi / (2 * n)));
        ld ang = pi / n;
        auto calc =[&](ld shift) {
            ld mnX = 1e18;
            ld mxX = -1e18;
            ld mxY = -1e18;
            ld mnY = 1e18;
            for (int i = 0; i < 2 * n; i++) {
                ld x = R * sin(ang * i + shift);
                ld y = R * cos(ang * i + shift);
                mnX = min(mnX, x);
                mnY = min(mnY, y);
                mxX = max(mxX, x);
                mxY = max(mxY, y);
            }
            return max(mxX - mnX, mxY - mnY);
        };
        for (int iter = 0; iter < 100; iter++) {
            ld l1 = (2 * l + r) / 3;
            ld r1 = (2 * r + l) / 3;
            if (calc(l1) < calc(r1)) r = r1;
            else l = l1;
        }
        cout << fixed << setprecision(10) << (calc((l + r) / 2)) << '\n';
    }
    return 0;
}