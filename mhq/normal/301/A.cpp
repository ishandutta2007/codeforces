#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e3 + 10;
int a[maxN];
int ch[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 2 * n - 1; i++) {
        cin >> a[i];
    }
    if (n % 2 == 1) {
        ll ans = 0;
        for (int i = 1; i <= 2 * n - 1; i++) ans += abs(a[i]);
        cout << ans;
    }
    else {
        ll st = 0;
        for (int i = 1; i <= 2 * n - 1; i++) {
            ch[i] = -2 * a[i];
            st += a[i];
        }
        sort(ch + 1, ch + (2 * n  - 1) + 1);
        reverse(ch +  1, ch + (2 * n  - 1) + 1);
        ll best = 0;
        for (int sz = 0; sz <= 2 * n - 1; sz += 2) {
            ll cur = 0;
            for (int p = 1; p <= sz; p++) cur += ch[p];
            best = max(best, cur);
        }
        cout << st + best;
    }
    return 0;
}