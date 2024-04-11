#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

const ld eps = 1e-9;
const ld pi = acos(-1);

struct output {
    ld res = 0;

    void print() {
        cout.precision(20);
        cout << fixed;
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return abs(res - o.res) < 1;
    }
};

struct pt {
    ld x = 0;
    ld y = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    ld scalar_mul(const pt& o) const {
        return x * o.x + y * o.y;
    }

    ld vector_mul(const pt& o) const {
        return x * o.y - o.x * y;
    }

    ld sqr_norm() const {
        return scalar_mul(*this);
    }

    ld norm() const {
        return sqrtl(max(ld(0), sqr_norm()));
    }

    pt operator + (const pt& o) const {
        return {x + o.x, y + o.y};
    }

    pt operator * (ld coef) const {
        return {x * coef, y * coef};
    }

    string to_string() const {
        stringstream ss;
        ss.precision(5);
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }

    ld angle(const pt& o) const {
        ld sm = scalar_mul(o);
        ld cos_alpha = sm / norm() / o.norm();
        cos_alpha = max(ld(-1), min(ld(1), cos_alpha));
        return acos(cos_alpha);
    }
};

pii find_tangents_on_convex_polygon(const vector<pt>& P, pt q) {
    // q is strictly outside P
    // P in counter-clockwise order
    // P.size >= 3
    // P is strictly convex
    // return {leftmost visible, rightmost visible}
    // be careful with corner cases
    // (when two different points may be
    // leftmost/rightmost visible)
    int n = (int) P.size();
    auto is_visible_edge = [&](int i) -> bool {
        return (P[i] - q).vector_mul(P[(i + 1) % n] - P[i]) < -eps;
    };
    auto is_visible = [&](int i) -> bool {
        return is_visible_edge(i) || is_visible_edge((i - 1 + n) % n);
    };
    auto is_on_right = [&](int i) -> bool {
        return (P[0] - q).vector_mul(P[i] - q) < -eps;
    };
    int bl, br, bm;
    int A = -1, B = -1;
    if (is_visible(0)) {
        bl = 0, br = n;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (is_visible(bm) && is_on_right(bm)) bl = bm;
            else br = bm;
        }
        B = bl;

        bl = 0, br = n;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            int i = (B + n - bm) % n;
            if (is_visible(i)) bl = bm;
            else br = bm;
        }
        A = (B + n - bl) % n;
    } else {
        bl = 0, br = n;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (!is_visible(bm) && !is_on_right(bm)) bl = bm;
            else br = bm;
        }
        A = (bl + 1) % n;

        bl = 0, br = n;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            int i = (A + bm) % n;
            if (is_visible(i)) bl = bm;
            else br = bm;
        }
        B = (A + bl) % n;
    }
    return {A, B};
}

struct input {
    int n;
    ld rope_len;
    vector<pt> ps;

    input() = default;

