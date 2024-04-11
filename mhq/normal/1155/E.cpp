#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e6 + 3;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const bool LOCAL = false;
int a = 2;
int b = 2;
int ask(int x) {
    if (LOCAL) {
        return sum(mult(a, x), b);
    }
    else {
        cout << "? " << x << endl;
        int ans;
        cin >> ans;
        return ans;
    }
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int f[15][15];
const int deg = 13;
vector < int > poly;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < deg; i++) {
        f[i][i] = ask(i);
    }
    for (int len = 1; len <= deg - 1; len++) {
        for (int i = 0; i + len <= deg - 1; i++) {
            int j = i + len;
            f[i][j] = mult(sub(f[i + 1][j], f[i][j - 1]), pw(j - i, mod - 2));
        }
    }
    vector < int > cur_poly(deg + 5, 0);
    vector < int > ans_poly(deg + 5, 0);
    cur_poly[0] = 1;
    for (int i = 0; i < deg; i++) {
        for (int j = 0; j < cur_poly.size(); j++) {
            ans_poly[j] = sum(ans_poly[j], mult(cur_poly[j], f[0][i]));
        }
        vector < int > n_p(deg + 5, 0);
        for (int j = 0; j < cur_poly.size(); j++) {
            n_p[j] = sub(n_p[j], mult(cur_poly[j], i));
            if (j + 1 < cur_poly.size()) {
                n_p[j + 1] = sum(n_p[j + 1], cur_poly[j]);
            }
        }
        cur_poly = n_p;
    }
    for (int i = 0; i < mod; i++) {
        int val = 0;
        int pw = 1;
        for (int j = 0; j < ans_poly.size(); j++) {
            val = sum(val, mult(ans_poly[j], pw));
            pw = mult(pw, i);
        }
        if (val == 0) {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
    return 0;
}