#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;

int n, t; LL T;
LL shifted = 0, phase = 0;

void shift(LL d) {
	shifted += d;
	phase = (phase + d) % T;
}

set < pair < pair <LL, LL>, LL>> s;

void make (LL l, LL r) {
	l -= phase; l %= T; l += T; l %= T;
	r -= phase; r %= T; r += T; r %= T;
	LL w = 1e18;
	if (l <= r) {
		auto it = s.lower_bound({{r, -1}, -1});
		if (it != s.begin()) --it;
		vector < pair < pair <LL, LL>, LL> > toinsert;
		for ( ; it != s.end(); ) {
			auto [p, v] = *it;
			auto [x, y] = p;
			if (y <= r) {
				it++;
				continue;
			}
			if (x <= r) {
				toinsert.push_back({{x, r}, v});
			}
			w = min(w, l + T - y + v);
			it = s.erase(it);
		}
		for (it = s.begin(); it != s.end(); ) {
			auto [p, v] = *it;
			auto [x, y] = p;
			if (x >= l) break;
			if (y >= l) {
				w = min(w, v);
				if (l < y) toinsert.push_back({{l + 1, y}, v});
			} else {
				w = min(w, l - y + v);
			}
			it = s.erase(it);
		}
		for (auto i : toinsert) s.insert(i);
	} else {
		auto it = s.lower_bound({{r, -1}, -1});
		if (it != s.begin()) --it;
		vector < pair < pair <LL, LL>, LL> > toinsert;
		for ( ; it != s.end(); ) {
			auto [p, v] = *it;
			auto [x, y] = p;
			if (y <= r) {
				it ++;
				continue;
			}
			if (x >= l) break;
			if (x <= r) {
				toinsert.push_back({{x, r}, v});
			}
			if (y >= l) {
				w = min(w, v);
				if (l < y) toinsert.push_back({{l + 1, y}, v});
			} else {
				w = min(w, l - y + v);
			}
			it = s.erase(it);
		}
		for (auto i : toinsert) s.insert(i);
	}
	if (w < 1e17) s.insert ({{l, l}, w});
}

void insert (LL l, LL r) {
	l -= phase; l %= T; l += T; l %= T;
	r -= phase; r %= T; r += T; r %= T;
	if (l <= r) s.insert ({{l, r}, 0ll});
	else s. insert ({{l, T - 1}, 0ll}), s. insert ({{0, r}, 0ll});
}

int g[N], c[N], d[N];

int main() {
	read(n); read(t); T = t;
	for (int i = 1; i <= n; i++) scanf("%d%d", g + i, c + i);
	for (int i = 1; i < n; i++) scanf("%d", d + i);
	insert (0 - c[1], g[1] - 1 - c[1]);
	shift (d[1]);
	for (int i = 2; i <= n; i++) {
		make(0 - c[i], g[i] - 1 - c[i]);
		if (i < n) shift(d[i]);
	}
	LL ans = 1e18;
	
	for (auto i : s) {
		ans = min(ans, i.second);
	}
	printf("%lld\n", ans + shifted);
}