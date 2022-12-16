#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10, inf = 4e18;
ll n,s;
struct node {
	ll tag;
	map <ll, ll> f;
	multiset <ll> mn;
	void clear() { tag = 0, f.clear(), mn.clear(); }
	ll get(ll y) {
		auto it = f.find(y);
		if (it == f.end()) return inf;
		return it -> second + tag;
	}
	void upd(ll y, ll v) {
		ll t = get(y);
		if (t < inf) mn.erase(mn.find(t - tag));
		mn.insert(f[y] = v - tag);
	}
	void del(ll y) {
		auto it = f.find(y);
		if (it == f.end()) return;
		mn.erase(mn.find(it -> second));
		f.erase(it);
	}
	friend void merge(node &p, node &q) {
		if (p.f.size() < q.f.size()) swap(p, q);
		for (auto o : q.f) {
			ll y = o.first, v = o.second + q.tag - p.tag;
			auto it = p.f.find(y);
			if (it == p.f.end()) p.f[y] = v, p.mn.insert(v);
			else if (it -> second > v) {
				p.mn.erase(p.mn.find(it -> second));
				p.mn.insert(it -> second = v);
			}
		}
	}
}sta[maxn];
ll tp;

int main() {
	scanf("%lld%lld", &n, &s);
	sta[tp = 1].f[0] = 0, sta[tp].mn.insert(0);
	for (ll i = 1; i <= n; ++i) {
		char op[10]; ll y, v;
		scanf("%s", op);
		if (op[0] == 's') {
			scanf("%lld%lld", &y, &v);
			ll mnv = (*sta[tp].mn.begin()) + sta[tp].tag;
			sta[tp].tag += v;
			if (y != s) sta[tp].upd(y, mnv);
		}
		else if (op[0] == 'i') {
			scanf("%lld", &y);
			v = sta[tp].get(y);
			sta[tp].del(y);
			sta[++tp].tag = 0;
			sta[tp].f[y] = v;
			sta[tp].mn.insert(v);
		}
		else {
			merge(sta[tp - 1], sta[tp]);
			sta[tp--].clear();
		}
	}
	printf("%lld\n", (*sta[tp].mn.begin()) + sta[tp].tag);
	return 0;
}