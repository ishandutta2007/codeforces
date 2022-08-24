#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 105;
int clr[maxN][maxN];
bool at_least[maxN][maxN][26];
bool pp[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (clr[i][j] == 0) {
                int f = 1;
                memset(pp, 0, sizeof pp);
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (abs(x) + abs(y) > 1) continue;
                        pp[clr[i + x][j + y]] = true;
                    }
                }
                while (pp[f]) f++;
                if (f == 1) {
                    int largest = -1;
                    // d^3
                    for (int d = 1; ; d++) {
                        bool ok = true;
                        for (int a = i; a <= i + d - 1; a++) {
                            if (!ok) break;
                            for (int b = j; b <= j + d - 1; b++) {
                                if (a > n || b > m) {
                                    ok = false;
                                    break;
                                }
                                if (clr[a][b] != 0) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        for (int a = i - 1; a <= i + d; a++) {
                            if (!ok) break;
                            for (int b = j - 1; b <= j + d; b++) {
                                bool c1 = (a == (i - 1)) || (a == (i + d));
                                bool c2 = (b == (j - 1)) || (b == (j + d));
                                if (c1 && c2) continue;
                                if (clr[a][b] == f) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (!ok) break;
                        largest = d;
                    }
                    int d = largest;
                    for (int a = i; a <= i + d - 1; a++) {
                        for (int b = j; b <= j + d - 1; b++) {
                            clr[a][b] = f;
                            for (int x = -1; x <= 1; x++) {
                                for (int y = -1; y <= 1; y++) {
                                    if (abs(x) + abs(y) > 1) continue;
                                    at_least[a + x][b + y][f] = true;
                                }
                            }
                        }
                    }
                }
                else {
                    int largest = -1;
                    for (int d = 1; ; d++) {
                        bool ok = true;
                        for (int a = i; a <= i + d - 1; a++) {
                            if (!ok) break;
                            bool has_val = false;
                            for (int b = j; b <= j + d - 1; b++) {
                                for (int c = 1; c < f; c++) if (!at_least[i][b][c]) has_val = true;
                                if (has_val) {
                                    ok = false;
                                    break;
                                }
                                if (a > n || b > m) {
                                    ok = false;
                                    break;
                                }
                                if (clr[a][b] != 0) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        for (int a = i - 1; a <= i + d; a++) {
                            if (!ok) break;
                            for (int b = j - 1; b <= j + d; b++) {
                                bool c1 = (a == (i - 1)) || (a == (i + d));
                                bool c2 = (b == (j - 1)) || (b == (j + d));
                                if (c1 && c2) continue;
                                if (clr[a][b] == f) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (!ok) break;
                        largest = d;
                    }
                    int d = largest;
                    for (int a = i; a <= i + d - 1; a++) {
                        for (int b = j; b <= j + d - 1; b++) {
                            clr[a][b] = f;
                            for (int x = -1; x <= 1; x++) {
                                for (int y = -1; y <= 1; y++) {
                                    if (abs(x) + abs(y) > 1) continue;
                                    at_least[a + x][b + y][f] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (char)(clr[i][j] - 1 + 'A');
        }
        cout << '\n';
    }
    return 0;
}