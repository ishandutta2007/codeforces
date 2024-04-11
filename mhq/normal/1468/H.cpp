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
        int n, k, m;
        cin >> n >> k >> m;
        vector<bool> good(n + 1, false);
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            good[x] = true;
        }
        if ((n - m) % (k - 1) != 0) {
            cout << "NO\n";
        }
        else {
            vector<int> f;
            for (int i = 1; i <= n; i++) {
                if (!good[i]) f.emplace_back(i);
            }
            int D = (k - 1) / 2;
            int c1 = f[D - 1];
            int c2 = f[f.size() - D];
            bool can = false;
            for (int i = 1; i <= n; i++) {
                if (good[i] && c1 <= i && i <= c2) {
                    can = true;
                }
            }
            if (can) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}