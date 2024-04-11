#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007

#define MAXN 50

typedef long long ll;
typedef pair<int, int> pii;

int n1, n2, k1, k2;

bool fwins[2][MAXN + 1][MAXN + 1];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n1 >> n2 >> k1 >> k2;

    for (int i = 0; i <= n1; i++) {
        fwins[0][i][0] = true;
        fwins[1][i][0] = true;
    }
    for (int i = 0; i <= n2; i++) {
        fwins[0][0][i] = false;
        fwins[1][0][i] = false;
    }
    fwins[0][0][0] = false;
    fwins[1][0][0] = true;

    for (int i = 0; i < n1 + n2; i++) {

        for (int p = 0; p < 2; p++) {
            for (int l = 0; l <= n1; l++) {
                for (int r = 0; r <= n2; r++) {
                    if (p == 0) {
                        for (int k = 1; k <= k1 && k <= l; k++) {
                            // left player
                            if (k == 1) {
                                fwins[0][l][r] = fwins[1][l - 1][r];
                            } else {
                                fwins[0][l][r] = max(fwins[0][l][r], fwins[1][l - k][r]);
                            }
                        }
                    } else {
                        for (int k = 1; k <= k2 && k <= r; k++) {
                            // right player
                            if (k == 1) {
                                fwins[1][l][r] = fwins[0][l][r - 1];
                            } else {
                                fwins[1][l][r] = min(fwins[1][l][r], fwins[0][l][r - k]);
                            }
                        }
                    }
                }
            }
        }
    }

//    for (int i = 0; i <= n1; i++) {
//        for (int j = 0; j <= n2; j++) {
//            cout << fwins[0][i][j] << ", " << fwins[1][i][j] << " ; ";
//        }
//        cout << endl;
//    }

    if (fwins[0][n1][n2]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}