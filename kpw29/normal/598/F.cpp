#include <bits/stdc++.h>

const int maxn = 1003;
const double eps = 1e-5;

int n, m;

struct vec {
	double x, y;
	vec operator+(const vec &k) const {
		return {x + k.x, y + k.y};
	}
	vec operator-(const vec &k) const {
		return {x - k.x, y - k.y};
	}
	double cross(const vec &k) const {
		return x * k.y - y * k.x;
	}
	double len() const {
		return sqrt(x * x + y * y);
	}
} gon[maxn], p, q;

int sign(const double &u) {
	return u < -eps ? -1 : u > eps;
}

double inter(const vec &a, const vec &u, const vec &b, const vec &v) {
	return ((a - b).cross(v)) / u.cross(v);
}

double solve(const vec &a, const vec &w) {
	static std::vector<std::pair<double, int> > it;
	it.clear();
	for(int i = 0, u, v; i < n; ++i) {
		u = sign(w.cross(gon[i] - a));
		v = sign(w.cross(gon[(i + 1) % n] - a));
		if(u == v)
			continue;
		it.push_back(std::make_pair(
			inter(a, w, gon[i], gon[(i + 1) % n] - gon[i]),
			(u > v ? 1 : -1) * (u && v ? 2 : 1)));
	}
	std::sort(it.begin(), it.end());
	int inside = 0;
	double ans = 0;
	for(int i = 0; i + 1 < it.size(); ++i) {
		inside += it[i].second;
		if(inside)
			ans += it[i + 1].first - it[i].first;
	}
	return ans * w.len();
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%lf%lf", &gon[i].x, &gon[i].y);
	for(int i = 0; i < m; ++i) {
		scanf("%lf%lf%lf%lf", &p.x, &p.y, &q.x, &q.y);
		printf("%.18lf\n", solve(p, q - p));
	}
	return 0;
}