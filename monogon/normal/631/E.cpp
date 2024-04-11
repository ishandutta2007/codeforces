
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
    vector<ll> a(n + 1), p(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }
    ll ch = 0;
    ll ans = 0;
    rep(i, 1, n + 1) {
        ch += a[i] * i;
    }
    LineContainer S;
    rep(i, 1, n + 1) {
        S.add(a[i], p[i] - a[i] * i);
        ans = max(ans, -p[i] + S.query(i));
    }
    reverse(a.begin() + 1, a.end());
    rep(i, 1, n + 1) {
        p[i] = a[i] + p[i - 1];
    }
    S.clear();
    rep(i, 1, n + 1) {
        S.add(-a[i], -p[i] + a[i] * i);
        ans = max(ans, p[i] + S.query(i));
    }

    cout << ch + ans << '\n';
}