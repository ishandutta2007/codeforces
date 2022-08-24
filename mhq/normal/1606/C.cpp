#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll pw10[15];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    pw10[0] = 1;
    for (int i = 1; i < 15; i++) pw10[i] = 10 * pw10[i - 1];
    int tst;
    cin >> tst;
    while (tst--) {
        int n; ll k;
        cin >> n >> k;
        k++;
        vector<int> who(n);
        for (int i = 0; i < n; i++) {
            cin >> who[i];
        }
        ll ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            ll need = min(pw10[who[i + 1]] / pw10[who[i]] - 1, k);
            k -= need;
            ans += pw10[who[i]] * need;
        }
        if (k > 0) {
            ans += k * pw10[who.back()];
        }
        cout << ans << '\n';

    }
    return 0;
}