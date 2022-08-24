#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

struct cmplx {
	ld x, y;
	ld real() {
		return x;
	}
	cmplx operator+(const cmplx &b) {
		return {x + b.x, y + b.y};
	}
	cmplx operator-(const cmplx &b) {
		return {x - b.x, y - b.y};
	}
	cmplx operator*(const cmplx &b) {
		return {x * b.x - y * b.y, x * b.y + y * b.x};
	}
	cmplx operator/(ld k) {
		return {x / k, y / k};
	}
};
const ld PI = acos(-1.0);

int rev(int x, int k) {
	int ans = 0;
	rep(i, 0, k) {
		ans = (ans * 2 + (x & 1));
		x >>= 1;
	}
	return ans;
}

void fft(cmplx *a, int k, int inv) {
	int n = (1 << k);
	rep(i, 0, n) {
		int x = rev(i, k);
		if (x > i)
			swap(a[x], a[i]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		ld ang = PI / bl;
		if (inv)
			ang = -ang;
		cmplx wadd{cos(ang), sin(ang)};
		for (int i = 0; i < n; i += 2 * bl) {
			cmplx w{1, 0};
			for (int j = i; j < i + bl; ++j, w = w * wadd) {
				cmplx u = a[j], v = a[j + bl] * w;
				a[j] = u + v, a[j + bl] = u - v;
			}
		}
	}
	if (inv) {
		rep(i, 0, n) {
			a[i] = a[i] / n;
		}
	}
}

string s, t;
int k;

cmplx a[6][1 << 18];
cmplx b[6][1 << 18];
cmplx tmp[1 << 18];
vector<pair<int, int>> eds[1 << 18];

void st(cmplx *a, string &s, int x) {
	for (int i = 0; i < s.size(); ++i)
		if (s[i] - 'a' == x)
			a[i] = {1, 0};
		else
			a[i] = {0, 0};
	for (int i = s.size(); i < (1 << k); ++i)
		a[i] = {0, 0};
}

int p[6];

int get(int a) {
	if (a == p[a])
		return a;
	return p[a] = get(p[a]);
}

int un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return 0;
	p[a] = b;
	return 1;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s >> t;
	reverse(ALL(t));
	k = 0;
	while (s.size() + t.size() - 1 > (1 << k))
		++k;
	for (int i = 0; i < 6; ++i) {
		st(a[i], s, i);
		st(b[i], t, i);
		fft(a[i], k, 0);
		fft(b[i], k, 0);
	}
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j) {
			if (i == j)
				continue;
			rep(x, 0, (1 << k)) {
				tmp[x] = a[i][x] * b[j][x];
			}
			fft(tmp, k, 1);
			int sh = t.size() - 1;
			for (int x = t.size() - 1; x < (1 << k); ++x) {
				if (llround(tmp[x].real())) {
					eds[x - sh].emplace_back(i, j);
				}
			}
		}
	for (int i = 0; i <= s.size() - t.size(); ++i) {
		for (int j = 0; j < 6; ++j)
			p[j] = j;
		int ans = 0;
		for (auto x: eds[i])
			if (un(x.first, x.second))
				++ans;
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}