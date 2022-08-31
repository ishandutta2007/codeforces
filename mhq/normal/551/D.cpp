#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int mod;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int bin_pw(int a, ull b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, bin_pw(a, b - 1));
    int res = bin_pw(a, b / 2);
    return mult(res, res);
}
int pw[70];
int l;
ull n, k;
vector < vector < int > > mat_mult(vector < vector < int > > a, vector < vector < int > > b) {
    vector < vector < int > > c;
    c.resize(2);
    for (int i = 0; i < c.size(); i++) c[i].resize(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = sum(c[i][j], mult(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}
vector < vector < int > > mat_pw(vector < vector < int > > a, ull n) {
    vector < vector < int > > b;
    b.resize(2);
    for (int i = 0; i < b.size(); i++) b[i].resize(2);
    if (n == 1) {
        b[0][0] = 0;
        b[0][1] = 1;
        b[1][0] = 1;
        b[1][1] = 1;
        return b;
    }
    else {
        if (n & 1) {
            return mat_mult(a, mat_pw(a, n - 1));
        }
        else {
            auto res = mat_pw(a, n / 2);
            return mat_mult(res, res);
        }
    }
}
int get(ull n) {
    vector < vector < int > > a(2);
    a.resize(2);
    for (int i = 0; i < a.size(); i++) a[i].resize(2);
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    auto b = mat_pw(a, n);
    return sum(b[0][0], mult(b[0][1], 2));
    // F[1] = 1
    // F[2] = 2

    // F[2k]
    // F[2k + 1]
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> l >> mod;
    int ans = 1 % mod;
    int f1  = get(n);
    int f2  = sum(mod - f1, bin_pw(2, n));
    if ((l != 64) && k >= (1LL << l)) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < l; i++) {
        if (k & (1LL << i)) ans = mult(ans, f2);
        else ans = mult(ans, f1);
    }
    cout << ans;
    //    
    //  
    // n = 1 -> 2
    // n = 2 -> 3
    return 0;
}