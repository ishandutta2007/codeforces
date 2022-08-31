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
        int m;
        cin >> m;
        vector<vector<int>> a(2, vector<int>(m));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        a[0][0] -= 1;
        vector<int> v1(m);
        vector<int> v2(m);
        v1[m - 1] = max(a[0][m - 1] + 1, a[1][m - 1]);
        v2[m - 1] = max(a[1][m - 1] + 1, a[0][m - 1]);
        for (int i = m - 2; i >= 0; i--) {
            v1[i] = max({v1[i + 1] + 1, a[1][i], a[0][i] + 2 * (m - 1 - i) + 1});
            v2[i] = max({v2[i + 1] + 1, a[0][i], a[1][i] + 2 * (m - 1 - i) + 1});
        }
        int best = 2e9;
        int cur_mx = 0;
        for (int i = 0; i < m; i++) {
//            cout << i << " " << v1[0] << endl;
            if (i % 2 == 0) {
                best = min(best, max(v1[i], cur_mx));
                cur_mx = max(cur_mx, a[0][i] + 2 * (m - 1 - i) + 1);
                cur_mx = max(cur_mx, a[1][i] + 2 * (m - 1 - i));
//                cout << " HI " << cur_mx << " " << best << endl;
                if (i + 1 < m) {
                    best = min(best, max(v2[i + 1], cur_mx));
                }
                else {
                    best = min(best, cur_mx);
                }
            }
            else {
                best = min(best, max(v2[i], cur_mx));
                cur_mx = max(cur_mx, a[1][i] + 2 * (m - 1 - i) + 1);
                cur_mx = max(cur_mx, a[0][i] + 2 * (m - 1 - i));
                if (i + 1 < m) {
                    best = min(best, max(v1[i + 1], cur_mx));
                }
                else {
                    best = min(best, cur_mx);
                }
            }
        }
        cout << best + 1 << '\n';
    }
    return 0;
}