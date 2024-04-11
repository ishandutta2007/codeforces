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
        vector<vector<char>> a(n, vector<char>(m));
        bool can[2] = {true, true};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'R') can[(i + j) % 2] = false;
                if (a[i][j] == 'W') can[(i + j + 1) % 2] = false;
            }
        }
        int it = -1;
        if (can[0]) it = 0;
        if (can[1]) it = 1;
        if (it == -1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i + j + it) % 2 == 0) cout << 'W';
                    else cout << 'R';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}