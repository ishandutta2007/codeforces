#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int MOD = 1E6;

int k, q, lst = 0;
long long m, x, y;
set<pair<int, int>, greater<pair<int, int>>> se;

struct SPoint {
    long long x, y;

    SPoint(long long _x, long long _y) : x(_x), y(_y) {}

    pair<long long, long long> to_pair() const {
        return {x, y};
    }

    inline bool operator<(const SPoint &oth) const {
        if (1LL * x * oth.y == 1LL * y * oth.x) {
            return x < oth.x;
        } else {
            return 1LL * x * oth.y < 1LL * y * oth.x;
        }
    }
};
set<SPoint> con;

bool convex(SPoint a, SPoint b, SPoint c) {
    SPoint fi(b.x - a.x, b.y - a.y);
    SPoint se(c.x - a.x, c.y - a.y);
    return fi.x * se.y < fi.y * se.x;
}

void add(SPoint u) {
    set<SPoint>::iterator it = con.insert(u).fi;
    se.insert(it->to_pair());
    if (con.size() == 1) {
        return;
    }
    if (it != con.begin() && next(it) != con.end() && !convex(*prev(it), *it, *next(it))) {
        se.erase(it->to_pair());
        con.erase(it);
        return;
    }
    while (it != con.begin()) {
        set<SPoint>::iterator pre = prev(it);
        if (pre == con.begin()) {
            break;
        }
        if (!convex(*prev(pre), *pre, *it)) {
            se.erase(pre->to_pair());
            con.erase(pre);
        } else {
            break;
        }
    }
    while (next(it) != con.end()) {
        set<SPoint>::iterator nxt = next(it);
        if (next(nxt) == con.end()) {
            break;
        }
        if (!convex(*it, *nxt, *next(nxt))) {
            se.erase(nxt->to_pair());
            con.erase(nxt);
        } else {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q >> m;
    for (int i = 1; i <= q; i++) {
        cin >> k >> x >> y;
        x = (x + lst) % MOD + 1;
        y = (y + lst) % MOD + 1;
        swap(x, y);
        if (k == 1) {
            add(SPoint(x, y));
        } else {
            bool chk = true;
            if (con.empty()) {
                chk = false;
            } else {
                set<SPoint>::iterator it = con.upper_bound(SPoint(m, x));
                SPoint mx = SPoint(se.begin()->fi, se.begin()->se);
                long long mul, val;
                if (it == con.end() || mx < *it) {
                    mul = mx.y; val = x;
                } else if (it == con.begin()) {
                    mul = 0; val = 1;
                } else {
                    long long x1 = it->x, y1 = it->y;
                    it = prev(it);
                    long long x2 = it->x, y2 = it->y;
                    mul = abs(x1 * (y1 - y2) - y1 * (x1 - x2));
                    val = abs(m * (y1 - y2) - x * (x1 - x2));
                }
                chk = (mul * y >= val);
            }
            if (chk) {
                cout << "YES\n";
                lst = i;
            } else {
                cout << "NO\n";
            }
        }
    }
}