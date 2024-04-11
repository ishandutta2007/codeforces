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
                } else if (a[i][j] == 'O') {
                    zer[(i + j) % 3]++;
                    tot[(i + j) % 3]++;
                }
            }
        }
        int moves = (tot[0] + tot[1] + tot[2]) / 3;
        int a1 = -1;
        int a2 = -1;
//        cout << tot[0] << " " << tot[1] << " " << tot[2] << " " << " " << zer[0] << " " << zer[1] << " " << zer[2]
//             << endl;
        for (int w1 = 0; w1 < 3; w1++) {
            for (int w2 = 0; w2 < 3; w2++) {
                if (w1 == w2) continue;
                int vals = 0;
                for (int x = 0; x < 3; x++) {
                    if (x == w1) {
                        vals += tot[x] - zer[x];
                    }
                    if (x == w2) {
                        vals += zer[x];
                    }
                }
                if (vals <= moves) {
                    a1 = w1;
                    a2 = w2;
                }
            }
        }
        assert(a1 != -1);
        for (int x = 0; x < 3; x++) {
            if (x == a1) {
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < n; b++) {
                        if (::a[a][b] == '.') continue;
                        if ((a + b) % 3 == x) ::a[a][b] = 'O';
                    }
                }
            } else if (x == a2){
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