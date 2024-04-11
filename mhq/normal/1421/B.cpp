#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int c[228][228];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char cc;
                cin >> cc;
                c[i][j] = cc - '0';
            }
        }
        int f = 0;
        if (c[0][1] == c[1][0]) f = c[0][1];
        else if (c[n - 2][n - 1] == c[n - 1][n - 2]) f = c[n - 2][n - 1] ^ 1;
        else f = 0;
        vector<pair<int, int>> ans;
        if (c[0][1] != f) ans.emplace_back(1, 2);
        if (c[1][0] != f) ans.emplace_back(2, 1);
        if (c[n - 2][n - 1] != (f ^ 1)) ans.emplace_back(n - 1, n);
        if (c[n - 1][n - 2] != (f ^ 1)) ans.emplace_back(n, n - 1);
        assert(ans.size() <= 2);
        cout << ans.size() << '\n';
        for (auto &it : ans) cout << it.first << " " << it.second << '\n';
    }

    return 0;
}