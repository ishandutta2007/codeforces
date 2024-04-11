
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

// first we must cut a tree of height 1
// bn = 0, so we want minimum cost to cut down last tree. Then we get all others for free
// dp[i] = minimum cost to cut down tree i
// dp[i] = min_{1 <= j < i} dp[j] + b_j (a_i - 1) + b_i
// b_i + min_j b_j (a_i) + (dp[j] - b_j)

const int N = 1e5 + 5;
int n;
ll a[N], b[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    LineContainer lines;
    b[0] = 2e9;
    lines.add(-b[0], -dp[0]);
    rep(i, 1, n + 1) {
        dp[i] = b[i] - lines.query(a[i] - 1);
        lines.add(-b[i], -dp[i]);
    }
    cout << dp[n] << '\n';
}