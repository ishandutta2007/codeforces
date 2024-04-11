#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 75;
ll a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int best = n - 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int cnt = 0;
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if ((a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i)) cnt++;
                }
                best = min(best, cnt);
            }
        }
        cout << best << '\n';
    }
    return 0;
}