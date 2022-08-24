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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int x = -1, y = -1;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            auto f1 = a[i];
            sort(f1.begin(), f1.end());
            vector<int> cnt;
            for (int j = 0; j < m; j++) {
                if (a[i][j] != f1[j]) {
                    cnt.emplace_back(j);
                }
            }
            if (cnt.size() > 2) {
                ok = false;
                break;
            }
            if (cnt.size() == 2) {
                x = cnt[0];
                y = cnt[1];
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
        else {
            if (x == -1) {
                x = y = 0;
            }
            vector<vector<int>> b = a;
            for (int j = 0; j < n; j++) {
                swap(b[j][x], b[j][y]);
            }
            ok = true;
            for (int i = 0; i < n; i++) {
                auto f1 = b[i];
                sort(f1.begin(), f1.end());
                if (b[i] != f1) {
                    ok = false;
                }
            }
            if (ok) {
                cout << x + 1 << " " << y + 1 << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}