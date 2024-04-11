#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 3 * (int)1e6 + 10;
int a[maxN];
int n;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;


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
vector < int > f;
vector < int > go(int l, int r) {
    if (l == r) {
        vector < int > res(f[l] + 1, 1);
        return res;
    }
    else {
        auto it1 = go(l, (l + r) / 2);
        auto it2 = go((l + r) / 2 + 1, r);
        poly_mult(it1, it2);
        return it1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        a[y]++;
    }
    int s = 0;
    for (int i = 2; i < maxN; i++) {
        if (a[i] > 0) {
            f.push_back(a[i]);
            s += a[i];
        }
    }
    s /= 2;
    sort(f.begin(), f.end());
    vector < int > res = go(0, f.size() - 1);
    cout << res[s] << '\n';
    return 0;
}