#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define pii pair<int, int>
using namespace std;
typedef unsigned long long u64; 
typedef long long i64;
typedef double db;
const int N = 100000, B = 10;
const u64 mod = 1ll << 58;

struct Num {
	u64 a[9];
	Num() {memset(a, 0, sizeof(a)); }
	Num(int x) {memset(a, 0, sizeof(a)), a[0] = x; }
	friend Num operator * (const Num a, const Num b) {
		Num c;
		u64 s = 0;
		for(int i = 0; i < B - 1; i++) {
			if(!a.a[i]) continue;
			for(int j = 0; j < B - 1; j++) {
				if(i + j == B - 1) s += a.a[i] * b.a[j];
				else c.a[(i + j) % B] += a.a[i] * b.a[j];
			}
		}
		for(int i = 0; i < B - 1; i++) c.a[i] -= s;
		return c;
	}
	friend Num operator + (const Num a, const Num b) {
		Num c;
		for(int i = 0; i < B - 1; i++) c.a[i] = a.a[i] + b.a[i];
		return c;
	}
}w[B], f[N];
int n;
u64 inv5, p5;

void fwt(Num *f, int t) {
	static Num g[B];
	memset(g, 0, sizeof(g));
	t = (t + B) % B;
	for(int i = 0; i < B; i++) {
		for(int j = 0; j < B; j++) {
			g[j] = g[j] + w[j * i * t % B] * f[i];
		}
	}
	memcpy(f, g, sizeof(g));
	return;
}

void reduce(Num &a) {
	a.a[0] -= a.a[5];
	a.a[5] = 0;
	for(int i = 0; i < 8; i += 2) a.a[i] -= a.a[8];
	a.a[8] = 0;
	return;
}

void FWT(Num *f, int len, int t) {
	static Num g[B];
	for(int i = B; i <= len; i *= B) {
		for(int j = 0; j < len; j += i) {
			for(int k = 0; k < i / B; k++) {
				for(int l = 0; l < B; l++) {
					g[l] = f[j + k + l * i / B];
				}
				fwt(g, t);
				for(int l = 0; l < B; l++) {
					f[j + k + l * i / B] = g[l];
				}
			}
		}
	}
	if(t == -1) {
		for(int i = 0; i < len; i++) {
			reduce(f[i]);
			f[i].a[0] *= p5, f[i].a[0] /= 32;
		}
	}
	return;
}
Num power(Num a, int b, Num c = 1) {
	for(; b; b >>= 1, a = a * a)
		if(b & 1)
			c = c * a;
	return c;
}
int main() {
	for(int i = 0; i < B - 1; i++) {
		w[i].a[i] = 1;
		w[B - 1].a[i] = -1;
	}
	inv5 = - (u64(-1) / 5);
	p5 = 1;
	for(int i = 1; i <= 5; i++) p5 *= inv5;
	scanf("%d", &n);
	for(int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		f[x].a[0]++;
	}
	FWT(f, N, 1);
	for(int i = 0; i < N; i++) {
		f[i] = power(f[i], n);
	}
	FWT(f, N, -1);
	for(int i = 0; i < n; i++) {
		printf("%llu\n", f[i].a[0] % mod);
	}
	return 0;
}