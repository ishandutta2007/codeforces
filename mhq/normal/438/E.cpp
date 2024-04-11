#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

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

void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pw(n, mod - 2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

void poly_mult(vector < int >& a, vector < int > b) {
    int s = a.size() + b.size();
    int r = 1;
    while (r < s) r *= 2;
    a.resize(r);
    b.resize(r);
    fft(a, false);
    fft(b, false);
    for (int j = 0; j < r; j++) {
        a[j] = mult(a[j], b[j]);
    }
    fft(a, true);
    while (!a.empty() && (a.back() == 0)) a.pop_back();
}

const int maxN = 3 * (int)1e4 + 100;

int fact[maxN], invfact[maxN], inv[maxN];

void init() {
    inv[1] = invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}

int cnk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}

int invNumber(int a) {
    return pw(a, mod - 2);
}

vector < int > inversePoly(vector < int > a, int t) {
    if (t <= 1) {
        vector < int > f(1);
        f[0] = pw(a[0], mod - 2);
        return f;
    }
    a.resize(t);
    vector < int > f0 = inversePoly(a, (t + 1) / 2);
    poly_mult(a, f0);
    a.resize(t);
    a[0] = sub(2, a[0]);
    for (int i = 1; i < t; i++) {
        a[i] = sub(0, a[i]);
    }
    poly_mult(a, f0);
    a.resize(t);
    return a;
}
vector < int > get_root(vector < int > a, int lim) {
    if (lim <= 1) {
        vector < int > f(1);
        f[0] = 1;
        return f;
    }
    a.resize(lim);
    vector < int > f0 = get_root(a, (lim + 1) / 2);
    vector < int > inv_0 = inversePoly(f0, lim);
    poly_mult(inv_0, a);
    f0.resize(lim);
    inv_0.resize(lim);
    for (int i = 0; i < f0.size(); i++) {
        f0[i] = mult(inv[2], sum(f0[i], inv_0[i]));
    }
    return f0;
}

int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    inv[2] = (mod + 1) / 2;
    cin >> n >> m;
    vector < int > a(n);
    for(int& v : a) cin >> v;
    sort(a.begin(), a.end());
    vector < int > res(a.back() + 1);
    res[0] = 1;
    for (int i = 0; i < a.size(); i++) res[a[i]] = sub(0, 4);
    auto gg = get_root(res, m + 1);
    gg[0] = sum(gg[0], 1);
    auto ngg = inversePoly(gg, m + 1);
    for (int& v : ngg) v = mult(v, 2);
    ngg.resize(m + 1);
    for (int i = 1; i <= m; i++) cout << ngg[i] << '\n';
    return 0;
}