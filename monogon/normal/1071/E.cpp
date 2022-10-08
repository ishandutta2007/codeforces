
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

using ftype = long double;

struct pt {
    ftype x, y;
    pt(ftype x = 0, ftype y = 0) : x(x), y(y) {}
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    pt operator+(const pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    pt operator*(const ftype &f) const {
        return pt(x * f, y * f);
    }
    ftype cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    ftype dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
    ftype norm() const {
        return x * x + y * y;
    }
    pt normalize() const {
        ftype d = 1.0 / len();
        return pt(x * d, y * d);
    }
    pt rot() const {
        return pt(-y, x);
    }
    bool operator<(const pt &o) const {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
    ftype len() const {
        return hypotl(x, y);
    }
};

const ftype EPS = 1e-9;

int sgn(ftype a) {
    return (a < -EPS ? -1 : a > EPS ? 1 : 0);
}
bool segseg(pt a, pt b, pt c, pt d) {
    return sgn((b - a).cross(d - a)) * sgn((b - a).cross(c - a)) <= 0 &&
        sgn((d - c).cross(a - c)) * sgn((d - c).cross(b - c)) <= 0;
}
pt lineline(pt a, pt b, pt c, pt d) {
    return a + (b - a) * ((c - a).cross(d - c) / (b - a).cross(d - c));
}
// pt pjline(pt a, pt b, pt p) {
//     ftype t = ((p - a).dot(b - a) / (b - a).norm());
//     return a + (b - a) * t;
// }
pt pjseg(pt a, pt b, pt p) {
    ftype t = clamp(((p - a).dot(b - a) / (b - a).norm()), (ftype) 0.0, (ftype) 1.0);
    return a + (b - a) * t;
}
// vector<pt> linecircle(pt a, pt b, pt c, double r) {
//     pt p = pjline(a, b, c) - c;
//     if(p.norm() > r * r + EPS) return {};
//     pt v = p.rot() * sqrtl(max(r * r / p.norm() - 1, (ftype) 0.0));
//     return {c + p + v, c + p - v};
// }

istream &operator>>(istream &is, pt &p) {
    ll X, Y;
    is >> X >> Y;
    p = pt(X, Y);
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w, h;
    pt p;
    cin >> n >> w >> h >> p;
    vector<pt> rain(n + 1);
    vi t(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> t[i] >> rain[i];
    }
    auto check = [&](ftype v) {
        pt a = p, b = p;
        rep(i, 1, n + 1) {
            int tdif = t[i] - t[i - 1];
            pt c(rain[i].x, rain[i].x);
            pt d(rain[i].x - rain[i].y, rain[i].x - rain[i].y + h);
            if(tdif == 0) {
                if(abs(rain[i].y - rain[i - 1].y) < EPS) {
                    if((rain[i] - rain[i - 1]).len() > EPS) {
                        return false;
                    }
                }else {
                    if((b - a).len() < EPS) {
                        // point on line
                        if(sgn((c - a).cross(d - c)) != 0) return false;
                    }else {
                        // collinear already checked
                        pt P = lineline(a, b, c, d);
                        pt Q = pjseg(a, b, P);
                        if((P - Q).len() > EPS) {
                            return false;
                        }else {
                            a = P;
                            b = P;
                        }
                    }
                }
            }else {
                ftype r = v * tdif;
                vector<pt> inter;
                auto thonk = [&](pt A, pt B) {
                    if(sgn((d - c).cross(B - A)) == 0) {
                        if(sgn((d - c).cross(A - c)) == 0) {
                            inter.push_back(A);
                            inter.push_back(B);
                        }
                    }else if(sgn((d - c).cross(A - c)) * sgn((d - c).cross(B - c)) <= 0) {
                        inter.push_back(lineline(A, B, c, d));
                    }
                };
                thonk(pt(a.x - r, a.y - r), pt(a.x - r, a.y + r));
                thonk(pt(a.x - r, a.y + r), pt(a.x + r, a.y + r));
                thonk(pt(a.x + r, a.y + r), pt(a.x + r, a.y - r));
                thonk(pt(a.x + r, a.y - r), pt(a.x - r, a.y - r));

                if((b - a).len() > EPS) {
                    thonk(pt(b.x - r, b.y - r), pt(b.x - r, b.y + r));
                    thonk(pt(b.x - r, b.y + r), pt(b.x + r, b.y + r));
                    thonk(pt(b.x + r, b.y + r), pt(b.x + r, b.y - r));
                    thonk(pt(b.x + r, b.y - r), pt(b.x - r, b.y - r));

                    thonk(pt(a.x - r, a.y - r), pt(b.x - r, b.y - r));
                    thonk(pt(a.x - r, a.y + r), pt(b.x - r, b.y + r));
                    thonk(pt(a.x + r, a.y - r), pt(b.x + r, b.y - r));
                    thonk(pt(a.x + r, a.y + r), pt(b.x + r, b.y + r));
                }

                if(inter.empty()) {
                    return false;
                }
                sort(all(inter));
                a = inter[0];
                b = inter.back();
                if((b - a).len() < EPS) {
                    if(a.x < -EPS || a.x > w + EPS || a.y < -EPS || a.y > w + EPS) {
                        return false;
                    }
                }else {
                    bool flag = true;
                    auto pjsquare = [&](pt a, pt b) {
                        ftype t = 0;
                        if(a.x < -EPS) {
                            ftype t2 = (a.x / (a.x - b.x));
                            if(t2 < -EPS || t2 > 1 + EPS) flag = false;
                            t = max(t, t2);
                        }
                        if(a.x > w + EPS) {
                            ftype t2 = (w - a.x) / (b.x - a.x);
                            if(t2 < -EPS || t2 > 1 + EPS) flag = false;
                            t = max(t, t2);
                        }
                        if(a.y < -EPS) {
                            ftype t2 = (a.y / (a.y - b.y));
                            if(t2 < -EPS || t2 > 1 + EPS) flag = false;
                            t = max(t, t2);
                        }
                        if(a.y > w + EPS) {
                            ftype t2 = (w - a.y) / (b.y - a.y);
                            if(t2 < -EPS || t2 > 1 + EPS) flag = false;
                            t = max(t, t2);
                        }
                        return (a + (b - a) * t);
                    };
                    pt anew = pjsquare(a, b);
                    pt bnew = pjsquare(b, a);
                    a = anew;
                    b = bnew;
                    if(!flag || a.x > b.x + EPS) return false;
                    if((b - a).len() < EPS) {
                        a = (a + b) * 0.5;
                        b = a;
                    }
                }
            }
        }
        return true;
    };
    ftype L = 0, R = 1e6;
    rep(it, 0, 50) {
        ftype v = (L + R) / 2;
        if(check(v)) {
            R = v;
        }else {
            L = v;
        }
    }
    cout << fixed << setprecision(8);
    if(L > 5e5) {
        cout << -1 << '\n';
    }else {
        cout << L << '\n';
    }
}