#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 95542721;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) {
        return mult(a, pw(a, b - 1));
    }
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int cb(int a) {
    return mult(a, mult(a, a));
}
const int BLOCK = 150;
int n, q;
const int maxN = (int)1e5 + 100;
const int LG = 50;
int add[maxN / BLOCK + 2];
int val[maxN / BLOCK + 2][LG];
int a[maxN];
int coef[LG];
int cur[maxN];
int valA[maxN][LG];
void build(int i) {
    if (i < 0) return;
    int l = i * BLOCK;
    int r = min(l + BLOCK - 1, n - 1);
    for (int j = l; j <= r; j++) {
        cur[j] += add[i];
        if (cur[j] >= 48) cur[j] -= 48;
    }
    add[i] = 0;
    for (int k = 0; k < 48; k++) {
        val[i][k] = 0;
    }
    for (int j = l; j <= r; j++) {
        int s = cur[j];
        for (int k = 0; k < 48; k++) {
            val[i][k] = sum(val[i][k], valA[j][s]);
            s++;
            if (s == 48) s = 0;
        }
    }
}
int get(int l, int r) {
    // i * BLOCK >= l
    // i * BLOCK + BLOCK - 1 <= r
    int il = (l + BLOCK - 1) / BLOCK;
    int ir = (r - BLOCK + 1) / BLOCK;
    if (r < BLOCK - 1) ir = -1;
    int s = 0;
    if (il > ir) {
        for (int j = l; j <= r; j++) {
            s = sum(s, valA[j][(cur[j] + add[j / BLOCK]) % 48]);
        }
        return s;
    }
    for (int j = il; j <= ir; j++) {
        s = sum(s, val[j][add[j]]);
    }
    for (int j = l; j <= il * BLOCK - 1; j++) {
        s = sum(s, valA[j][(cur[j] + add[j / BLOCK]) % 48]);
    }
    for (int j = (ir + 1) * BLOCK; j <= r; j++) {
        s = sum(s, valA[j][(cur[j] + add[j / BLOCK]) % 48]);
    }
    return s;
}
void upd(int l, int r) {
    int il = (l + BLOCK - 1) / BLOCK;
    int ir = (r - BLOCK + 1) / BLOCK;
    if (r < BLOCK - 1) ir = -1;
    if (il > ir) {
        for (int j = l; j <= r; j++) {
            cur[j] = (cur[j] + 1) % 48;
        }
        for (int j = ir - 1; j <= il + 1; j++) {
            if (j * BLOCK <= r && j * BLOCK + BLOCK - 1 >= l) {
                build(j);
            }
        }
        return;
    }
    for (int j = il; j <= ir; j++) {
        add[j] = (add[j] + 1) % 48;
    }
    for (int j = l; j <= il * BLOCK - 1; j++) {
        cur[j] = (cur[j] + 1) % 48;
    }
    if (l <= (il * BLOCK - 1)) {
        build(il - 1);
    }
    for (int j = (ir + 1) * BLOCK; j <= r; j++) {
        cur[j] = (cur[j] + 1) % 48;
    }
    if ((ir + 1) * BLOCK <= r) {
        build(ir + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(239);
    coef[0] = 1;
    for (int k = 1; k < 48; k++) {
        coef[k] = (1LL * coef[k - 1] * 3) % (mod - 1);
    }
    cin >> n;
    //n = 1000;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= mod;
        valA[i][0] = a[i];
        for (int j = 1; j < 48; j++) {
            valA[i][j] = cb(valA[i][j - 1]);
        }
    }
    //q = 5;
    cin >> q;
    for (int i = 0; i * BLOCK < n; i++) {
        build(i);
    }
    for (int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1) {
            cout << get(l, r) << '\n';
        }
        else {
            upd(l, r);
        }
    }
    return 0;
}