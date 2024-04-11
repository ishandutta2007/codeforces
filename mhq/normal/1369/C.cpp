#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n);
        for (int& v : a) cin >> v;
        ll ans = 0;
        sort(a.begin(), a.end());
        vector < int > w(k);
        int cnt = 0;
        for (int& v : w) {
            cin >> v;
            if (v == 1) cnt++;
        }
        sort(w.begin(), w.end());
        reverse(a.begin(), a.end());
        for (int i = 0; i < k; i++) {
            ans += a[i];
            if (cnt > 0) {
                ans += a[i];
                cnt--;
            }
        }
        int from = k;
        for (int i = 0; i < k; i++) {
            if (w[i] == 1) continue;
            ans += a[from + w[i] - 2];
            from += w[i] - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}