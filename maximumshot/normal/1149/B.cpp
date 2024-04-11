#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 260;
const int L = 1e5 + 50;
const int ALPH = 26;

int n, q;
string a, b, c;
int la, lb, lc;
int dp[N][N][N];
string word;
int nxt[L][ALPH];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    cin >> word;

    fill((int*)nxt, (int*)nxt + L * ALPH, n + 2);

    for (int i = (int)word.size() - 1; i >= 0; i--) {
        for (int j = 0; j < ALPH; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][word[i] - 'a'] = i;
    }

    la = lb = lc = 0;

    fill((int*)dp, (int*)dp + N * N * N, n + 2);

    dp[0][0][0] = 0;

    for (int iter = 0; iter < q; iter++) {
        char op;
        int id;
        char cc;
        cin >> op >> id;
        if (op == '+') {
            cin >> cc;
            if (id == 1) {
                a.push_back(cc);
                la++;
                for (int i = la; i <= la; i++) {
                    for (int j = 0; j <= lb; j++) {
                        for (int k = 0; k <= lc; k++) {
                            if (i) {
                                dp[i][j][k] = min(dp[i][j][k],
                                    nxt[ dp[i - 1][j][k] ][ a[i - 1] - 'a' ] + 1
                                );
                            }
                            if (j) {
                                dp[i][j][k] = min(dp[i][j][k],
                                    nxt[ dp[i][j - 1][k] ][ b[j - 1] - 'a' ] + 1
                                );
                            }
                            if (k) {
                                dp[i][j][k] = min(dp[i][j][k],
                                    nxt[ dp[i][j][k - 1] ][ c[k - 1] - 'a' ] + 1
                                );
                            }
                        }
                    }
                }
            } else if (id == 2) {
                b.push_back(cc);
                lb++;
                for (int i = 0; i <= la; i++) {
                    for (int j = lb; j <= lb; j++) {
                        for (int k = 0; k <= lc; k++) {
                            if (i) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  nxt[ dp[i - 1][j][k] ][ a[i - 1] - 'a' ] + 1
                                );
                            }
                            if (j) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  nxt[ dp[i][j - 1][k] ][ b[j - 1] - 'a' ] + 1
                                );
                            }
                            if (k) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  nxt[ dp[i][j][k - 1] ][ c[k - 1] - 'a' ] + 1
                                );
                            }
                        }
                    }
                }
            } else {
                c.push_back(cc);
                lc++;
                for (int i = 0; i <= la; i++) {
                    for (int j = 0; j <= lb; j++) {
                        for (int k = lc; k <= lc; k++) {
                            if (i) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  nxt[ dp[i - 1][j][k] ][ a[i - 1] - 'a' ] + 1
                                );
                            }
                            if (j) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  nxt[ dp[i][j - 1][k] ][ b[j - 1] - 'a' ] + 1
                                );
                            }
                            if (k) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  nxt[ dp[i][j][k - 1] ][ c[k - 1] - 'a' ] + 1
                                );
                            }
                        }
                    }
                }
            }
        } else {
            if (id == 1) {
                for (int i = la; i <= la; i++) {
                    for (int j = 0; j <= lb; j++) {
                        for (int k = 0; k <= lc; k++) {
                            dp[i][j][k] = n + 2;
                        }
                    }
                }
                a.pop_back();
                la--;
            } else if (id == 2) {
                for (int i = 0; i <= la; i++) {
                    for (int j = lb; j <= lb; j++) {
                        for (int k = 0; k <= lc; k++) {
                            dp[i][j][k] = n + 2;
                        }
                    }
                }
                b.pop_back();
                lb--;
            } else {
                for (int i = 0; i <= la; i++) {
                    for (int j = 0; j <= lb; j++) {
                        for (int k = lc; k <= lc; k++) {
                            dp[i][j][k] = n + 2;
                        }
                    }
                }
                c.pop_back();
                lc--;
            }
        }
        cout << (dp[la][lb][lc] <= n ? "YES" : "NO") << "\n";
    }

    return 0;
}