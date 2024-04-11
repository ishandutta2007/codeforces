#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int p[maxN];
int f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        p[1] = 1;
        int sz = 1;
        ll ans = 0;
        p[1] = 1;
        for (int i = (n + 2) / 2; i <= n; i++) {
            p[++sz] = i;
            ans += (1LL * (i - 1) * (i - 1));
        }
        for (int i = (n + 2) / 2 - 1; i > 1; i--) {
            p[++sz] = i;
            ans += (1LL * (n - i)) * (n - i);
        }
        assert(sz == n);
        for (int i = 1; i <= n; i++) {
            f[p[i]] = p[i % n + 1];
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) cout << f[i] << " ";
        cout << '\n';
        cout << (n - 1) << '\n';
        for (int i = (n + 2) / 2; i < n; i++) {
            cout << i << " " << 1 << '\n';
        }
        for (int i = (n + 2) / 2 - 1; i >= 1; i--) {
            cout << i << " " << n << '\n';
        }
        cout << '\n';

    }
    return 0;
}