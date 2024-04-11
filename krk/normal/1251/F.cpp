#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
int r, rpw;
int root, root_1;
int root_pw = 1 << 23;
const int Maxn = 1 << 19;
const int Maxm = 1500000;
const int Maxb = 20;

int fac[Maxn], inv[Maxn];
int pw2[Maxn];
int my[Maxb][Maxn];
int n, k;
int a[Maxn];
int b;
int res[Maxm];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int getRoot()
{
    int prims[3] = {2, 7, 17};
    for (int i = 2; ; i++) {
        bool ok = true;
        for (int j = 0; j < 3 && ok; j++)
            ok = toPower(i, (mod - 1) / prims[j]) != 1;
        if (ok) return i;
    }
}

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
    root = r; root_pw = rpw;
    while (root_pw > a.size()) {
        root = ll(root) * root % mod;
        root_pw >>= 1;
    }
    root_1 = Inv(root);
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
		int nrev = Inv(n);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

void Multiply(vector <int> A, vector <int> B, vector <int> &C)
{
    int n = 1;
    while (n < A.size() || n < B.size()) n <<= 1;
    n <<= 1;
    A.resize(n, 0); B.resize(n, 0);
    fft(A, false); fft(B, false);
    C.resize(n);
    for (int i = 0; i < n; i++)
        C[i] = ll(A[i]) * B[i] % mod;
    fft(C, true);
}

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
    r = toPower(getRoot(), 7 * 17);
    rpw = 1 << 23;
    fac[0] = inv[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        inv[i] = Inv(fac[i]);
        pw2[i] = 2ll * pw2[i - 1] % mod;
    }
    vector <int> spec(Maxn, 0); spec[0] = 1; spec[1] = 2; spec[2] = 1;
    fft(spec, false);
    for (int i = 0; i < Maxn; i++)
        my[0][i] = spec[i];
    for (int j = 1; j < Maxb; j++)
        for (int i = 0; i < Maxn; i++)
            my[j][i] = ll(my[j - 1][i]) * my[j - 1][i] % mod;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    for (int i = 0; i < k; i++) {
        int b; scanf("%d", &b);
        int ones = 0, twos = 0;
        for (int j = 1; j < b; j++)
            if (a[j] >= 2) twos++;
            else if (a[j] >= 1) ones++;
        vector <int> multB(ones + 1), multC;
        for (int j = 0; j <= ones; j++)
            multB[j] = ll(C(ones, j)) * pw2[j] % mod;
        if (twos == 0) multC = multB;
        else {
            vector <int> multA(Maxn, 1);
            for (int j = 0; j < Maxb; j++) if (twos & 1 << j)
                for (int z = 0; z < Maxn; z++)
                    multA[z] = ll(multA[z]) * my[j][z] % mod;
            fft(multA, true);
            while (multA.size() > 1 && multA.back() == 0) multA.pop_back();
            Multiply(multA, multB, multC);
        }
        for (int j = 0; j < multC.size() && b + j + 1 < Maxm; j++) if (multC[j])
            res[b + j + 1] = (res[b + j + 1] + multC[j]) % mod;
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        printf("%d\n", res[x / 2]);
    }
    return 0;
}