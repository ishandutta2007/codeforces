#ifndef BZ
#pragma GCC optimize "-O3"
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
typedef long double ld;
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

struct point {
	ll x, y;
	int c;
	int n;
	point() {
		x = y = c = 0;
	}
	point(ll x, ll y): x(x), y(y) {}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
};

const int MAXN = 1200;

int n;
point p[MAXN];

bool bad(point a, point b, point c) {
	return (b - a) * (c - a) < 0;
}
int ds[MAXN];

vector<pair<int, int>> ans;

bool in(point a, point b, point c, point d) {
	ll go = abs((a - d) * (b - d)) + abs((b - d) * (c - d)) + abs((c - d) * (a - d)) - abs((b - a) * (c - a));
	return go == 0;
}

void run(point a, point b, point c) {
	for (int i = 0; i < n; ++i) {
		if (p[i].c == c.c && in(a, b, c, p[i]) && p[i].n != c.n) {
			ans.emplace_back(p[i].n, c.n);
			run(a, b, p[i]);
			run(p[i], c, a);
			run(p[i], c, b);
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (in(a, b, c, p[i]) && p[i].n != a.n && p[i].n != b.n && p[i].c == a.c)
			ans.emplace_back(p[i].n, a.n);
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].c;
		p[i].n = i;
	}
	sort(p, p + n, [] (point a, point b) {
			return make_pair(a.x, a.y) < make_pair(b.x, b.y);
			});
	sort(p + 1, p + n, [] (point a, point b) {
				return (a - p[0]) * (b - p[0]) > 0;
			});
	vector<point> st;
	for (int i = 0; i < n; ++i) {
		while (st.size() >= 2 && bad(st[st.size() - 2], st.back(), p[i]))
			st.pop_back();
		st.push_back(p[i]);
	}
	for (int i = 0; i + 1 < st.size(); ++i)
		if (st[i].c != st[i + 1].c) {
			rotate(st.begin(), st.begin() + i + 1, st.end());
			break;
		}
	int cnt = 0;
	for (int i = 0; i + 1 < st.size(); ++i) {
		if (st[i].c != st[i + 1].c)
			++cnt;
	}
	if (cnt > 1) {
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i < st.size(); ++i)
		ds[st[i].n] = 1;
	for (int i = 0; i + 1 < st.size(); ++i)
		if (st[i].c == st[i + 1].c) {
			ans.emplace_back(st[i].n, st[i + 1].n);
		}
	if (cnt == 0) {
		int gp = -1;
		for (int i = 0; i < n; ++i)
			if (p[i].c != st[0].c) {
				gp = i;
				break;
			}
		if (gp == -1) {
			for (int i = 0; i < n; ++i)
				if (!ds[p[i].n])
					ans.emplace_back(st[0].n, p[i].n);
		}
		else {
			st.push_back(st[0]);
			for (int i = 0; i + 1 < st.size(); ++i)
				run(st[i], st[i + 1], p[gp]);
			st.pop_back();
		}
	}
	else {
		int now = 0;
		while (st[now].c == st[0].c)
			++now;
		for (int i = now; i + 1 < st.size(); ++i)
			run(st[i], st[i + 1], st[0]);
		for (int i = 0; i + 1 < now; ++i)
			run(st[i], st[i + 1], st[now]);
	}
	cout << ans.size() << "\n";
	for (auto p: ans)
		cout << p.first << " " << p.second << "\n";
	return 0;
}