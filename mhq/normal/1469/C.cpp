#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int h[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        int prvL = h[1];
        int prvR = h[1];
        for (int i = 2; i <= n; i++) {
            int aL = h[i];
            int aR = h[i] + k - 1;
            aL = max(aL, prvL - (k - 1));
            aR = min(aR, prvR + (k - 1));
            if (aL > aR) {
                ok = false;
                break;
            }
            prvL = aL;
            prvR = aR;
        }
        if (ok && prvL == h[n]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}