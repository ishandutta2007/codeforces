#include <bits/stdc++.h>
using namespace std;
const int maxN = 55;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw[maxN * maxN];
int c[maxN];
int dp[maxN][maxN][maxN][maxN][2];
int n, p;
int get(int x, int y) {
    if (y == 0) {
        if (x == 0) return 1;
        else return 0;
    }
    return pw[y - 1];
}
int val(int a, int b, int c, int d, int e) {
    if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
    return dp[a][b][c][d][e];
}
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    pw[0] = 1;
    for (int i = 1; i < maxN * maxN; i++) {
        pw[i] = sum(pw[i - 1], pw[i - 1]);
    }
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> c[i];
    dp[n + 1][0][0][0][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int white = 0; white <= n - i + 1; white++) {
            int black = n - i + 1 - white;
            for (int eW = 0; eW <= white; eW++) {
                for (int eB = 0; eB <= black; eB++) {
                    for (int bit = 0; bit < 2; bit++) {
                        int st = 0;
                        int oW = white - eW;
                        int oB = black - eB;
                        for (int clr = 0; clr < 2; clr++) {
                            if ((c[i] != -1) && (clr != c[i])) continue;
                            for (int pBit = 0; pBit < 2; pBit++) {
                                int ne = pBit ^ bit;
                                if (clr == 0) {
                                    st = sum(st, mult(val(i + 1, white - 1, oW - ne, oB, pBit), mult(get(ne ^ 1, oB), pw[n - i - oB])));
                                }
                                else {
                                    st = sum(st, mult(val(i + 1, white, oW, oB - ne, pBit), mult(get(ne ^ 1, oW), pw[n - i - oW])));
                                }
                            }
                        }
                        dp[i][white][oW][oB][bit] = st;
                    }
                }
            }
        }
    }
    int cur = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                cur = sum(cur, dp[1][i][j][k][p]);
            }
        }
    }
    cout << cur;
    return 0;
}