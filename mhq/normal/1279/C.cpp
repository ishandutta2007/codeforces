#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int a[maxN];
int b[maxN];
int n;
int pos[maxN];
int m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int mx_pos = 0;
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            if (pos[b[i]] > mx_pos) {
                mx_pos = pos[b[i]];
                ans += 2 * (mx_pos - i + 1) - 1;
            }
            else {
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}