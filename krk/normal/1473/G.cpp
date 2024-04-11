#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;
int root, root_1;
const int root_pw = 1<<15;

int fac[Maxn], ifac[Maxn];
int cur[root_pw], mult[root_pw];
int len;
int n;
int lg2[root_pw + 1];
int rev[16][root_pw];

void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[log_n][i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[log_n][i] |= 1<<(log_n-1-j);
	}
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

void fft (int a[], int n, bool invert) {
    int tmp = lg2[n];
	for (int i=0; i<n; ++i)
		if (i < rev[tmp][i])
			swap (a[i], a[rev[tmp][i]]);

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
		int nrev = toPower(n, mod - 2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

void Multiply(int A[], int &alen, int B[], int &blen)
{
    size_t n = 1;
	while (n < max (alen, blen))  n <<= 1;
	n <<= 1;
	fill(A + alen, A + n, 0); alen = n;
	fill(B + blen, B + n, 0); blen = n;
	fft (A, n, false),  fft (B, n, false);
	for (size_t i=0; i<n; ++i)
        A[i] = ll(A[i]) * B[i] % mod;
	fft (A, n, true);
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        ifac[i] = toPower(fac[i], mod - 2);
    }
    root = toPower(3, 30464);
    root_1 = toPower(root, mod - 2);
    for (int i = 0; 1 << i <= root_pw; i++) {
        calc_rev(1 << i, i);
        lg2[1 << i] = i;
    }
    cur[0] = 1; len = 1;
    scanf("%d", &n);
    while (n--) {
        int a, b; scanf("%d %d", &a, &b);
        int nlen = len + a - b;
        int tot = a + b;
        int lef = max(0, b - len + 1), rig = b + (nlen - 1) / 2;
        int sz = rig - lef + 1;
        for (int i = 0; i < sz; i++)
            mult[i] = C(tot, lef + i);
        Multiply(cur, len, mult, sz);
        int sh = b - lef;
        for (int i = sh; i <= sh + (nlen - 1) / 2 && i < len; i++)
            cur[i - sh] = cur[i];
        for (int i = (nlen - 1) / 2 + 1; i < nlen; i++)
            cur[i] = cur[nlen - 1 - i];
        len = nlen;
    }
    int res = 0;
    for (int i = 0; i < len; i++)
        res = (res + cur[i]) % mod;
    printf("%d\n", res);
    return 0;
}