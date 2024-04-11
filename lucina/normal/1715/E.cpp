#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int K = 21;
int n, m, k;
vector <pair <int, int>> g[nax];
array <int, 3> e[nax];
int64_t dp[nax];
bool vis[nax];
int64_t ans[nax];

template <typename T>
using min_heap = priority_queue <T, vector <T>, greater<T>>;

/**
    at most k flights
    So, just change the way we implement shortest path
*/
const int64_t INF = 1e17;

void update_dp() {
    min_heap <pair <int64_t, int>> pq;

    for (int i = 1 ; i <= n ; ++ i) {
        if (dp[i] != INF) {
            pq.emplace(dp[i], i);
        }
    }
    fill(vis + 1, vis + 1 + n, false);

    while (!pq.empty()) {
        auto [val, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (auto [to, w] : g[v]) {
            if (val + w < dp[to]) dp[to] = val + w, pq.emplace(dp[to], to);
        }
    }
}

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
using ll = int64_t;
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
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 1 ; i <= m ; ++ i) {
        auto &[u, v, w] = e[i];
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        dp[i] = INF;
    }
    dp[1] = 0;
    update_dp();

    for (int j = 0 ; j < k ; ++ j) {
        update_dp();
        LineContainer c;
        /**
            min_y (dp[y] + y * y - 2 *y * x)
            max_y -(2 * y * x - dp[y] - y * y)
        */
        static int64_t n_dp[nax];
        for (int i = 1 ; i <= n;  ++ i)
            n_dp[i] = dp[i];
        c.add(2 * 1, -(dp[1] + 1 * 1));
        for (int i = 2 ; i <= n ; ++ i) {
            int64_t f = -c.query(i);
            n_dp[i] = min(n_dp[i], f + 1ll * i * i);
            c.add(2 * i, -(dp[i] + i * i));
        }
        c.clear();

        c.add(2 * n, -(dp[n] + 1ll * n * n));
        for (int i = n ; i >= 1 ; -- i) {
            int64_t f = -c.query(i);
            n_dp[i] = min(n_dp[i], f + 1ll * i * i);
            c.add(2 * i, -(dp[i] + i * i));
        }
        for (int i = 1 ; i <= n;  ++ i) {
            dp[i] = n_dp[i];
        }
    }
    update_dp();

    for (int i = 1 ; i <= n ; ++ i) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
}