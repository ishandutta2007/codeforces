#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;

const int maxn = 1e5 + 10;
int n; db m;
struct node {
	db x, y;
	friend node operator - (node a, node b) { return {a.x - b.x, a.y - b.y}; }
	friend bool operator < (node a, node b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
	friend db operator * (node a, node b) { return a.x * b.y - a.y * b.x; }
};
set <node> s;
void ins(node p) {
	auto lt = s.lower_bound(p), rt = lt--;
	if (rt != s.end() && (p - *lt) * (p - *rt) >= 0) return;
	while (rt != s.end()) {
		auto it = rt++;
		if (rt == s.end() || (p - *it) * (p - *rt) >= 0) break;
		s.erase(it);
	}
	while (lt != s.begin()) {
		auto it = lt--;
		if ((p - *it) * (p - *lt) < 0) break;
		s.erase(it);
	}
	s.insert(p);
}

bool query(int t, int h) {
	db x = 1.0 * h / t;
	auto lt = s.lower_bound({x, 0});
	if (lt == s.end()) return 0;
	auto rt = lt--;
	node p = *rt - *lt; db k = p.y / p.x;
	db b = (rt -> y) - k * (rt -> x);
	return (k * x + b) * t <= m;
}

int main() {
	s.insert({0, 0});
	scanf("%d%Lf", &n, &m);
	for (int i = 1, lstans = 0; i <= n; ++i) {
		int op, a, b; scanf("%d%d%d", &op, &a, &b);
		a = (a + lstans) % 1000000 + 1;
		b = (b + lstans) % 1000000 + 1;
		if (op == 1) ins({(db) a, (db) b});
		else {
			if (query(a, b)) printf("YES\n"), lstans = i;
			else printf("NO\n");
		}
	}
	return 0;
}