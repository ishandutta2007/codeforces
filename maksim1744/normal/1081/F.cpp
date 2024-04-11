/*
    20.12.2018 17:46:01
*/

#include <bits/stdc++.h>

using namespace std;

int t;

int ask(int l, int r) {
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int nt;
    cin >> nt;
    int d = nt - t;
    t = nt;
    return d;
}

int main() {
    int n;
    cin >> n >> t;
    vector< int > inv(n, 0);
    vector< int > ans(n);
    if (n % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            int d = ask(i, i);
            while ((i + 1) % 2 != abs(d) % 2) {
                for (int j = i; j < n; ++j) {
                    inv[j] ^= 1;
                }
                d = ask(i, i);
            }
            int d0 = 0;
            for (int j = 0; j < i; ++j) {
                if (ans[j]^inv[j]) {
                    --d0;
                } else {
                    ++d0;
                }
                inv[j] ^= 1;
            }
            if (d - d0 == 1) {
                ans[i] = inv[i];
            } else {
                ans[i] = inv[i]^1;
            }
            inv[i] ^= 1;
        }
    } else {
        if (n == 1) {
            ans[0] = t;
        } else {
            int d = ask(0, 1);
            while (abs(d) % 2 != 0) {
                for (int j = 0; j < n; ++j) {
                    inv[j] ^= 1;
                }
                d = ask(0, 1);
            }
            bool eq;
            if ((d == 0) == (inv[0] == inv[1])) {
                eq = false;
            } else {
                eq = true;
            }
            inv[0] ^= 1;
            inv[1] ^= 1;
            if (eq != (inv[0] == inv[1])) {
                d = ask(1, 2);
                while (abs(d) % 2 != 0) {
                    inv[0] ^= 1;
                    inv[1] ^= 1;
                    inv[2] ^= 1;
                    d = ask(1, 2);
                }
                for (int j = 1; j < n; ++j) {
                    inv[j] ^= 1;
                }
            }
            d = ask(0, 1);
            while (abs(d) % 2 != 0) {
                for (int j = 0; j < n; ++j) {
                    inv[j] ^= 1;
                }
                d = ask(0, 1);
            }
            if (d == 2) {
                ans[0] = inv[0];
                ans[1] = inv[1];
            } else {
                ans[0] = inv[0]^1;
                ans[1] = inv[1]^1;
            }
            inv[0] ^= 1;
            inv[1] ^= 1;
            for (int i = 1; i < n - 1; ++i) {
                d = ask(i, i + 1);
                while (abs(d) % 2 != (i + 2) % 2) {
                    for (int j = i; j < n; ++j) {
                        inv[j] ^= 1;
                    }
                    d = ask(i, i + 1);
                }
                int d0 = 0;
                for (int j = 0; j < i + 1; ++j) {
                    if (ans[j]^inv[j]) {
                        --d0;
                    } else {
                        ++d0;
                    }
                    inv[j] ^= 1;
                }
                if (d - d0 == 1) {
                    ans[i + 1] = inv[i + 1];
                } else {
                    ans[i + 1] = inv[i + 1]^1;
                }
                inv[i + 1] ^= 1;
            }
        }
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}