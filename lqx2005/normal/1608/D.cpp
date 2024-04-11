#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define vi vector<int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
const int LG = 21, N = 1 << LG, P = 998244353;
vector<int> rev;
int fac[N], ifac[N], inv[N], rts[N];

void Mod(int &x) {x += (x >> 31) & P; }

void initmath(int n = N - 1) {
	inv[1] = 1;
	for(int i = 2; i <= n; i++) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	fac[0] = ifac[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % P;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % P;
	}
	return;
}

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) 
		if(b & 1) 
			c = 1ll * c * a % P; 
	return c;
}

void initrt(int n = N) {
	for(int i = 2; i <= n; i <<= 1) {
		int e = power(3, (P - 1) / i);
		rts[i >> 1] = 1;
		for(int j = (i >> 1) + 1; j < i; j++)
			rts[j] = 1ll * rts[j - 1] * e % P;
	}
	return;
}


void dft(vi &a) {
	int n = sz(a);
	if(sz(rev) != n) {
		rev.resize(n);
		rev[0] = 0;
		for(int i = 1; i < n; i++) 
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1)); 
	}
	for(int i = 0; i < n; i++)
		if(i < rev[i]) 
			swap(a[i], a[rev[i]]);
	for(int i = 2; i <= n; i <<= 1) {
		for(int j = 0; j < n; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				int u = a[j + k];
				int v = 1ll * a[j + k + (i >> 1)] * rts[(i >> 1) + k] % P;
				Mod(a[j + k] = u + v - P), Mod(a[j + k + (i >> 1)] = u - v);
			}
		}
	}
	return;
}

void idft(vi &a) {
	int n = a.size();
	dft(a);
	reverse(a.begin() + 1, a.end());
	int inv = power(n, P - 2);
	for(int i = 0; i < n; i++)
		a[i] = 1ll * a[i] * inv % P;
	return;
}

struct Poly {
	vi a;
	Poly() {}
	Poly(int a0) { if(a0) a = {a0}; }
	Poly(const vi &a1) : a(a1) {
		while(!a.empty() && !a.back()) 
			a.pop_back();
	}
	void rse(int n) { a.resize(n); }
	int sze() const { return a.size(); }
	int operator [] (const int idx) const {
		if(idx < 0 || idx >= int(a.size()))
			return 0;
		return a[idx];
	}
	
	Poly mulxk(int k) const {
		vi b = a;
		b.insert(b.begin(), k, 0);
		return b;
	}
	
	Poly modxk(int k) const {
		k = min(k, sze());
		return Poly(vi(a.begin(), a.begin() + k));
	}
	
	Poly divxk(int k) const {
		if(sze() <= k) return Poly();
		return Poly(vi(a.begin() + k, a.end()));
	}
	
	friend Poly operator + (const Poly a, const Poly b) {
		vi res(max(a.sze(), b.sze()));
		for(int i = 0; i < sz(res); i++) {
			Mod(res[i] = a[i] + b[i] - P);
		}
		return Poly(res);
	}
	
	
	friend Poly operator - (Poly a, Poly b) {
		vi res(max(a.sze(), b.sze()));
		for(int i = 0; i < sz(res); i++) {
			Mod(res[i] = a[i] - b[i]);
		}
		return Poly(res);
	}
	
	friend Poly operator * (Poly a, Poly b) {
		int n = 1, tot = int(a.sze() + b.sze()) - 1;
		while(n <= tot) 
			n <<= 1;
		a.rse(n);
		b.rse(n);
		dft(a.a), dft(b.a);
		for(int i = 0; i < n; i++) a.a[i] = 1ll * a.a[i] * b[i] % P;
		idft(a.a);
		return Poly(a.a);
	}
	
	Poly &operator += (Poly b) {
		return *this = *this + b;
	}
	
	Poly &operator -= (Poly b) {
		return *this = *this - b;
	}
	
	Poly &operator *= (Poly b) {
		return *this = *this * b;
	}
	
	Poly deriv() const {
		if(a.empty()) {
			return Poly();
		}
		vi res(sze() - 1);
		for(int i = 1; i < sze(); i++) {
			res[i - 1] = 1ll * i * a[i] % P;
		}
		return Poly(res);
	}
	
	Poly integr() const {
		if(a.empty()) {
			return Poly();
		}
		vi res(sze() + 1);
		res[0] = 0;
		for(int i = 0; i < sze(); i++) {
			res[i + 1] = 1ll * a[i] * inv[i + 1] % P;
		}
		return Poly(res);
	}
};
int n;
Poly p[N];
Poly divide(int l, int r) {
	if(l == r) return p[l];
	int mid = (l + r) / 2;
	return divide(l, mid) * divide(mid + 1, r);
}
int main() {
	initmath(), initrt();
	cin >> n;
	int f0 = 1, f1 = 1;
	int res = 1;
	for(int i = 1; i <= n; i++) {
		string dom;
		cin >> dom;
		if(dom[0] == 'B' || dom[1] == 'W') f0 = 0;
		if(dom[0] == 'W' || dom[1] == 'B') f1 = 0;
		if(dom[0] != '?' && dom[1] != '?') {
			if(dom[0] == dom[1]) {
				res = 0;
				if(dom[0] == 'W') p[i] = vi{1};
				else p[i] = vi{0, 0, 1};
			}
			else {
				p[i] = vi{0, 1};
			}
		} else {
			if(dom[0] == '?' && dom[1] == '?') {
				res = 2ll * res % P;
				p[i] = vi{1, 2, 1};
			} else {
				if(dom[0] == 'W' || dom[1] == 'W') p[i] = vi{1, 1};
				else p[i] = vi{0, 1, 1};
			}
		}
	}
	int ans = (f0 + f1 + P - res) % P;
	Poly ns = divide(1, n);
	ans = (ans + ns[n]) % P;
	cout << ans << endl;
	return 0;
}