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
        int n;
        cin >> n;
        vector < int > f[2];
        for (int i = 1; i <= 2 * n; i++) {
            int x;
            cin >> x;
            f[x % 2].emplace_back(i);
        }
        if (f[0].size() % 2 == 1) {
            f[0].pop_back();
            f[1].pop_back();
        }
        else {
            if (!f[0].empty()) {
                f[0].pop_back();
                f[0].pop_back();
            }
            else {
                f[1].pop_back();
                f[1].pop_back();
            }
        }
        for (int a = 0; a < 2; a++) {
            for (int c = 0; c < f[a].size(); c += 2) {
                cout << f[a][c] << " " << f[a][c + 1] << '\n';
            }
        }

    }
    return 0;
}