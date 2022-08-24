#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n;
ll a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        ll tot = 0;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 2; i <= n - 1; i++) {
            tot += (a[i] + 1) / 2;
            ok |= (a[i] >= 2);
        }

        if (!ok || (n == 3 && a[2] % 2 != 0)) cout << -1 << '\n';
        else cout << tot << '\n';
    }
    return 0;
}