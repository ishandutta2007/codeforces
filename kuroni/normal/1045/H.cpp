#include <bits/stdc++.h>
using namespace std;

const int N = 4E5 + 5, MOD = 1E9 + 7;

int c00, c01, c10, c11;
long long fct[N], inv[N], ifc[N];
string a, b;

long long C(int n, int k) {
    if (k == -1) {
        return n == -1;
    } else {
        return fct[n] * ifc[k] % MOD * ifc[n - k] % MOD;
    }
}

long long solve(string s, int c00, int c01, int c10, int c11) {
    int sz = c00 + c01 + c10 + c11 + 1;
    long long ans = 0;
    if (s.size() < sz) {
        return 0;
    }
    if (s.size() > sz) {
        int r0 = c10, r1 = c01 + 1;
        int c0 = r0 + c00, c1 = r1 + c11;
        if (r1 - 1 <= r0 && r0 <= r1) {
            ans = C(c0 - 1, r0 - 1) * C(c1 - 1, r1 - 1) % MOD;
        }
        return ans;
    }
    for (int i = 1; i < sz; i++) {
        if (s[i] == '1') {
            if (s[i - 1] == '0') {
                c00--;
            } else {
                c10--;
            }
            if (min(min(c00, c01), min(c10, c11)) >= 0) {
                int r0 = c10 + 1, r1 = c01;
                int c0 = r0 + c00, c1 = r1 + c11;
                if (r0 - 1 <= r1 && r1 <= r0) {
                    (ans += C(c0 - 1, r0 - 1) * C(c1 - 1, r1 - 1)) %= MOD;
                }
            }
            if (s[i - 1] == '0') {
                c00++;
            } else {
                c10++;
            }
        }
        if (s[i - 1] == '0' && s[i] == '0') {
            c00--;
        } else if (s[i - 1] == '0' && s[i] == '1') {
            c01--;
        } else if (s[i - 1] == '1' && s[i] == '0') {
            c10--;
        } else {
            c11--;
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    fct[0] = ifc[0] = 1;
    for (int i = 1; i < N; i++) {
        fct[i] = fct[i - 1] * i % MOD;
        ifc[i] = ifc[i - 1] * inv[i] % MOD;
    }
    cin >> a >> b >> c00 >> c01 >> c10 >> c11;
    b = "0" + b;
    for (int i = b.size() - 1, car = 1; i >= 0; i--, car /= 2) {
        car += b[i] - '0';
        b[i] = car % 2 + '0';
    }
    if (b.front() == '0') {
        b.erase(b.begin());
    }
    cout << (solve(b, c00, c01, c10, c11) - solve(a, c00, c01, c10, c11) + MOD) % MOD;
}