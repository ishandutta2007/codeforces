// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> Poly;
typedef vector<Poly> S;
const int N = 2e5 + 5, P = 998244353, G = 3;

int A[N], rev[N];
int lim = 1, len = 0, mod;

//int oo = 0;

int inline power(int a, int b, int P) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int Gi = power(G, P - 2, P), inv2 = power(2, P - 2, P);

void inline NTT(int c[], int lim, int o) {
	//oo++;
	for (int i = 0; i < lim; i++)
		if (i < rev[i]) swap(c[i], c[rev[i]]);
	for (int k = 1; k < lim; k <<= 1) {
		int wn = power(o == 1 ? G : Gi, (P - 1) / (k << 1), P);
		for (int i = 0; i < lim; i += (k << 1)) {
			for (int j = 0, w = 1; j < k; j++, w = (LL)w * wn % P) {
				int u = c[i + j], v = (LL)c[i + k + j] * w % P;
				c[i + j] = (u + v) % P;
				c[i + j + k] = ((LL)u - v + P) % P; 
			}
		}
	}
	if (o == -1) {
		int inv = power(lim, P - 2, P);
		for (int i = 0; i < lim; i++)
			c[i] = (LL)c[i] * inv % P;
	}
}

void inline setN(int n) {
	lim = 1, len = 0;
	while (lim < n) lim <<= 1, len++;
	for (int i = 0; i < lim; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
}

Poly inline NTT(Poly a, int o) {
	int n = a.size();
	for (int i = 0; i < n; i++) A[i] = a[i];
	NTT(A, lim, o);
	Poly b;
	for (int i = 0; i < lim; i++) b.push_back(A[i]), A[i] = 0;
	return b;
}

Poly operator + (const Poly a, const Poly b)  {
	Poly c(max(a.size(), b.size()));
	for (int i = 0; i < c.size(); i++) {
		if (i < a.size()) {
			c[i] += a[i]; if (c[i] > P) c[i] -= P;
		}
		if (i < b.size()) {
			c[i] += b[i]; if (c[i] > P) c[i] -= P;
		}
	}
	return c;
}

Poly inline mul (Poly a, Poly b, int newn = -1) {
	if (newn == -1) newn = a.size() + b.size() - 1;
	setN(a.size() + b.size() - 1);
	Poly c = NTT(a, 1), d = NTT(b, 1);
	for (int i = 0; i < lim; i++) c[i] = (LL)c[i] * d[i] % P;
	d = NTT(c, -1); d.resize(newn);
	return d;
}

int K;

Poly X { 0, 1 };

S st(3);

Poly inline trans(Poly a) {
	for (int i = K - 1; i >= 1; i--) a[i] = a[i - 1];
	a[0] = 0;
	return a;
}

S solve(int n) {
	if (n == 0) return st;
	S u(3);
	if (n & 1) {
		S v = solve(n - 1);
		u[0] = v[1], u[1] = v[2], u[2] = u[1] + trans(u[1]) + trans(u[0]); 
	} else {
		S v = solve(n / 2 - 1);
		Poly a = mul(v[1], v[1], K);
		u[0] = a + trans(mul(v[0], v[0], K));
		u[1] = mul(v[2], v[1], K) + trans(mul(v[1], v[0], K));
		u[2] = mul(v[2], v[2], K) + trans(a);
	}
	return u;
}

int main() {
	int n; scanf("%d%d", &n, &K); ++K;
	st[0] = Poly { 1 };
	st[1] = Poly { 1, 1 };
	st[2] = Poly { 1, 3, 1 };
	for (int i = 0; i < 3; i++) st[i].resize(K);
	S u = solve(n);
	for (int i = 1; i < K; i++) printf("%d ", u[0][i]);
	return 0;
}