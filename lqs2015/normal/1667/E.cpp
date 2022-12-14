#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 19, mod = 998244353;
int binpow(int a, int t) {
    int res = 1, p = a;
    for (int i = t; i; i >>= 1) {
        if (i & 1)
            res = 1ll * res * p % mod;
        p = 1ll * p * p % mod;
    }
    return res;
}
namespace poly {
    int w[2][MAXN + 5], s[MAXN + 5], t[MAXN + 5], n, m, sz, cnt, rev[MAXN + 5], cur, gg[MAXN + 5], G[MAXN + 5],
        jc[MAXN + 5], injc[MAXN + 5], iv[MAXN + 5];
    long long cc[MAXN + 5];
    vector<int> gf[MAXN + 5];
    int ar[22][MAXN + 5], len[22];
    struct polynomial {
        int len, arr[MAXN + 5];
        void read(int n) {
            len = n;
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
        }
        void write() {
            for (int i = 0; i < len; i++)
                printf("%d ", (arr[i] + mod) % mod);
            printf("\n");
        }
        void rev() {
            reverse(arr, arr + len);
        }
        void multiply(int x) {
            for (int i = 0; i < len; i++)
                arr[i] = 1ll * arr[i] * x % mod;
        }
        void clear() {
            for (int i = 0; i < len; i++)
                arr[i] = 0;
            len = 0;
        }
    } a, b, c, d, e, f;
    int binpow(int a, int t) {
        int res = 1, p = a;
        for (int i = t; i; i >>= 1) {
            if (i & 1)
                res = 1ll * res * p % mod;
            p = 1ll * p * p % mod;
        }
        return res;
    }
    void diff(polynomial &a, polynomial &b) {
        for (int i = 1; i < a.len; i++)
            b.arr[i - 1] = 1ll * i * a.arr[i] % mod;
        b.len = a.len - 1;
    }
    void inte(polynomial &a, polynomial &b) {
        for (int i = a.len - 1; i >= 0; i--)
            b.arr[i + 1] = 1ll * a.arr[i] * iv[i + 1] % mod;
        b.len = a.len + 1;
        b.arr[0] = 0;
    }
    void Init() {
        w[0][0] = 1;
        cur = binpow(3, (mod - 1) / MAXN);
        for (int i = 1; i <= MAXN; i++)
            w[0][i] = 1ll * w[0][i - 1] * cur % mod;
        w[1][0] = 1;
        cur = binpow(3, mod - 1 - (mod - 1) / MAXN);
        for (int i = 1; i <= MAXN; i++)
            w[1][i] = 1ll * w[1][i - 1] * cur % mod;
        jc[0] = 1;
        for (int i = 1; i <= MAXN; i++)
            jc[i] = 1ll * jc[i - 1] * i % mod;
        injc[MAXN] = binpow(jc[MAXN], mod - 2);
        for (int i = MAXN - 1; i >= 0; i--)
            injc[i] = 1ll * injc[i + 1] * (i + 1) % mod;
        for (int i = 1; i <= MAXN; i++)
            iv[i] = 1ll * jc[i - 1] * injc[i] % mod;
    }
    void ntt(int d[], int flag) {
        for (int i = 0; i < sz; i++)
            cc[i] = (long long)d[i];
        for (int i = 0; i < sz; i++) {
            if (rev[i] > i)
                swap(cc[i], cc[rev[i]]);
        }
        for (int i = 2; i <= sz; i <<= 1) {
            int p = i >> 1, fu = MAXN / i;
            for (int j = 0; j < p; j++) {
                gg[j] = w[flag][j * fu];
            }
            for (int j = 0; j < sz; j += i) {
                for (int k = j; k < j + p; k++) {
                    long long tmp1 = cc[k];
                    long long tmp2 = cc[k + p] % mod * gg[k - j];
                    cc[k] = tmp1 + tmp2;
                    cc[k + p] = tmp1 - tmp2;
                }
            }
        }
        for (int j = 0; j < sz; j++)
            cc[j] %= mod;
        if (flag) {
            int wn = binpow(sz, mod - 2);
            for (int i = 0; i < sz; i++) {
                cc[i] = cc[i] * wn % mod;
            }
        }
        for (int i = 0; i < sz; i++)
            d[i] = cc[i];
    }
    void mult(polynomial &a, polynomial &b, polynomial &c) {
        c.len = a.len + b.len - 1;
        sz = 1;
        cnt = 0;
        while (sz < c.len) {
            sz <<= 1;
            cnt++;
        }
        rev[0] = 0;
        for (int i = 1; i < sz; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
        }
        for (int i = 0; i < sz; i++) {
            if (i < a.len)
                s[i] = a.arr[i];
            else
                s[i] = 0;
        }
        for (int i = 0; i < sz; i++) {
            if (i < b.len)
                t[i] = b.arr[i];
            else
                t[i] = 0;
        }
        ntt(s, 0);
        ntt(t, 0);
        for (int i = 0; i < sz; i++)
            s[i] = 1ll * s[i] * t[i] % mod;
        ntt(s, 1);
        for (int i = 0; i < c.len; i++)
            c.arr[i] = s[i];
    }
    void cdq(int l, int r, int dep) {
        if (l == r) {
            a.len = gf[l].size();
            for (int i = 0; i < a.len; i++)
                a.arr[i] = gf[l][i];
            return;
        }
        int mid = (l + r) >> 1;
        cdq(l, mid, dep + 1);
        for (int i = 0; i < a.len; i++)
            ar[dep][i] = a.arr[i];
        len[dep] = a.len;
        cdq(mid + 1, r, dep + 1);
        b.len = len[dep];
        for (int i = 0; i < b.len; i++)
            b.arr[i] = ar[dep][i];
        mult(a, b, c);
        a.len = c.len;
        for (int i = 0; i < c.len; i++)
            a.arr[i] = c.arr[i];
    }
    void geti(polynomial &a, polynomial &b, int n, int m) {
        sz = 1;
        cnt = 0;
        while (sz < 2 * n) {
            sz *= 2;
            cnt++;
        }
        rev[0] = 0;
        for (int i = 1; i < sz; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
        }
        for (int i = 0; i < sz; i++)
            s[i] = t[i] = 0;
        for (int i = 0; i < n; i++)
            s[i] = a.arr[i];
        for (int i = 0; i < m; i++)
            t[i] = b.arr[i];
        ntt(s, 0);
        ntt(t, 0);
        for (int i = 0; i < sz; i++)
            s[i] = (-1ll * s[i] * t[i] % mod * t[i] + 2 * t[i]) % mod;
        ntt(s, 1);
        for (int i = 0; i < n; i++)
            b.arr[i] = s[i];
    }
    void inv(int deg, polynomial &a, polynomial &b) {
        if (deg == 1) {
            b.arr[0] = binpow(a.arr[0], mod - 2);
            b.len = 1;
            return;
        }
        inv((deg + 1) >> 1, a, b);
        geti(a, b, deg, (deg + 1) >> 1);
        b.len = deg;
    }
    void divide(polynomial &a, polynomial &b, polynomial &c, polynomial &d) {
        a.rev();
        b.rev();
        inv(a.len, b, d);
        mult(a, d, c);
        c.len = a.len - b.len + 1;
        c.rev();
        a.rev();
        b.rev();
        mult(b, c, d);
        for (int i = 0; i < a.len; i++)
            d.arr[i] = (a.arr[i] - d.arr[i]) % mod;
        d.len = b.len - 1;
    }
    void gets(polynomial &a, polynomial &b, int n, int m) {
        polynomial c, d;
        inv(n, b, c);
        int t = a.len;
        a.len = n;
        mult(a, c, d);
        a.len = t;
        for (int i = 0; i < m; i++)
            d.arr[i] = (d.arr[i] + b.arr[i]) % mod;
        d.len = n;
        d.multiply((mod + 1) / 2);
        for (int i = 0; i < n; i++)
            b.arr[i] = d.arr[i];
    }
    void Sqrt(int deg, polynomial &a, polynomial &b)  // a[0]=1
    {
        if (deg == 1) {
            b.arr[0] = 1;
            b.len = 1;
            return;
        }
        Sqrt((deg + 1) >> 1, a, b);
        gets(a, b, deg, (deg + 1) >> 1);
        b.len = deg;
    }
    void ln(polynomial &a, polynomial &b, int deg) {
        polynomial c, d;
        inv(deg, a, c);
        diff(a, d);
        mult(d, c, b);
        inte(b, b);
        b.len = deg;
    }
    void gete(polynomial &a, polynomial &b, int n, int m) {
        polynomial c, d;
        ln(b, c, n);
        for (int i = c.len; i < n + m; i++)
            c.arr[i] = 0;
        c.len = n;
        for (int i = 0; i < n; i++)
            c.arr[i] = (a.arr[i] - c.arr[i]) % mod;
        c.arr[0]++;
        c.arr[0] %= mod;
        mult(b, c, d);
        for (int i = 0; i < n; i++)
            b.arr[i] = d.arr[i];
    }
    void exp(int deg, polynomial &a, polynomial &b) {
        if (deg == 1) {
            b.arr[0] = 1;
            b.len = 1;
            return;
        }
        exp((deg + 1) >> 1, a, b);
        gete(a, b, deg, (deg + 1) >> 1);
        b.len = deg;
    }
    void Pow(polynomial &a, polynomial &b, int n, int deg) {
        polynomial c, d;
        int pp, ps, iv;
        for (int i = 0; i < a.len; i++) {
            if (a.arr[i]) {
                pp = i;
                ps = a.arr[i];
                break;
            }
        }
        if (1ll * n * pp >= deg) {
            for (int i = 0; i < deg; i++)
                b.arr[i] = 0;
            b.len = deg;
            return;
        }
        iv = binpow(ps, mod - 2);
        c.len = a.len - pp;
        for (int i = 0; i < c.len; i++)
            c.arr[i] = 1ll * a.arr[i + pp] * iv % mod;
        ln(c, d, deg);
        d.multiply(n);
        b.clear();
        exp(deg, d, b);
        int coef = binpow(ps, n);
        for (int i = deg - 1; i >= n * pp; i--)
            b.arr[i] = 1ll * b.arr[i - n * pp] * coef % mod;
        for (int i = 0; i < n * pp; i++)
            b.arr[i] = 0;
    }
    int nn, ans[555555];
    int C(int n, int k) {
        if (n < 0 || k < 0 || n < k)
            return 0;
        return 1ll * jc[n] * injc[k] % mod * injc[n - k] % mod;
    }
    void solve() 
	{
		scanf("%d", &nn);
		a.len = (nn - 1) >> 1; a.len++;
		for (int i = 1; i < a.len; i++) a.arr[i] = iv[i];
		exp(nn + 1, a, b);
		c.len = nn + 1; d.len = nn + 1;
		for (int i = 0; i <= nn; i++) c.arr[i] = injc[i];
		memset(d.arr, 0, sizeof(d.arr));
		for (int i = (nn - 1) >> 1; i <= nn - 2; i++) d.arr[i] = 1ll * jc[nn - i - 2] * b.arr[i] % mod;
		mult(c, d, e);
		for (int i = 2; i <= nn; i++) ans[i] = 1ll * e.arr[nn - i] * (i - 1) % mod * jc[nn - i] % mod;
		ans[1] = 1ll * jc[nn - 1] * b.arr[nn - 1] % mod;
		for (int i = 1; i <= nn; i++) printf("%d ", (ans[i] + mod) % mod);
		printf("\n");
    }
}  // namespace poly
int main() {
    poly::Init();
    poly::solve();
    return 0;
}