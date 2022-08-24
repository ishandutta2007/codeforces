#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int LG = 17;
const int PW = (1 << 17);
const int INV = pw(PW, mod - 2);
void xor_fft(vector < int >& a, bool invert) {
    assert(a.size() == PW);
    for (int bit = 0; bit < LG; bit++) {
        for (int mask = 0; mask < PW; mask++) {
            if (mask & (1 << bit)) {
                int u = a[mask];
                int v = a[mask ^ (1 << bit)];
                a[mask ^ (1 << bit)] = sum(v, u);
                a[mask] = sub(v, u);
            }
        }
    }
    if (invert) {
        for (int& v : a) v = mult(v, INV);
    }
}
void and_fft(vector < int >& a, bool invert) {
    assert(a.size() == PW);
    for (int bit = 0; bit < LG; bit++) {
        for (int mask = 0; mask < PW; mask++) {
            if (mask & (1 << bit)) {
                int u = a[mask];
                int v = a[mask ^ (1 << bit)];
                if (!invert) {
                    a[mask ^ (1 << bit)] = sum(v, u);
                    a[mask] = u;
                }
                else {
                    a[mask ^ (1 << bit)] = sub(v, u);
                    a[mask] = u;
                }
            }
        }
    }
}
void or_fft(vector < int >& a, bool invert) {
    assert(a.size() == PW);
    for (int bit = 0; bit < LG; bit++) {
        for (int mask = 0; mask < PW; mask++) {
            if (mask & (1 << bit)) {
                int u = a[mask];
                int v = a[mask ^ (1 << bit)];
                if (!invert) {
                    a[mask ^ (1 << bit)] = v;
                    a[mask] = sum(u, v);
                }
                else {
                    a[mask ^ (1 << bit)] = v;
                    a[mask] = sub(u, v);
                }
            }
        }
    }
}
int n;
int bits[PW];
void convolute(vector < int >& a, vector < int >& b, vector < int >& c) {
    for (int i = 0; i < PW; i++) {
        c[i] = mult(a[i], b[i]);
    }
}
int fib[PW];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i < PW; i++) fib[i] = sum(fib[i - 1], fib[i - 2]);
    for (int i = 1; i < PW; i++) bits[i] = bits[i / 2] + (i & 1);
    cin >> n;
    vector < int > a(PW);
    while (n--) {
        int x;
        cin >> x;
        a[x]++;
    }
    vector < vector < int > > all(LG + 1, vector < int >(PW));
    for (int i = 0; i < PW; i++) {
        all[bits[i]][i] = a[i];
    }
    for (int i = 0; i < LG; i++) {
        or_fft(all[i], false);
    }
    vector < int > fin(PW);
    for (int s = 0; s <= LG; s++) {
        vector < int > now(PW);
        for (int i = 0; i <= LG && i <= s; i++) {
            int j = s - i;
            vector < int > cur(PW);
            convolute(all[i], all[j], cur);
            for (int p = 0; p < PW; p++) now[p] = sum(now[p], cur[p]);
        }
        or_fft(now, true);
        for (int k = 0; k < PW; k++) {
            if (bits[k] == s) {
                fin[k] = sum(fin[k], now[k]);
            }
        }
    }
    for (int i = 0; i < PW; i++) fin[i] = mult(fin[i], fib[i]);
    /*for (int i = 0; i <= 10; i++) {
        cout << fin[i] << " ";
    }
    cout << endl;
    return 0;*/
    and_fft(fin, false);
    vector < int > cop = a;
    for (int i = 0; i < PW; i++) {
        cop[i] = mult(cop[i], fib[i]);
    }
    and_fft(cop, false);
    convolute(fin, cop, fin);
    xor_fft(a, false);
    convolute(a, a, a);
    xor_fft(a, true);
    for (int i = 0; i < PW; i++) {
        a[i] = mult(a[i], fib[i]);
    }
    and_fft(a, false);
    convolute(fin, a, fin);
    and_fft(fin, true);
    int tot = 0;
    for (int i = 0; i < LG; i++) {
        tot = sum(tot, fin[(1 << i)]);
    }
    cout << tot;
    return 0;
}