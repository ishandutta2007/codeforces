#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 3 * (int)1e4 + 10;
typedef complex<long double> base;
const long double PI = acos(-1.0);
void fft (vector<base> & a, bool invert) {
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
        long double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
const int mod = (int)1e9 + 7;
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
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int pw2[maxN];
int n, k;
void init() {
    ll buf;
    cin >> buf >> k;
    if (buf > k) {
        cout << 0;
        exit(0);
    }
    n = (int)(buf);
    fact[0] = 1;
    invfact[0] = 1;
    inv[1] = 1;
    pw2[0] = 1;
    for (int i = 1; i <= k; i++) {
        pw2[i] = mult(pw2[i - 1], 2);
        fact[i] = mult(fact[i - 1], i);
        if (i > 1) {
            inv[i] = mult(mod - mod / i, inv[mod % i]);
        }
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
vector < int > get(int n) {
    vector < int > st(k + 1, 0);
    int cur = 1;
    int coef = pw2[n - 1];
    for (int i = 1; i <= k; i++) {
        cur = mult(cur, coef);;
        st[i] = mult(invfact[i], cur);
    }
    return st;
}
const int BLOCK = sqrt(mod);
vector < int > poly_mult(vector < int > poly1, vector < int > poly2) {
    int ext = 1;
    while (poly1.size() + poly2.size() >= ext) ext *= 2;
    poly1.resize(ext);
    poly2.resize(ext);
    vector < base > res1(ext), res2(ext), div1(ext), div2(ext);
    for (int i = 0; i < poly1.size(); i++) {
        res1[i] = (poly1[i] / BLOCK);
        div1[i] = (poly1[i] % BLOCK);
        res2[i] = (poly2[i] / BLOCK);
        div2[i] = (poly2[i] % BLOCK);
    }
    fft(res1, false);
    fft(div1, false);
    fft(res2, false);
    fft(div2, false);
    vector < base > other1(ext), other2(ext);
    for (int i = 0; i < res1.size(); i++) {
        other1[i] = res1[i] * div2[i];
        other2[i] = res2[i] * div1[i];
        res1[i] *= res2[i];
        div1[i] *= div2[i];
    }
    fft(res1, true);
    fft(div1, true);
    fft(other1, true);
    fft(other2, true);
    vector < int > ans(ext);
    for (int i = 0; i < ext; i++) {
        ll x = (ll)(res1[i].real() + 0.5);
        ll y = (ll)(div1[i].real() + 0.5);
        ll xm = (ll)(other1[i].real() + 0.5);
        ll ym = (ll)(other2[i].real() + 0.5);
//        cout << x
 //       assert(x >= 0);
        x %= mod;
        y %= mod;
        xm %= mod;
        ym %= mod;
        ans[i] = mult(mult(BLOCK, BLOCK), x);
        ans[i] = sum(ans[i], y);
        ans[i] = sum(ans[i], mult(BLOCK, sum(xm, ym)));
    }
    ans.resize(k + 1);
    return ans;
}
vector < int > calc(int n) {
    if (n == 0) {
        vector < int > res(k + 1, 0);
        res[0] = 1;
        return res;
    }
    if (n & 1) {
        auto poly1 = calc(n - 1);
        auto poly2 = get(n);
        return poly_mult(poly1, poly2);
    }
    else {
        auto poly1 = calc(n / 2);
        vector < int > poly2 = poly1;
        int coef = pw2[n / 2];
        int cur = 1;
        for (int i = 0; i <= k; i++) {
            poly2[i] = mult(poly2[i], cur);
            cur = mult(cur, coef);
        }
        return poly_mult(poly1, poly2);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    auto vec = calc(n);
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ans = sum(ans, mult(vec[i], mult(fact[k], invfact[k - i])));
    }
    cout << ans;
    return 0;
}