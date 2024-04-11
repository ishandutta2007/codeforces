#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int mod = 31607;
int mult(int a, int b) {
    return (a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 21;
int val[maxN][(1 << maxN) + 2];
int a[maxN][maxN];
const int P = pw(10000, mod - 2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
//    n = 21;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
//            a[i][j] = rand() % 151;
            a[i][j] = mult(a[i][j], P);
        }
    }
    for (int row = 0; row < n; row++) {
        val[row][0] = 1;
        for (int z = 0; z < n; z++) {
            for (int x = 0; x < (1 << z); x++) {
                val[row][x + (1 << z)] = mult(val[row][x], a[row][z]);
            }
        }
    }
    int F = 0;
    for (int mask = 0; mask < (1 << (n + 2)); mask++) {
        int good_mask = mask & ((1 << n) - 1);
        int bt1 = ((mask >> (n)) & 1);
        int bt2 = ((mask >> (n + 1)) & 1);
        int cnt = __builtin_popcount(mask);
        int X = 0;
        if (cnt % 2 == 0) X = 1;
        else X = sub(0, 1);
        for (int row = 0; row < n; row++) {
            int ngood = good_mask;
            if (bt1) ngood |= (1 << (n - row - 1));
            if (bt2) ngood |= (1 << row);

            int A = val[row][(1 << n) - 1];
            int B = val[row][ngood];
            X = mult(X, sub(B, A));
        }
        F = sum(F, X);
    }
    cout << sub(1, F);
    return 0;
}