#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    else {
        int res = pw(a, b / 2);
        return mult(res, res);
    }
}
int get_inv(int a) {
    return pw(a, mod - 2);
}
int root = 2;
int root_1 = (mod + 1) / 2;
int root_pw = 1<<21;

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
        int nrev = get_inv(n);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; ;i++) {
        if (pw(i, root_pw) != 1) continue;
        if (pw(i, root_pw / 2) != 1) {
            root = i;
            root_1 = get_inv(root);
            break;
        }
    }
    int n, k;
    cin >> n >> k;
    vector < int > coefs;
    vector < int > poly(root_pw, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        coefs.push_back(x);
    }
    int cur_coef = 1;
    for (int i = 0; i < poly.size(); i++) {
        int val = 0;
        for (int v : coefs) {
            val = sum(val, pw(cur_coef, v));
        }
        val = pw(val, n / 2);
        poly[i] = val;
        cur_coef = mult(cur_coef, root);
    }
    fft(poly, true);
    int ans = 0;
    for (int i = 0; i < poly.size(); i++) {
        ans = sum(ans, mult(poly[i], poly[i]));
    }
    cout << ans;
    return 0;
}