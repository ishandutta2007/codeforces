#include <iostream>
#include <cstdio>
#include <set>
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef set<PII>::iterator SIT;
typedef set<PII> SI;

PII operator - (const PII &a, const PII &b) {
	return mp(a.x - b.x, a.y - b.y);
}

LL inline cross(PII a, PII b) {
	return a.x * b.y - a.y * b.x;
}

LL inline cross(PII a, PII b, PII c) {
	PII u = b - a, v = c - a;
	return cross(u, v);
}

struct Hull {
	SI su, sd;
	bool inline query(SI &s, PII u, int o) {
		SIT l = s.upper_bound(u), r = s.lower_bound(u);
		if (r == s.end() || l == s.begin()) return false;
		l--;
		return cross(*l, u, *r) * o >= 0;
	}
	void inline insert(SI &s, PII u, int o) {
		if (query(s, u, o)) return;
		SIT it = s.insert(u).first;
		while (1) {
			SIT mid = it;
			if (mid == s.begin()) break; --mid;
			SIT l = mid;
			if (l == s.begin()) break; --l;
			if (cross(*l, *mid, u) * o <= 0) break; 
			s.erase(mid);
		}
		while (1) {
			SIT mid = it; ++mid;
			if (mid == s.end()) break; 
			SIT r = mid; ++r;
			if (r == s.end()) break;
			if (cross(u, *mid, *r) * o <= 0) break; 
			s.erase(mid);
		}
	}
	void inline ins(PII u) {
		insert(su, u, 1), insert(sd, u, -1);
	}
	int inline chk(PII u) {
		return query(su, u, 1) && query(sd, u, -1);
	}
} t;

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int op; LL x, y; scanf("%d%lld%lld", &op, &x, &y);
		if (op == 1) t.ins(mp(x, y));
		else puts(t.chk(mp(x, y)) ? "YES" : "NO");
	}
}