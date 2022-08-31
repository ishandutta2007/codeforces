#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
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

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

const int root = pw(646, 16);

const int root_1 = pw(208611436, 16);

const int root_pw = 1 << 16;

const int inv_pw = pw(root_pw, mod - 2);

int rev[root_pw + 2];

void init() {
    for (int i = 0; i < root_pw; i++) {
        int ri = 0;
        for (int j = 0; j < 16; j++) {
            if (i & (1 << j)) ri |= 1 << (15 - j);
        }
        rev[i] = ri;
    }
}

void fft (int* a, bool invert) {
    for (int i = 0; i < root_pw; i++) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int len = 2; len <= root_pw; len *= 2) {
        int wlen = invert ? root_1 : root;
        wlen = pw(wlen, root_pw / len);
        for (int i = 0; i < root_pw; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j]; int v = mult(w, a[i + j + len / 2]);
                a[i + j] = sum(u, v);
                a[i + j + len / 2] = sub(u, v);
                w = mult(w, wlen);
            }
        }
    }
    if (invert) {
        for (int i = 0; i < root_pw; i++) {
            a[i] = mult(a[i], inv_pw);
        }
    }
}



int n, k;
int a[3][root_pw];
int b[root_pw];
const int pw15 = (1 << 15);
void make_move() {
    memset(b, 0, sizeof b);
    for (int i = 0; i < pw15; i++) {
        b[i] = a[2][i];
        if (i > 0) {
            b[i] = sum(b[i], a[2][i - 1]);
        }
        if (i > 0) {
            b[i] = sum(b[i], a[1][i - 1]);
        }
    }
    for (int i = 0; i + 1 <= 2; i++) {
        for (int j = 0; j < root_pw; j++) {
            a[i][j] = a[i + 1][j];
        }
    }
    for (int j = 0; j < root_pw; j++) {
        a[2][j] = b[j];
    }
}
int c[3][root_pw];
int temp[root_pw];
void get(int n) {
    if (n <= 1) {
        a[2][0] = 1;
        for (int j = 0; j < n + 2; j++) {
            make_move();
        }
        return;
    }
    if (n & 1) {
        get(n - 1);
        make_move();
        return;
    }
    get((n - 2) / 2);
    for (int i = 0; i < 3; i++) {
        for (int j = pw15; j < root_pw; j++) {
            a[i][j] = 0;
        }
        fft(a[i], false);
        memset(c[i], 0, sizeof c[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < root_pw; j++) {
            temp[j] = mult(a[(i + 2) / 2][j], a[(i + 3) / 2][j]);
        }
        fft(temp, true);
        for (int j = 0; j < root_pw; j++) {
            c[i][j] = temp[j];
        }
        for (int j = 0; j < root_pw; j++) {
            temp[j] = mult(a[i / 2][j], a[(i + 1) / 2][j]);
        }
        fft(temp, true);
        for (int j = 1; j < root_pw; j++) {
            c[i][j] = sum(c[i][j], temp[j - 1]);
        }
    }
    for (int i = 0; i < 3; i++) {
        memset(a[i], 0, sizeof a[i]);
        for (int j = 0; j < pw15; j++) {
            a[i][j] = c[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n >> k;
    get(n);
    for (int i = 1; i <= k; i++) {
        cout << a[0][i] << " ";
    }
    cout << '\n';
    return 0;
}