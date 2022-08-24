#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e5 + 10;
int a[maxN];
void solve() {
    cin >> n;
    int xr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xr ^= a[i];
    }
    if (xr == 0) {
        cout << "DRAW\n";
    }
    else {
        int lrg = -1;
        for (int i = 30; i >= 0; i--) {
            if (xr & (1 << i)) {
                lrg = i;
                break;
            }
        }
        assert(lrg != -1);
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] & (1 << lrg)) {
                x++;
            }
            else {
                y++;
            }
        }
        y %= 2;
        if (y == 0) {
            cout << (((x + 1) / 2) % 2 == 1 ? "WIN" : "LOSE") << '\n';
        }
        else {
            cout << "WIN\n";
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}