    void read() {
        cin >> n >> rope_len;
        ps.resize(n);
        for (auto& p : ps)
            cin >> p.x >> p.y;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ld> L(2 * n);
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            L[i] = L[i + n] = (ps[j] - ps[i]).norm();
        }
        for (int i = 1; i < 2 * n; i++)
            L[i] += L[i - 1];
        auto get_sum = [&](int le, int ri) -> ld { // [l, r)
            if (le == ri)
                return 0;
            if (le > ri) ri += n;
            return L[ri - 1] - (le > 0 ? L[le - 1] : 0);
        };
        auto get_len = [&](pt p) -> ld {
            auto [i, j] = find_tangents_on_convex_polygon(ps, p);
            ld on_polygon = get_sum(j, i);
            ld dist_i = (ps[i] - p).norm();
            ld dist_j = (ps[j] - p).norm();
//            cout << "get_len[ " << p.to_string() << " ]\n";
//            cout << "\t" << i << " " << j << " | " << dist_i << " " << dist_j << "\n";
            return on_polygon + dist_i + dist_j;
        };
        auto find_pt = [&](pt s, pt v) -> pt {
            const int MAX_ITER = 50;
            ld bl = 0, br = 1e6, bm;
            ld v_norm = v.norm();
            for (int iter = 0; iter < MAX_ITER; iter++) {
                bm = (bl + br) * 0.5;
                pt p = s + v * (bm / v_norm);
                if (get_len(p) < rope_len) bl = bm;
                else br = bm;
            }
            ld dist = (bl + br) * 0.5;
            pt res = s + v * (dist / v_norm);
//            cout << "find from s = " << s.to_string() << ", v = " << v.to_string() << " : " << res.to_string() << ", len = " << get_len(res) << "\n";
            return res;
        };
        vector<pt> to(n), fr(n), dir_to(n), dir_fr(n);
        for (int i = 0; i < n; i++) {
            dir_to[i] = ps[(i + 1) % n] - ps[i];
            to[i] = find_pt(ps[i], dir_to[i]);
            dir_fr[i] = ps[(i + n - 1) % n] - ps[i];
            fr[i] = find_pt(ps[i], dir_fr[i]);
//            cout << ps[i].to_string() << " : " << to[i].to_string() << "\n";
        }
        auto integrate = [&](ld x0, ld A, ld B) -> ld {
//            const int MAX_ITER = 1000;
//            ld res = 0;
//            for (int i = 0; i < MAX_ITER; i++) {
//                ld x1 = ld(i) * x0 / ld(MAX_ITER);
//                ld x2 = ld(i + 1) * x0 / ld(MAX_ITER);
//                ld f1 = B * sqrtl(max(ld(0), 1 - (x1 / A) * (x1 / A)));
//                ld f2 = B * sqrtl(max(ld(0), 1 - (x2 / A) * (x2 / A)));
//                ld add = (f1 + f2) * (x2 - x1) / 2;
//                res += add;
//            }
//            return res;
            ld alpha0 = asinl(max(ld(-1), min(ld(1), x0 / A)));
            return A * B / 2 * (sinl(2 * alpha0) / 2 + alpha0);
        };
        function<ld(ld, ld, ld, ld, ld)> elipse_prefix_area = [&](ld sum_dist, ld A, ld B, ld D, ld x) -> ld {
            ld y = B * sqrtl(max(ld(0), 1 - (x / A) * (x / A)));
            if (x < 0) {
                ld total = pi * A * B / 2 - D * y / 2;
                return total - elipse_prefix_area(sum_dist, A, B, D, -x);
            }
            ld res = 0;
            if (x < D / 2) {
                res += pi * A * B / 4 - y * (D / 2 - x) / 2;
                res -= integrate(x, A, B);
            } else {
                res += pi * A * B / 4;
                res -= integrate(x, A, B);
                res += (x - D / 2) * y / 2;
            }
            return res;
        };
        auto elipse_area = [&](ld sum_dist, ld A, ld B, ld D, ld x1, ld x2) -> ld {
            ld area1 = elipse_prefix_area(sum_dist, A, B, D, x1);
            ld area2 = elipse_prefix_area(sum_dist, A, B, D, x2);
            ld res = (area2 - area1);
            return res;
        };
        auto move_area = [&](int i, int j, pt p1, pt p2) -> ld {
//            cout << "\t" << ps[(i + 1) % n].to_string() << " .. " << ps[j].to_string() << " : ";
//            cout << p1.to_string() << " -> " << p2.to_string() << "\n";
            int ni = (i + 1) % n;
            ld D = (ps[ni] - ps[j]).norm();
            ld sum_dist = (ps[ni] - p2).norm() + (ps[j] - p2).norm();
            ld d = (sum_dist - D) / 2;
            ld A = D / 2 + d;
            ld B = sqrtl(max(ld(0), (sum_dist / 2) * (sum_dist / 2) - (D / 2) * (D / 2)));
            pt center = (ps[ni] + ps[j]) * 0.5;
            pt v1 = p1 - center;
            pt v2 = p2 - center;
            ld alpha1 = v1.angle(ps[ni] - ps[j]);
            ld alpha2 = v2.angle(ps[ni] - ps[j]);
            ld x1 = v1.norm() * cosl(alpha1);
            ld x2 = v2.norm() * cosl(alpha2);
            ld area = elipse_area(sum_dist, A, B, D, x1, x2);
//            cout << "\tadd area = " << area << "\n";
            return area;
        };
        ld res = 0;
        for (int i = 0; i < n; i++) {
            int j = find_tangents_on_convex_polygon(ps, to[i]).second;
            pt cur = to[i];
            pt finish = to[(i + 1) % n];
//            cout << "start i = " << i << "\n";
            while (1) {
                pt tmp = fr[(j + 1) % n];
                if ((tmp - cur).norm() > (finish - cur).norm())
                    break;
                ld add = move_area(i, j, cur, tmp);
                res += add;
                cur = tmp;
                j = (j + 1) % n;
            }
//            j = (j + n - 1) % n;
            ld add = move_area(i, j, cur, finish);
            res += add;
        }
        ld polygon_area = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            polygon_area += ps[i].vector_mul(ps[j]);
        }
        polygon_area = abs(polygon_area) / 2;
//        cout << "polygon area = " << polygon_area << "\n";
        res += polygon_area;
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}