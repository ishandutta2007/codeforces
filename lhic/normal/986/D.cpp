#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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


typedef complex<ld> cmplx;


const ll ML = 1000;
const int C = 3;
const ld PI = acos(-1.0);

int rev(int x, int k) {
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = ans * 2 + (x & 1);
		x >>= 1;
	}
	return ans;
}

void fft(cmplx *a, int k, int inv) {
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		int x = rev(i, k);
		if (x > i)
			swap(a[x], a[i]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		ld ang = PI / bl;
		if (inv)
			ang = -ang;
		cmplx wadd = cmplx(cos(ang), sin(ang));
		for (int i = 0; i < n; i += 2 * bl) {
			cmplx w = 1;
			for (int j = i; j < i + bl; ++j, w = w * wadd) {
				cmplx u = a[j];
				cmplx v = a[j + bl] * w;
				a[j] = u + v;
				a[j + bl] = u - v;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; ++i)
			a[i] = a[i] / ld(n);
	}
}

cmplx ac[1500000];
cmplx bc[1500000];

void mult(vector<ll> &a, const vector<ll> &b) {
	int nd = a.size() - 1 + b.size() - 1 + 1;
	int k = 0;
	while ((1 << k) < nd)
		++k;
	for (int i = 0; i < (1 << k); ++i)
		ac[i] = bc[i] = 0;
	for (int i = 0; i < a.size(); ++i)
		ac[i] = a[i];
	for (int i = 0; i < b.size(); ++i)
		bc[i] = b[i];
	fft(ac, k, 0);
	fft(bc, k, 0);
	for (int i = 0; i < (1 << k); ++i)
		ac[i] = ac[i] * bc[i];
	fft(ac, k, 1);
	a.clear();
	for (int i = 0; i < nd; ++i)
		a.push_back(llround(ac[i].real()));
	ll p = 0;
	for (int i = 0; i < a.size() || p; ++i) {
		if (i >= a.size()) {
			a.push_back(0);
		}
		ll cur = a[i] + p;
		a[i] = cur % ML;
		p = cur / ML;
	}
}

void mult2(vector<ll> &a) {
	int nd = a.size() - 1 + a.size() - 1 + 1;
	int k = 0;
	while ((1 << k) < nd)
		++k;
	for (int i = 0; i < (1 << k); ++i)
		ac[i] = 0;
	for (int i = 0; i < a.size(); ++i)
		ac[i] = a[i];
	fft(ac, k, 0);
	for (int i = 0; i < (1 << k); ++i)
		ac[i] = ac[i] * ac[i];
	fft(ac, k, 1);
	a.clear();
	for (int i = 0; i < nd; ++i)
		a.push_back(llround(ac[i].real()));
	ll p = 0;
	for (int i = 0; i < a.size() || p; ++i) {
		if (i >= a.size()) {
			a.push_back(0);
		}
		ll cur = a[i] + p;
		a[i] = cur % ML;
		p = cur / ML;
	}
}

string get(const vector<ll> &a) {
	string ans;
	for (int i = 0; i < a.size(); ++i) {
		string x = to_string(a[i]);
		reverse(x.begin(), x.end());
		while (x.size() < C)
			x += "0";
		ans += x;
	}
	while (ans.back() == '0')
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	return ans;
}

string s;

bool gr(const string &a, const string &b) {
	if (a.size() > b.size())
		return 1;
	if (a.size() < b.size())
		return 0;
	return a > b;
}

void mul(string &s, int k) {
	reverse(s.begin(), s.end());
	int p = 0;
	for (int i = 0; i < s.size(); ++i) {
		int x = (s[i] - '0') * k + p;
		s[i] = '0' + x % 10;
		p = x / 10;
	}
	if (p) {
		s += '0' + p;
	}
	reverse(s.begin(), s.end());
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	if (s == "1") {
		cout << 1 << "\n";
		return 0;
	}
	int x = s.size();
	int ndlen = log(10) * x / log(3) - 3;
	ndlen = max(ndlen, 0);
	vector<ll> vv = {1};
	vector<ll> p = {3};
	int now = ndlen;
	for (int i = 0; now; ++i) {
		if ((now >> i) & 1) {
			mult(vv, p);
			now -= (1 << i);
		}
		if (now)
			mult2(p);
	}
	string t = get(vv);
	string pr1, pr2;
	while (gr(s, t)) {
		pr2 = pr1;
		pr1 = t;
		mul(t, 3);
		++ndlen;
	}
	int ans = ndlen * 3;
	mul(pr2, 4);
	if (!gr(s, pr2)) {
		ans = min(ans, (ndlen - 2) * 3 + 4);
	}
	mul(pr1, 2);
	if (!gr(s, pr1)) {
		ans = min(ans, (ndlen - 1) * 3 + 2);
	}
	cout << ans << "\n";
	return 0;
}