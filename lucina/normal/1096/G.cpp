#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353 ; /// (1 << 23) * 7 * 17 + 1

int add (int a, int b) {
    return ((a += b) >= mod)? a - mod : a;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}

int power (int a, long long b) {
    int res = 1;
    for (; b > 0 ; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}



const int sz = 1 << 20; /// enough?
const int g = 3;
const int g_in = power(3, mod - 2);

int rev_bit[sz + 10];
int r[sz + 10];

void pre_rev_bit (int n) {
    int lg = 0;
    while ((1 << (lg + 1)) < n) ++ lg;

    for (int i = 1 ; i < n ; ++ i) {
        rev_bit[i] = (rev_bit[i >> 1] >> 1) | ((i & 1) << lg);
    }
}

void pre_pow (int n, int root) {
    pre_rev_bit(n);
    r[0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        r[i] = mul(r[i - 1], root);
    }
}

void ntt (int * a, int n, bool inverse) {

    int root = inverse ? g_in : g;
    root = power(root, (mod - 1) / n);


    pre_pow(n, root);

    for (int i = 0 ; i < n; ++ i) {
        int to = rev_bit[i];
        if (i < to) {
            swap(a[i], a[to]);
        }
    }


    for (int len = 1 ; len < n ; len <<= 1) {
        for (int i = 0 ; i < n ; i += (len << 1)) {
            int cur = 0;
            int delta = n / (len << 1);

            for (int j = 0 ; j < len ; ++ j) {
                int u = a[i + j], v = mul(a[i + j + len], r[cur]);

                a[i + j] = add(u, v);
                a[i + j + len] = sub(u, v);
                cur += delta;
            }
        }
    }


    if (inverse) {
        int inv = power(n, mod - 2);
        for (int i = 0 ; i < n;  ++ i) {
            a[i] = mul(a[i], inv);
        }
    }
}

int p[sz + 10];

int main () {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int x; k -- ; ) {
        scanf("%d", &x);
        ++ p[x];
    }

    ntt (p, sz, false);

    ///remember that DFT(A * B) = DFT(A) dot DFT(B)
    /// so DFT(A^n) is just DFT(A) dot n times
    for (int i = 0 ; i < sz ; ++ i) {
        p[i] = power(p[i], n / 2);
    }

    ntt (p, sz, true);

    int ans = 0;

    for (int i = 0 ; i < sz ; ++ i) {
        ans = add(ans, mul(p[i], p[i]));
    }

    printf("%d\n", ans);

}