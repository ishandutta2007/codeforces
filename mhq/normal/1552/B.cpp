#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e4 + 15;
int r[maxN][5];
bool who(int i, int j) {
    int cnt = 0;
    for (int z = 0; z < 5; z++) {
        if (r[i][z] < r[j][z]) cnt++;
    }
    return (cnt >= 3);
}
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
            for (int j = 0; j < 5; j++) {
                cin >> r[i][j];
            }
        }
        int c = 1;
        for (int i = 2; i <= n; i++) {
            if (!who(c, i)) c = i;
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (i == c) continue;
            if (!who(c, i)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << c << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}