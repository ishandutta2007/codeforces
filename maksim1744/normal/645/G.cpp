/*
    author:  Maksim1744
    created: 26.06.2021 15:27:26
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

const long double e = 1e-9;

// struct:
//     point
//     line
//     circle

struct point {
    long double x, y;
    point() {};
    point(long double x, long double y): x(x), y(y) {};
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    long double dist(point b) {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    long double len() {
        return sqrt(x * x + y * y);
    }
    point ort() {
        return point(-y, x);
    }

    long double dp(point other) {
        return x * other.x + y * other.y;
    }

    point operator+(point a) {
        return point(a.x + x, a.y + y);
    }
    point operator-(point a) {
        return point(x - a.x, y - a.y);
    }
    point operator*(long double k) {
        return point(x * k, y * k);
    }
    point operator/(long double k) {
        return point(x / k, y / k);
    }
    friend ostream& operator<< (ostream &os, const point & p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

string to_string(point p) {
    stringstream ss;
    ss << p;
    return ss.str();
}

struct line {
    long double a, b, c;
    line() {};
    line(long double a, long double b, long double c): a(a), b(b), c(c) {};
    line(point m, point n) {
        a = n.y - m.y;
        b = m.x - n.x;
        c = -a * m.x - b * m.y;
    }
    point intersect(line l) {
        return point((b * l.c - c * l.b) / (a * l.b - b * l.a), (a * l.c - c * l.a) / (b * l.a - a * l.b));
    }
    long double dist(point p) {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    friend ostream& operator<< (ostream &os, const line & l) {
        if (l.a != 0) {
            os << l.a << "x ";
            if (l.b != 0) {
                if (l.b > 0) {
                    os << "+";
                } else {
                    os << "-";
                }
                os << " " << abs(l.b) << "y ";
            }
        } else {
            os << l.b << "y ";
        }
        if (l.c != 0) {
            if (l.c > 0) {
                os << "+";
            } else {
                os << "-";
            }
            os << " " << abs(l.c) << " ";
        }
        os << "= 0";
        return os;
    }
};

string to_string(line l) {
    stringstream ss;
    ss << l;
    return ss.str();
}

struct circle {
    long double r;
    point o;
    circle() {};
    circle(long double x, long double y, long double new_r) {
        o = point(x, y);
        r = new_r;
    };
    circle(point p, long double new_r) {
        o = p;
        r = new_r;
    };

    long double dist(line l) {
        return l.dist(o);
    }

    vector<point> intersect(line l) {
        vector<point> ans;

        long double d = dist(l);
        if (d > r + e) {
            return ans;
        }
        if (d > r - e) {
            point ort = point(l.a, l.b);
            ort = ort / ort.len() * r;
            auto ort2 = ort * -1;
            if (l.dist(o + ort2) < l.dist(o + ort))
                swap(ort, ort2);
            ans.push_back(ort + o);
            return ans;
        }

        point ort = point(l.a, l.b);
        point m = line(o, o + ort).intersect(l);
        point nap = point(-l.b, l.a);
        nap = nap * sqrt(r * r - d * d) / nap.len();

        ans.push_back(m + nap);
        ans.push_back(m - nap);

        return ans;
    }
    vector<point> intersect(circle s) {
        vector<point> ans;

        long double d = o.dist(s.o);
        if (d > r + s.r + e) {
            return ans;
        }
        if (d > r + s.r - e) {
            point oo = point(o, s.o);
            ans.push_back(o + oo * r / oo.len());
            return ans;
        }
        if (d < abs(r - s.r) - e) {
            return ans;
        }
        if (d < abs(r - s.r) + e) {
            point oo = point(o, s.o);
            oo = oo * r / oo.len();
            if (r < s.r) {
                oo = oo * (-1);
            }
            ans.push_back(o + oo);
            return ans;
        }
        line l = line((long double)2 * (s.o.x - o.x), (long double)2 * (s.o.y - o.y),
                        o.x * o.x + o.y * o.y - s.o.x * s.o.x - s.o.y * s.o.y - r * r + s.r * s.r);
        return intersect(l);
    }
    
    friend ostream& operator<< (ostream &os, const circle & s) {
        if (s.o.x == 0) {
            os << "x^2 + ";
        } else if (s.o.x > 0) {
            os << "(x - " << abs(s.o.x) << ")^2 + ";
        } else {
            os << "(x + " << abs(s.o.x) << ")^2 + ";
        }
        if (s.o.y == 0) {
            os << "y^2 = ";
        } else if (s.o.y > 0) {
            os << "(y - " << abs(s.o.y) << ")^2 = ";
        } else {
            os << "(y + " << abs(s.o.y) << ")^2 = ";
        }
        os << abs(s.r) << "^2";
        return os;
    }
};

string to_string(circle c) {
    stringstream ss;
    ss << c;
    return ss.str();
}

vector<line> tangentToCircle(point p, circle s) {
    vector<line> ans;

    circle s1 = circle((p + s.o) / 2.0, (s.o - p).len() / 2.0);
    vector<point> pts = s1.intersect(s);
    for (auto pt : pts) {
        ans.push_back(line(pt, pt + (pt - s.o).ort()));;
    }

    return ans;
}

vector<line> outer_tangents_to_circles(circle a, circle b) {
    vector<line> ans;
    if (a.r < b.r) {
        swap(a, b);
    }
    long double d = a.o.dist(b.o);
    if (d > a.r - b.r + e) {
        if (abs(a.r - b.r) < e) {
            line oo = line(a.o, b.o);
            point ort = point(oo.a, oo.b);
            ort = ort * a.r / ort.len();
            ans.push_back(line(a.o + ort, b.o + ort));
            ans.push_back(line(a.o - ort, b.o - ort));
        } else {
            vector<point> pts = circle(a.o, a.r - b.r).intersect(circle((a.o + b.o) / 2, (a.o - b.o).len() / 2));
            vector<point> vcts(pts.size());
            for (int i = 0; i < pts.size(); ++i) {
                vcts[i] = pts[i] - a.o;
                vcts[i] = vcts[i] * b.r / vcts[i].len();
                ans.push_back(line(pts[i] + vcts[i], b.o + vcts[i]));
            }
        }
    } else if (d > a.r - b.r - e) {
        point oo = point(a.o, b.o);
        oo = oo * a.r / oo.len();
        ans.push_back(line(a.o + oo, a.o + oo + oo.ort()));
    }
    return ans;
}

vector<line> inner_tangents_to_circle(circle a, circle b) {
    vector<line> ans;
    if (a.r < b.r) {
        swap(a, b);
    }
    long double d = a.o.dist(b.o);
    if (d > a.r + b.r + e) {
        vector<point> pts = circle(a.o, a.r + b.r)
                .intersect(circle((a.o + b.o) / 2, (a.o - b.o).len() / 2));
        vector<point> vcts(pts.size());
        for (int i = 0; i < pts.size(); ++i) {
            vcts[i] = a.o - pts[i];
            vcts[i] = vcts[i] * b.r / vcts[i].len();
            ans.push_back(line(pts[i] + vcts[i], b.o + vcts[i]));
        }
    } else if (d > a.r + b.r - e) {
        point oo = point(a.o, b.o);
        oo = oo * a.r / oo.len();
        ans.push_back(line(a.o + oo, a.o + oo + oo.ort()));
    }
    return ans;
}

vector<line> tangents_to_circles(circle a, circle b) {
    vector<line> ans;
    vector<line> inner = inner_tangents_to_circle(a, b);
    vector<line> outer = outer_tangents_to_circles(a, b);
    for (auto i : inner) {
        ans.push_back(i);
    }
    for (auto i : outer) {
        ans.push_back(i);
    }
    return ans;
}

const ld PI = acosl(-1.0l);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, A;
    cin >> n >> A;
    vector<point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }

    vector<circle> circs(n);
    for (int i = 0; i < n; ++i) {
        circs[i].o = v[i];
        circs[i].r = v[i].dist(point(-A, 0));
    }

    // ld anss = A * 2;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < i; ++j) {
    //         auto v2 = circs[i].intersect(circs[j]);
    //         for (auto p : v2)
    //             umin(anss, p.dist(point(A, 0)));
    //     }
    // }
    // cout << fixed << setprecision(20) << anss << endl;
    // return 0;

    debug {
        cerr << "size (20,20)\n";
        cerr << "grid c=(0,0) s=(20,20) d=(20,20) col=(255,255,255) w=0.2\n";
        cerr << "line s=(-100,0) f=(100,0) w=0.5 col=(255,255,255)\n";
        cerr << "line s=(0,-100) f=(0,100) w=0.5 col=(255,255,255)\n";
        for (auto c : circs) {
            cerr << "circle c=(" << c.o.x << "," << c.o.y << ") r=" << c.r << " f=0 col=(255,255,255)\n";
        }
    }

    ld L = 0, R = A * 2;
    for (int i = 0; i < 50; ++i) {
        ld C = (L + R) / 2;

        circle cur({(ld)A, 0}, C);
        debug {
            cerr << "tick\n";
            cerr << "circle c=(" << cur.o.x << "," << cur.o.y << ") r=" << cur.r << " f=0 col=(255,0,0)\n";
        }

        vector<pair<ld, ld>> segs;
        vector<pair<ld, ld>> segs0;

        for (auto c : circs) {
            auto v = cur.intersect(c);
            if (v.size() != 2) continue;

            v[0] = v[0] - cur.o;
            v[1] = v[1] - cur.o;

            ld ang1 = atan2(v[0].y, v[0].x);
            ld ang2 = atan2(v[1].y, v[1].x);
            assert(-PI - e <= ang1 && ang1 <= PI + e);
            assert(-PI - e <= ang2 && ang2 <= PI + e);
            if (ang1 > ang2) swap(ang1, ang2);
            debug {
                cerr << "msg " << v[0] << ' ' << v[1] << ' ' << ang1 << ' ' << ang2 << endl;
            }
            if (ang2 - ang1 > PI) {
                swap(ang1, ang2);
                segs.eb(-PI, ang2);
                segs.eb(ang1, PI);
                segs0.eb(ang2, ang1);
            } else {
                segs.eb(ang1, ang2);
            }
        }

        debug {
            cerr << "msg segs: " << segs << endl;
            cerr << "msg segs0: " << segs0 << endl;
        }

        bool found = false;

        auto chck = [&](vector<pair<ld, ld>> &v) {
            sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first < b.first;
            });
            vector<pair<ld, ld>> st;
            debug {
                cerr << "msg " << v << endl;
            }
            for (auto [l, r] : v) {
                while (!st.empty()) {
                    if (st.back().first <= l && st.back().second >= r) break;
                    if (st.back().second <= l) {
                        st.pop_back();
                        continue;
                    }
                    found = true;
                    return;
                }
                st.eb(l, r);
            }
            debug {
                cerr << "msg not found" << endl;
            }
        };

        chck(segs);
        chck(segs0);

        if (found)
            R = C;
        else
            L = C;
    }
    ld ans = (L + R) / 2;
    cout << fixed << setprecision(20) << ans << '\n';

    return 0;
}