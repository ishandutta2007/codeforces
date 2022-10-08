
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool upper() const {
        return y > 0 || (y == 0 && x > 0);
    }
    ll cross(const pt &p) const {
        return x * p.y - y * p.x;
    }
    bool operator<(const pt &p) const {
        if(upper() != p.upper()) return upper();
        return cross(p) > 0;
    }
};

struct Line {
	mutable double k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(double x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const double inf = 1/.0;
	double div(double a, double b) { // floored division
		return a / b;
    }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(double k, double m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	double query(double x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 2005;

int n;
ll xl[N], xr[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    LineContainer l1, l2;
    rep(i, 0, n) {
        cin >> xl[i] >> xr[i] >> y[i];
        l1.add(y[i], xr[i]);
        l2.add(-y[i], -xl[i]);
    }
    vector<pair<pt, int>> ve;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if(y[i] >= y[j]) continue;
            ve.emplace_back(pt(xl[j] - xr[i], y[i] - y[j]), 1);
            ve.emplace_back(pt(xr[j] - xl[i], y[i] - y[j]), -1);
        }
    }
    ve.emplace_back(pt(0, -1), 0);
    sort(all(ve));
    int cnt = 0;
    double ans = DBL_MAX;
    for(auto &p : ve) {
        pt q = p.first;
        if(cnt == 0 || cnt + p.second == 0) {
            ans = min(ans, l1.query(1.0 * q.x / q.y) + l2.query(1.0 * q.x / q.y));
        }
        cnt += p.second;
    }
    cout << fixed << setprecision(8);
    cout << ans << '\n';
}