#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ld EPS = 1E-12;

const int maxN = 25000 + 10;
int x[maxN], y[maxN], dx[maxN], dy[maxN], ss[maxN];
int n;

struct pt {
    ld x, y;
    pt(ld x, ld y) : x(x), y(y) {}
};

struct seg {
    pt p, q;
    int id;
    seg(pt& x, pt& y, int& id) : p(x), q(y), id(id) {}

    double get_y (double x) const {
        if (abs (p.x - q.x) < EPS)  return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};


inline bool intersect1d (ld l1, ld r1, ld l2, ld r2) {
    if (l1 > r1)  swap (l1, r1);
    if (l2 > r2)  swap (l2, r2);
    return max (l1, l2) <= min (r1, r2) + EPS;
}

inline int vec (const pt & a, const pt & b, const pt & c) {
    ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s)<EPS ? 0 : s>0 ? +1 : -1;
}

bool intersect (const seg & a, const seg & b) {
    return intersect1d (a.p.x, a.q.x, b.p.x, b.q.x)
           && intersect1d (a.p.y, a.q.y, b.p.y, b.q.y)
           && vec (a.p, a.q, b.p) * vec (a.p, a.q, b.q) <= 0
           && vec (b.p, b.q, a.p) * vec (b.p, b.q, a.q) <= 0;
}


bool operator< (const seg & a, const seg & b) {
    double x = max (min (a.p.x, a.q.x), min (b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}


struct has_inter {

    struct event {
        ld x;
        int tp, id;

        event() {}

        event(ld x, int tp, int id)
            : x(x), tp(tp), id(id) {}

        bool operator<(const event &e) const {
            if (abs(x - e.x) > EPS) return x < e.x;
            return tp > e.tp;
        }
    };

    set<seg> s;
    vector<set<seg>::iterator> where;

    inline set<seg>::iterator prev(set<seg>::iterator it) {
        return it == s.begin() ? s.end() : --it;
    }

    inline set<seg>::iterator next(set<seg>::iterator it) {
        return ++it;
    }

    pair<int, int> solve(const vector<seg> &a) {
        int n = (int) a.size();
        vector<event> e;
        for (int i = 0; i < n; ++i) {
            e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
            e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
        }
        sort(e.begin(), e.end());

        s.clear();
        where.resize(a.size());
        for (size_t i = 0; i < e.size(); ++i) {
            int id = e[i].id;
            if (e[i].tp == +1) {
                auto nxt = s.lower_bound(a[id]), prv = prev(nxt);
                if (nxt != s.end() && intersect(*nxt, a[id]))
                    return make_pair(nxt->id, id);
                if (prv != s.end() && intersect(*prv, a[id]))
                    return make_pair(prv->id, id);
                where[id] = s.insert(nxt, a[id]);
            } else {
                auto nxt = next(where[id]), prv = prev(where[id]);
                if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                    return make_pair(prv->id, nxt->id);
                s.erase(where[id]);
            }
        }

        return make_pair(-1, -1);
    }
};
bool has(ld T) {
    vector < seg > f;
    for (int i = 1; i <= n; i++) {
        pt c1{(ld)x[i], (ld)y[i]};
        ld D = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
        pt c2{x[i] + T * ss[i] * dx[i] / D, y[i] + T * ss[i] * dy[i] / D};
        f.emplace_back(c1, c2, i);
    }
    has_inter Q;
    return Q.solve(f).first != -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> ss[i];
    }
    ld l = 0;
    ld r = 2e12;
    if (!has(r)) {
        cout << "No show :(" << '\n';
    }
    else {
        for (int it = 0; it < 75; it++) {
            ld mid = (l + r) / 2;
            if (has(mid)) r = mid;
            else l = mid;
        }
        cout << fixed << setprecision(12) << (l + r) / 2 << '\n';
    }
    return 0;
}