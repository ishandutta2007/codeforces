#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
ll a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        ll k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll len = min(k, (ll)n);
        ll add = ((2 * k - len - 1) * len) / 2;
        ll best = 0;
        ll cur = 0;
        for (int i = 1; i <= len ;i++) {
            cur += a[i];
        }
        best = cur;
        for (int i = len + 1; i <= n; i++) {
            cur += a[i];
            cur -= a[i - len];
            best = max(best, cur);
        }
        cout << best + add << '\n';
    }
    return 0;
}