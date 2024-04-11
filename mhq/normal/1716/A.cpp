#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        ll n;
        cin >> n;
        ll best = 1e18;
        for (int cnt = -10; cnt <= 10; cnt++) {
            if ((n - 2 * cnt) % 3 == 0) {
                best = min(best, abs(cnt) + abs((n - 2 * cnt) / 3));
            }
        }
        cout << best << '\n';
    }
    return 0;
}