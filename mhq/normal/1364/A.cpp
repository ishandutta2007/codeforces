#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, x;
const int maxN = 1e5 + 10;
int pref[maxN];
void solve() {
    cin >> n >> x;
    bool has = false;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        c %= x;
        has |= (c > 0);
        pref[i] = (pref[i - 1] + c) % x;
    }
    if (!has) {
        cout << -1 << '\n';
        return;
    }
    if (pref[n] != 0) {
        cout << n << '\n';
    }
    else {
        int l = 0;
        while (pref[l] == 0) l++;
        int best = n - l;
        int r = n;
        while (pref[r] == 0) r--;
        best = max(best, r);
        cout << best << '\n';
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