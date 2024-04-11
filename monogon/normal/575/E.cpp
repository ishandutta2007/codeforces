
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

typedef double ftype;

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    pt operator+(const pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    pt operator*(const ll d) const {
        return pt(x * d, y * d);
    }
    pt operator/(const ll d) const {
        return pt(x / d, y / d);
    }
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    bool operator<(const pt &o) const {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
    bool operator==(const pt &o) const {
        return x == o.x && y == o.y;
    }
    ftype len() const {
        return hypot(x, y);
    }
};

int n;

vector<pt> upperhull(const vector<pt> &v, int n) {
    vector<pt> u;
    for(int m, i = 0; i < n; i++) {
        while((m = u.size()) > 1) {
            pt p = u[m - 1], q = u[m - 2];
            if((p - q).cross(v[i] - p) > 0) break;
            u.pop_back();
        }
        u.push_back(v[i]);
    }
    return u;
}
vector<pt> hull(vector<pt> &v) {
    int n = sz(v);
    vector<pt> u = upperhull(v, n);
    reverse(v.begin(), v.end());
    vector<pt> l = upperhull(v, n);
    reverse(v.begin(), v.end());
    for(int i = 1; i + 1 < (int) l.size(); i++)
        u.push_back(l[i]);
    return u;
}

bool ins(const pt &p) {
    return p.x >= 0 && p.x <= 100'000 && p.y >= 0 && p.y <= 100'000;
}

int sgn(ll x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}

bool segseg(const pt &a, const pt &b, const pt &c, const pt &d) {
    return sgn((b - a).cross(c - a)) * sgn((b - a).cross(d - a)) <= 0 &&
        sgn((d - c).cross(a - c)) * sgn((d - c).cross(b - c)) <= 0;
}

pt lineline(pt a, pt b, pt c, pt d) {
    return a + ((b - a) * (c - a).cross(d - c)) / (b - a).cross(d - c);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pt> ve;
    auto add = [&](const pt &p) {
        if(ins(p)) ve.push_back(p);
    };
    vector<pt> A;
    A.emplace_back(0, 0);
    A.emplace_back(100'000, 0);
    A.emplace_back(100'000, 100'000);
    A.emplace_back(0, 100'000);
    rep(i, 0, n) {
        pt p;
        int v;
        cin >> p.x >> p.y >> v;
        if(v == 0) add(p);
        else {
            vector<pt> B;
            B.emplace_back(p.x + v, p.y);
            B.emplace_back(p.x, p.y + v);
            B.emplace_back(p.x - v, p.y);
            B.emplace_back(p.x, p.y - v);
            for(pt &p : B) add(p);
            rep(i, 0, 4) {
                int i2 = (i + 1) % 4;
                rep(j, 0, 4) {
                    int j2 = (j + 1) % 4;
                    if(segseg(A[i], A[i2], B[j], B[j2])) {
                        ve.push_back(lineline(A[i], A[i2], B[j], B[j2]));
                    }
                }
            }
            rep(i, 0, 4) {
                if(abs(A[i].x - p.x) + abs(A[i].y - p.y) <= v) {
                    ve.push_back(A[i]);
                }
            }
        }
    }
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    vector<pt> c = hull(ve);
    int s = sz(c), idx = 0;
    ftype bestR = 0;
    rep(i, 0, s) {
        int j = (i + 1) % s;
        int k = (i + 2) % s;
        ll cr = (c[j] - c[i]).cross(c[k] - c[i]);
        if(cr != 0) {
            ftype R = (c[j] - c[i]).len() * (c[k] - c[j]).len() * (c[i] - c[k]).len() / (2 * abs(cr));
            if(R > bestR) {
                bestR = R;
                idx = i;
            }
        }
    }
    rep(i, 0, 3) {
        int j = (idx + i) % s;
        cout << c[j].x << ' ' << c[j].y << '\n';
    }
}