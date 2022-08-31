#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 305;
char a[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int tot[3] = {0, 0, 0};
        int zer[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'X') {
                    tot[(i + j) % 3]++;
                }
                else if (a[i][j] == 'O') {
                    zer[(i + j) % 3]++;
                    tot[(i + j) % 3]++;
                }
            }
        }
        int moves = (tot[0] + tot[1] + tot[2]) / 3;
        int who = -1;
        for (int mask = 1; mask < 7; mask++) {
            int vals = 0;
            for (int x = 0; x < 3; x++) {
                if (mask & (1 << x)) {
                    //X -> O
                    vals += tot[x] - zer[x];
                }
                else {
                    //O->X
                    vals += zer[x];
                }
            }
            if (vals <= moves) {
                who = mask;
                break;
            }
        }
        assert(who != -1);
        for (int x = 0; x < 3; x++) {
            if (who & (1 << x)) {
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < n; b++) {
                        if (::a[a][b] == '.') continue;
                        if ((a + b) % 3 == x) ::a[a][b] = 'O';
                    }
                }
            }
            else {
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < n; b++) {
                        if (::a[a][b] == '.') continue;
                        if ((a + b) % 3 == x) ::a[a][b] = 'X';
                    }
                }
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cout << a[x][y];
            }
            cout << '\n';
        }
    }
    return 0;
}