
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 2) {
        cout << 2 << '\n';
        return 0;
    }
    int root = 1;
    while(sz(g[root]) == 1) root++;
    vector<ll> dp1(n + 1), dp2(n + 1), s(n + 1);
    ll ans = LLONG_MAX;
    auto dfs = [&](auto dfs, int x, int p) -> void {
        vi ch;
        s[x] = 1;
        for(int y : g[x]) {
            if(y != p) {
                dfs(dfs, y, x);
                ch.push_back(y);
                s[x] += s[y];
            }
        }
        LineContainer se;
        dp1[x] = (ch.empty() ? 1 : LLONG_MAX);
        dp2[x] = LLONG_MAX;
        for(int y : ch) {
            dp1[x] = min(dp1[x], (s[x] - s[y]) * (s[x] - s[y]) + dp1[y]);
            if(!se.empty()) {
                dp2[x] = min(dp2[x], (n - s[y]) * (n - s[y]) + dp1[y] - se.query(n - s[y]));
            }
            se.add(2 * s[y], -(dp1[y]) - s[y] * s[y]);
        }
        ans = min(ans, dp2[x]);
    };
    dfs(dfs, root, root);
    cout << (2LL * n * n - n - ans) / 2 << '\n';
}