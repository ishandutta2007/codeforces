#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll tot = 0;
        ll mn_pref = 0;
        ll best = -1e18;
        cin >> n;
        vector < int > f;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tot += x;
            if (i != n) {
                best = max(best, tot - mn_pref);
                if (tot <= 0) ok = false;
            }
            mn_pref = min(mn_pref, tot);
        }
        if (best >= tot || !ok) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}