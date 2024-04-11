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
        int n, al, ar;
        cin >> n >> al >> ar;
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (i <= al) l[a]++;
            else r[a]++;
        }
        int ans = 0;
        int fl = 0;
        int fr = 0;
        for (int i = 1; i <= n; i++) {
            int d = min(l[i], r[i]);
            l[i] -= d;
            r[i] -= d;
            fl += l[i];
            fr += r[i];
        }
        ans = abs(fr - fl) / 2;
        int c = 0;
        if (fl > fr) swap(l, r);
        for (int i = 1; i <= n; i++) {
            if (r[i] > 0) {
                c += r[i] / 2;
            }
        }
        c = min(c, abs(fr - fl) / 2);
        ans += (fr + fl) / 2 - c;
        cout << ans << '\n';
    }
    return 0;
}