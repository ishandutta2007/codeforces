#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int const nax = 2048;
using ld = double;
using ll = long long;
const ll INF = 1e12;
struct frac_t {
    ll x, y;

    frac_t (ll _x, ll _y) : x(_x), y(_y) {
        if (y < 0) x = -x, y = -y;
        ll g = abs(__gcd(x, y));
        x /= g, y /= g;
    }

    ld to_ld () const {
        return ld(x) / ld(y);
    }

    bool operator < (const frac_t &other) const {
        return x * other.y < y * other.x;
    }

    bool operator == (const frac_t &other) const {
        return x * other.y == y * other.x;
    }

    bool operator <= (const frac_t &other) const {
        return *this < other || *this == other;
    }

};


///Description: Container where you can add line in form y = kx + m and query maximum values at point x
///ref: not sure.
struct Line {
	mutable ll k, m;
	mutable ld p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ld inf = 1e20;
	ld div(ld a, ld b) {
        return a / b;
    }
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
	ld query(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return 1.0 * l.k * x + l.m;
	}
};



struct segment {
    int l, r, y;

    segment (int l = 0, int r = 0, int y = 0) : l(l), r(r), y(y) {}
    void read () {
        cin >> l >> r >> y;
    }

    bool operator <(const segment &other) const {
        return y < other.y;
    }
};

int n;
segment a[nax];
vector <pair <frac_t, int>> events;
LineContainer cht_max, cht_min;


int main () {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    for (int i = 1 ; i <= n ; ++ i) {
        a[i].read();
        cht_max.add(a[i].y, a[i].r);
        cht_min.add(-a[i].y, -a[i].l);
    }

    sort(a + 1, a + 1 + n);


    for (int i = 1 ; i < n ; ++ i) {
        for (int j = i + 1 ; j <= n ; ++ j) {
            if (a[i].y == a[j].y) continue;
            ll dif_y = a[j].y - a[i].y;

            frac_t x = frac_t((a[i].l - a[j].r), dif_y);
            frac_t y = frac_t((a[i].r - a[j].l), dif_y);

            events.emplace_back(x, 1);
            events.emplace_back(y, -1);

        }
    }

    if (events.empty()) {
        ll max_r = -INF;
        ll min_l = INF;
        for (int i = 1 ; i <= n ; ++ i)
            max_r = max(max_r, (ll)a[i].r), min_l = min(min_l, (ll)a[i].l);
        cout << max_r - min_l;
        return 0;
    }

    sort(events.begin(), events.end());

    ld ans = 1e20;
    int cnt = 0;

    ans = min(ans, cht_max.query(-INF) + cht_min.query(-INF));

    for (auto [f, t] : events) {
        ld p = f.to_ld();
        if (cnt == 0) {
            ans = min(ans, cht_max.query(p) + cht_min.query(p));
        }

        cnt += t;

        if (cnt == 0)
            ans = min(ans, cht_max.query(p) + cht_min.query(p));
    }


    cout.precision(20);
    cout << fixed << ans << '\n';

}
/*
    Very hard game. :(
*/