#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FI first
#define SE second
typedef long long ll;
typedef pair <int, int> ii;
#define MOD 1009

typedef complex<double> cd;
const double PI = acos(-1);

void fft(cd* pts, bool inv, int n) {
	if (n == 1) return;
	cd even[n / 2], odd[n / 2];
	for (int i = 0; i * 2 < n; i++) {
		even[i] = pts[2 * i];
		odd[i] = pts[2 * i + 1];
	}
	fft(even, inv, n / 2); fft(odd, inv, n / 2);
	double theta = 2.0 * PI / n * (inv ? -1.0 : 1);
	cd w(1), wn(cos(theta), sin(theta));
	for (int i = 0; 2 * i < n; i++) {
		pts[i] = even[i] + w * odd[i];
		pts[i + n / 2] = even[i] - w * odd[i];
		if (inv) {
			pts[i] /= 2;
			pts[i + n / 2] /= 2;
		}
		w *= wn;
	}
}
vector<ll> mult(vector<ll> const& lres, vector<ll> const& rres) {
	int n = 1 << (32 - __builtin_clz(lres.size() + rres.size() - 1));
	cd lf[n], rf[n];
	for (int i = 0; i < n; i++) {
		if (i < lres.size()) lf[i] = lres[i];
		else lf[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (i < rres.size()) rf[i] = rres[i];
		else rf[i] = 0;
	}
	fft(lf, false, n); fft(rf, false, n);
	for (int i = 0; i < n; i++) lf[i] *= rf[i];
	fft(lf, true, n);
	vector<ll> res;
	for (int i = 0; i < n; i++) {
		res.push_back(round(lf[i].real()));
	}
	return res;
}

// #define DEBUG

int n, m, k;
int cnt[200005];
vector<ll> poly[500005];
set<ii> st;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		cnt[c]++;
	}
	for (int i = 1; i <= m; i++) {
		if (cnt[i] == 0) continue;
		for (int j = 0; j <= cnt[i]; j++) {
			poly[i].push_back(1);
		}
		st.insert(MP(poly[i].size(), i));
	}
	int ptr = m + 1;
	while (st.size() > 1) {
		vector<ll> l = poly[st.begin() -> SE]; st.erase(st.begin());
		vector<ll> r = poly[st.begin() -> SE]; st.erase(st.begin());
		poly[ptr] = mult(l, r);
#ifdef DEBUG
		printf("left:");
		for (ll i : l) printf(" %lld", i);
		printf("\nright:");
		for (ll i : r) printf(" %lld", i);
		printf("\nres:");
		for (ll i : poly[ptr]) printf(" %lld", i);
		printf("\n");
#endif
		while (!poly[ptr].empty() && poly[ptr].back() == 0) poly[ptr].pop_back();
		int sze = poly[ptr].size();
		for (int i = 0; i < sze; i++) {
			poly[ptr][i] %= MOD;
		}
		st.insert(MP(sze, ptr++));
	}
	printf("%lld\n", poly[st.begin() -> SE][k]);
	return 0;
}