#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

void poly_sq(vector < int >& a) {
    int s = a.size() + a.size();
    int r = 1;
    while (r < s) r *= 2;
    a.resize(r);
    fft(a, false);
    for (int j = 0; j < r; j++) {
        a[j] = mult(a[j], a[j]);
    }
    fft(a, true);
    while (!a.empty() && (a.back() == 0)) a.pop_back();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, k, f;
    cin >> n >> k >> f;
    vector<int> dp(k + 1, 1);
    for (int step = 1; step < n; step++) {
        poly_sq(dp);
        dp.resize(2 * k + 1);
        vector<int> ndp(k + 1);
        int s_all = 0;
        for (int& v : dp) s_all = sum(s_all, v);
        int cur = 0;
        for (int t = 0; t <= k; t++) {
            cur = sum(cur, dp[t]);
            ndp[t] = mult(k - t + 1, dp[t]);
            ndp[t] = sum(ndp[t], sub(s_all, cur));
        }
        dp = ndp;
    }
    poly_sq(dp);
    if (f >= (int)dp.size()) {
        cout << 0 << '\n';
    }
    else {
        cout << dp[f] << '\n';
    }
    return 0;
}