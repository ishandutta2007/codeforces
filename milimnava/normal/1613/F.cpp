#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int P = 998244353, R = 3;

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  if (x < 0)
    x += P;
  return x;
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}

const int L2 = 11;

struct NTT {
  int brev[1 << L2];

  NTT() {
    for (int i = 1; i < (1 << L2); ++i)
      brev[i] = brev[i >> 1] >> 1 | ((i & 1) << (L2 - 1));
  }

  void fft(int* a, int lgn, int d) {
    int n = 1 << lgn;
    for (int i = 0; i < n; ++i) {
      int rev = (brev[i >> L2] | (brev[i & ((1 << L2) - 1)] << L2)) >> ((L2 << 1) - lgn);
      if (i < rev)
        swap(a[i], a[rev]);
    }
    int rt = d == 1 ? R : inv(R);
    for (int i = 0; i < lgn; ++i) {
      int t = 1 << i;
      int omega = mpow(rt, (P - 1) >> (i + 1));
      for (int j = 0; j < n; j += t << 1) {
        int w = 1;
        for (int k = 0; k < t; ++k) {
          int a0 = a[j + k], a1 = a[j + k + t];
          a[j + k] = (a0 + w * (ll)a1) % P;
          a[j + k + t] = (a0 + (P - w) * (ll)a1) % P;
          w = w * (ll)omega % P;
        }
      }
    }
    if (d == -1) {
      int in = inv(n);
      for (int i = 0; i < n; ++i)
        a[i] = a[i] * (ll)in % P;
    }
  }
} ntt;

struct Poly {
  vector<int> a;
  
  Poly(int v = 0) : a(1) {
    if ((v %= P) < 0)
      v += P;
    a[0] = v;
  }
  
  Poly(const vector<int>& a) : a(a) {}

  Poly(initializer_list<int> init) : a(init) {}

  Poly operator*(const Poly& rhs) const;
  
  int operator[](int k) const { return k < a.size() ? a[k] : 0; }
  int& operator[](int k) {
    if (k >= a.size())
      a.resize(k + 1);
    return a[k];
  }
  
  int deg() const { return a.size() - 1; }
};

Poly emptyPoly(int deg) { return vector<int>(deg + 1); }

Poly Poly::operator*(const Poly& rhs) const {
  int n = deg(), m = rhs.deg();
  if (n <= 10 || m <= 10) {
    Poly ret = emptyPoly(n + m);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        ret[i + j] = (ret[i + j] + a[i] * (ll)rhs[j]) % P;
    return ret;
  }
  n += m;
  int l = 0;
  while ((1 << l) <= n)
    ++l;
  vector<int> res(1 << l), tmp(1 << l);
  memcpy(res.begin().base(), a.begin().base(), a.size() * sizeof(int));
  ntt.fft(res.begin().base(), l, 1);
  memcpy(tmp.begin().base(), rhs.a.begin().base(), rhs.a.size() * sizeof(int));
  ntt.fft(tmp.begin().base(), l, 1);
  for (int i = 0; i < (1 << l); ++i)
    res[i] = res[i] * (ll)tmp[i] % P;
  ntt.fft(res.begin().base(), l, -1);
  res.resize(n + 1);
  return res;
}

const int mod = 998244353;

vector<Poly> p;
Poly divide(int l, int r) {
	if (l == r) return p[l];
	int mid = (l + r) / 2;
	return divide(l, mid) * divide(mid + 1, r);
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> deg(n, 0), fac(n + 1, 0);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		++deg[u]; ++deg[v];
	}
	p.resize(n + 1);
	++deg[0];
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (deg[i] > 1) {
			++len;
			p[len] = emptyPoly(1);
			p[len][0] = 1; p[len][1] = deg[i] - 1;
		}
	}
	Poly f = divide(1, len);
	int res = 0;
	for (int i = 0; i < f.a.size(); i++) {
		int x = 1ll * f[i] * fac[n - i] % mod;
		if (i % 2 == 0) res = (res + x) % mod;
		else res = (res - x + mod) % mod;
	}
	cout << res << endl;
	return 0;
}