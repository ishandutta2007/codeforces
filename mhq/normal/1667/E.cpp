#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

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

void fft(vector<int> &a, bool invert) {
    int n = (int) a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = int(wlen * 1ll * wlen % mod);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = int(w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pw(n, mod - 2);
        for (int i = 0; i < n; ++i)
            a[i] = int(a[i] * 1ll * nrev % mod);
    }
}

void poly_mult(vector<int> &a, vector<int> b) {
    if (min(a.size(), b.size()) < 128) {
        vector<int> c = a;
        a.assign(a.size() + b.size() - 1, 0);
        for (int i = 0; i < c.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                a[i + j] = sum(a[i + j], mult(c[i], b[j]));
            }
        }
        return;
    }
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
}
const int maxN = 2e5 + 10;
int F[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > inv(n + 1), fact(n + 1), invfact(n + 1);
    inv[1] = invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    vector<int> p1(n + 2);
    for (int t = (n - 1) / 2; t <= n - 2; t++) {
        p1[n - t] = fact[n - t - 2];
    }
    vector<int> p2(n + 2);
    for (int s = 0; s <= n; s++) {
        p2[s] = invfact[n - s];
    }
    poly_mult(p1, p2);
    p1.resize(2 * n + 5);
    for (int j = 2; j <= n; j++) {
        F[j] = mult(p1[n + j], mult(fact[n - j], invfact[j - 2]));
    }
    F[1] = fact[n - 1];
    int sb = 0;
    for (int i = n; i >= 1; i--) {
        ans[i] = sub(mult(F[i], fact[i - 1]), sb);
        if (i > 1) sb = sum(sb, mult(F[i], fact[i - 2]));
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}