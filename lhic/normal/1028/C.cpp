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

struct rect {
	int x1, y1, x2, y2;
};

rect cross(rect a, rect b) {
	rect ans;
	ans.x1 = max(a.x1, b.x1);
	ans.x2 = min(a.x2, b.x2);
	ans.y1 = max(a.y1, b.y1);
	ans.y2 = min(a.y2, b.y2);
	return ans;
}

bool cor(rect a) {
	if (a.x1 <= a.x2 && a.y1 <= a.y2)
		return 1;
	return 0;
}

int n;
rect a[200000];
rect b[200000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
	rect cur = a[0];
	for (int i = 0; i < n - 1; ++i) {
		cur = cross(cur, a[i]);
	}
	if (cor(cur)) {
		cout << cur.x1 << " " << cur.y1 << "\n";
		return 0;
	}
	cur = a[1];
	for (int i = 1; i < n; ++i)
		cur = cross(cur, a[i]);
	if (cor(cur)) {
		cout << cur.x1 << " " << cur.y1 << "\n";
		return 0;
	}
	b[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		b[i] = cross(b[i + 1], a[i]);
	}
	cur = a[0];
	for (int i = 0; i + 2 < n; ++i) {
		cur = cross(cur, a[i]);
		if (cor(cross(cur, b[i + 2]))) {
			cur = cross(cur, b[i + 2]);
			cout << cur.x1 << " " << cur.y1 << "\n";
			return 0;
		}
	}
	return 0;
}