#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 4e5 + 10;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = a[n + 1] = 0;
        for (int i = 0; i <= n; i ++) ans += abs(a[i + 1] - a[i]);
        for (int i = 1; i <= n; i++) {
            if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
                ans -= (a[i] - max(a[i - 1], a[i + 1]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}