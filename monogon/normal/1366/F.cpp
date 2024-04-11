
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
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
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
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

// query path of length k
// dist + w * (k - num_edges)
// (w) * k + (dist - w * num_edges)

const int N = 2005, M = 1e9 + 7;
int n, m, q, u, v;
ll w, dist[N][N];
using edge = pair<ll, int>;
vector<edge> adj[N];
LineContainer lines;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    rep(i, 0, m) {
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    rep(it, 0, N) rep(i, 0, N) dist[it][i] = -1;
    dist[0][1] = 0;
    ll ans = 0;
    rep(k, 1, n + 2) {
        rep(u, 1, n + 1) {
            if(dist[k - 1][u] != -1) {
                for(edge &e : adj[u]) {
                    tie(w, v) = e;
                    lines.add(w, dist[k - 1][u] - w * (k - 1));
                }
            }
        }
        if(k - 1 <= q) {
            ans += lines.query(k - 1);
            ans %= M;
        }
        rep(u, 1, n + 1) {
            if(dist[k - 1][u] != -1) {
                for(auto &e : adj[u]) {
                    tie(w, v) = e;
                    if(dist[k - 1][u] + w > dist[k][v]) {
                        dist[k][v] = dist[k - 1][u] + w;
                    }
                }
            }
        }
    }
    // n+2, ..., q
    ll L = n + 1;
    for(const Line &l : lines) {
        if(L > q) break;
        if(L <= l.p) {
            ll R = min((ll) q, l.p);
            // sum_{i = L}^R (k i + m)
            // k sum_{i = L}^R (i) + (R - L + 1) * m
            // k [R (R + 1) / 2 - (L - 1) L / 2] + (R - L + 1) * m
            ans += (l.k % M) * ((R * (R + 1) / 2 - (L - 1) * L / 2) % M) + ((((R - L + 1) % M) * l.m) % M);
            L = R + 1;
        }
    }
    ans = ((ans % M) + M) % M;
    cout << ans << '\n';
}