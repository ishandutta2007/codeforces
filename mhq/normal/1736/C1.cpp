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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> bad;
        vector<int> when(n, n + 5);
        for (int i = 0; i < n; i++) {
            if (i >= a[i]) {
                when[i - a[i]] = min(when[i - a[i]], i - 1);
            }
        }
        int at_most = n - 1;
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            at_most = min(at_most, when[i]);
            ans += (at_most - i + 1);
        }
        cout << ans << '\n';

    }
    return 0;
}