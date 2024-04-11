#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int mod;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 5005;
int stir[maxN][maxN];
int n;
int c[maxN][maxN];
int pw[maxN][maxN];
int F[maxN][maxN];
int fact[maxN];
int PP[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> mod;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mult(fact[i - 1], i);
    }
//    stir[0][0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= i; j++) {
//            //1, 2, 3, .. j
//            stir[i][j] = sum(mult(j, stir[i - 1][j]), mult(j, stir[i - 1][j - 1]));
//        }
//    }
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    F[0][0] = 1;
//    PP[0][0] = 1;
//    for (int i = 1; i <= n; i++) {
//        PP[0][i] = 1;
//    }
    for (int i = 1; i <= n; i++) {
        for (int chains = 1; chains <= i; chains++) {
            //add to end, start new
            F[i][chains] = sum(mult(2 * chains, F[i - 1][chains]), F[i - 1][chains - 1]);
            F[i][chains] = sum(F[i][chains], mult(chains, mult(chains + 1, F[i - 1][chains + 1])));
//            if (i >= chains) {
//                F[i][chains] = PP[i - chains][chains];
//            }
//            PP[i][chains] = sum(PP[i][chains - 1], F[i][chains]);
        }
    }
    pw[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            pw[i][j] = mult(pw[i][j - 1], i);
        }
    }
    int ans = 0;
    //4 4
    //4 3 1
    //4 2 2
    //4 1 1 1 1
    //4 2 1 1
    for (int x = 0; x <= n; x++) {
        for (int y = 1; y + x <= n && n - x - y >= y; y++) {
            int coef = mult(c[n][y], mult(c[n - y][x], mult(fact[y], F[n - y - x][y])));
            coef = mult(coef, mult(pw[n - 1][y], pw[n - x - y][x]));
            ans = sum(ans, coef);
        }
    }
    cout << ans << '\n';
    return 0;
}