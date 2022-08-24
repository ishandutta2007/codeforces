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
        vector<int> a, b;
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            x = abs(x);
            y = abs(y);
            if (x == 0) {
                a.emplace_back(y);
            }
            else {
                b.emplace_back(x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ld tot = 0;
        for (int i = 0; i < n; i++) {
            tot += sqrt(1LL * a[i] * a[i] + 1LL * b[i] * b[i]);
        }
        cout << fixed << setprecision(12) << tot << '\n';
    }
    return 0;
}