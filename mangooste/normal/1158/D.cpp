#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vec point

struct point {
	ll x, y;
	int id;

	point(ll x = 0, ll y = 0, int id = 0) : x(x), y(y), id(id) {}

	point operator - (point p) {
		return vec(x - p.x, y - p.y, -1);
	}

	ll operator % (vec v) {
		return x * v.y - y * v.x;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<point> ps(n);
	for (int i = 0; i < n; i++) {
		cin >> ps[i].x >> ps[i].y;
		ps[i].id = i + 1;
	}
	string s;
	cin >> s;
	for (int i = 1; i < n; i++) {
		if (ps[i].x < ps[0].x || ps[i].x == ps[0].x && ps[i].y < ps[0].y) {
			swap(ps[0], ps[i]);
		}
	}

	vector<point> ord = {ps[0]};
	vector<char> used(n + 1, 0);
	used[ord[0].id] = 1;
	for (int i = 0; i < n - 2; i++) {
		point now;
		for (auto p : ps) {
			if (used[p.id]) continue;
			if (!now.id) {
				now = p;
				continue;
			}
			vec v1 = now - ord.back();
			vec v2 = p - ord.back();
			if ((v1 % v2 > 0) ^ (s[i] == 'L')) now = p;
		}
		used[now.id] = 1;
		ord.push_back(now);
	}
	for (auto p : ps) {
		if (!used[p.id]) ord.push_back(p);
	}
	for (auto x : ord) cout << x.id << ' ';
	cout << '\n';
}