#include <bits/stdc++.h>
using namespace std;

const int D = 15, Z = 5000, O = 4999, S = 4000, T = 4998;

int d, p, c[D][D];

int pw(int u, int m) {
    long long ret = 1;
    for (int i = __lg(m); i >= 0; i--) {
        (ret *= ret) %= p;
        if (m >> i & 1) {
            (ret *= u) %= p;
        }
    }
    return ret;
}

void add(int a, int b, int c) {
    cout << "+ " << a << " " << b << " " << c << endl;
}

void expo(int a, int c) {
    cout << "^ " << a << " " << c << endl;
}

void copy(int a, int b) {
    add(a, Z, b);
}

void mult(int a, int m, int b) {
    if (m == 0) {
        copy(Z, b);
        return;
    }
    m = (m + p) % p;
    copy(a, T - 1);
    for (int i = __lg(m) - 1; i >= 0; i--) {
        add(T - 1, T - 1, T - 1);
        if (m >> i & 1) {
            add(T - 1, a, T - 1);
        }
    }
    copy(T - 1, b);
}

void subtract(int a, int b, int c) {
    mult(b, -1, T);
    add(a, T, c);
}

void init() {
    for (int i = __lg(p) - 1; i >= 0; i--) {
        add(Z, Z, Z);
        if (p >> i & 1) {
            add(Z, O, Z);
        }
    }
    for (int i = 0; i <= d; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
        }
    }
}

vector<int> operator*(const vector<int> &ve, int m) {
    vector<int> ans = ve;
    for (int &v : ans) {
        v = 1LL * v * m % p;
    }
    return ans;
}

vector<int> operator-(const vector<int> &a, const vector<int> &b) {
    vector<int> ans = a;
    for (int i = 0; i < a.size(); i++) {
        (ans[i] += p - b[i]) %= p;
    }
    return ans;
}

void find_square(int a, int b) {
    vector<vector<int>> bas;
    vector<vector<int>> pre;
    for (int i = 0; i <= d; i++) {
        int cur = S + i;
        copy(a, cur);
        for (int j = 0; j < i; j++) {
            add(cur, O, cur);
        }
        expo(cur, cur);
        vector<int> ve(d + 1, 0), ev(d + 1, 0);
        ev[i] = 1;
        for (int j = 0; j <= d; j++) {
            ve[j] = 1LL * c[d][j] * pw(i, j) % p;
        }
        for (int j = 0; j < i; j++) {
            int m = 1LL * bas[j][j] * pw(ve[j], p - 2) % p;
            ve = ve * m - bas[j]; ev = ev * m - pre[j];
        }
        bas.push_back(ve);
        pre.push_back(ev);
    }
    for (int i = d; i >= d - 2; i--) {
        for (int j = i - 1; j >= d - 2; j--) {
            if (bas[j][i] > 0) {
                int m = 1LL * bas[j][i] * pw(bas[i][i], p - 2) % p;
                bas[i] = bas[i] * m; pre[i] = pre[i] * m;
                bas[j] = bas[j] - bas[i]; pre[j] = pre[j] - pre[i];
            }
        }
    }
    vector<int> ve = pre[d - 2] * pw(bas[d - 2][d - 2], p - 2);
    copy(Z, b);
    for (int i = 0; i <= d; i++) {
        mult(S + i, ve[i], T - 2);
        add(b, T - 2, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> p;
    init();
    add(1, 2, 3);
    for (int i = 1; i <= 3; i++) {
        find_square(i, i + 3);
    }
    subtract(6, 4, 6);
    subtract(6, 5, 6);
    mult(6, pw(2, p - 2), 6);
    cout << "f 6" << endl;
}