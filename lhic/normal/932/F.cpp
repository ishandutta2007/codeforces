#pragma GCC optimize "-O3"
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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

/*
struct st {
#error add custom comparator
	set<pair<ll, ll> > ss;
	void add(ll a, ll b) {
		for (int i = 0; i < n; ++i) {

		}
	}
	ll get(ll x) {

	}
};*/

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return ld(x->b - y->b)*(z->m - y->m) >= ld(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

typedef HullDynamic st;

st *merge(st *a, st *b) {
	if (a->size() < b->size())
		swap(a, b);
	for (auto x: *b) {
		a->insert_line(x.m, x.b);
	}
	return a;
}

const int MAXN = 120000;

int was[MAXN];
ll ans[MAXN];

vector<int> eds[MAXN];
int n;
ll a[MAXN];
ll b[MAXN];

st *dfs1(int v) {
	was[v] = 1;
	st *now = new st();
	int fl = 0;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		fl = 1;
		st *tmp = dfs1(u);
		now = merge(now, tmp);
	}
	if (!fl) {
		ans[v] = 0;
	}
	else {
		ans[v] = now->eval(a[v]);
	}
	now->insert_line(-b[v], ans[v]);
	return now;
}

const int MX = 100000;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
		assert(abs(a[i]) <= MX);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", b + i);
		assert(abs(b[i]) <= MX);
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	for (int i = 0; i < n; ++i)
		printf("%lld ", -ans[i]);
	printf("\n");
	return 0;
}