#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
 
const int inf = 1e9;
const ll inf64 = 1e18;
 
struct Fen {
    int n; // [0, n)
    vector<int> f;
 
    Fen(int nn) {
        n = nn;
        f.resize(n);
    }
 
    void upd(int pos, int value) {
        for (int cur = pos; cur < n; cur |= (cur + 1))
            f[cur] += value;
    }
 
    int get(int pos) {
        int res = 0;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }
};
 
struct CyclicRangeProcessor {
    Fen fen;
 
    CyclicRangeProcessor(int n): fen(n) { }
 
    int query(int l, int r) {
        if (l <= r)
            return fen.get(r) - fen.get(l - 1);
        return fen.get(fen.n - 1) - fen.get(l - 1) + fen.get(r);
    }
 
    void upd(int pos, int value) {
        fen.upd(pos, value);
    }
};
 
const ld eps = 1e-12;
const ld pi = acos(-1);
 
struct pt {
    ld x = 0;
    ld y = 0;
 
    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }
 
    pt operator + (const pt& o) const {
        return {x + o.x, y + o.y};
    }
 
    pt operator * (ld coef) const {
        return {x * coef, y * coef};
    }
 
    ld sqr_norm() const {
        return x * x + y * y;
    }
 
    ld norm() const {
        return sqrtl(sqr_norm());
    }
 
    pt rotate(ld cos_alpha, ld sin_alpha) const {
        return {x * cos_alpha - y * sin_alpha, x * sin_alpha + y * cos_alpha};
    }
 
    ld get_angle() const {
        return atan2l(y, x);
    }
 
    void show() {
        cout << "(" << x << ", " << y << ")";
    }
 
    pt normalize(ld need_len) const {
        ld cur_len = norm();
        return *this * (need_len / cur_len);
    }
};
 
inline ld sqr(ld x) {
    return x * x;
}
 
int main() {
 
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    ll k;
    cin >> n >> k;
 
    vector<pt> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
 
    auto get_segment = [](ld R, pt p) -> pair<ld, ld> {
        ld sqr_D = p.sqr_norm();
        ld D = sqrtl(sqr_D);
        ld h = sqrtl(max(ld(0), sqr_D - sqr(R)));
 
        ld sin_alpha = R / D;
        ld cos_alpha = h / D;
 
        pt va = (p * -1).rotate(cos_alpha, -sin_alpha).normalize(h);
        pt vb = (p * -1).rotate(cos_alpha, +sin_alpha).normalize(h);
 
        pt a = p + vb;
        pt b = p + va;
 
//        a.show(); cout << "   "; b.show(); cout << "\n";
//        cout << a.get_angle() << " .. " << b.get_angle() << " | " << b.get_angle() - a.get_angle() << "\n";
 
        if ((a - b).norm() < eps)
            return {0, 0};
 
        return {a.get_angle(), b.get_angle()};
    };
 
    auto get_segments = [&](ld R) -> vector<pair<ld, ld>> {
        vector<pair<ld, ld>> segments;
        for (int i = 0; i < n; i++)
            if (p[i].norm() > R + eps)
                segments.push_back(get_segment(R, p[i]));
        return segments;
    };
 
    auto q_segs = [](const vector<pair<ld, ld>>& segs) -> vector<pii> {
        vector<pii> res(segs.size());
        vector<pair<ld, int>> crd;
        for (int i = 0; i < (int) segs.size(); i++) {
            crd.emplace_back(segs[i].first, i + 1);
            crd.emplace_back(segs[i].second, -(i + 1));
        }
        sort(crd.begin(), crd.end());
        for (int ptr = 0, i = 0; i < (int) crd.size(); i++) {
            int j = i;
//            while (j + 1 < (int) crd.size() && abs(crd[j].first - crd[j + 1].first) < eps)
//                j++;
            // [i, j]
            for (int q = i; q <= j; q++) {
                if (crd[q].second > 0)
                    res[crd[q].second - 1].first = ptr;
                else
                    res[-crd[q].second - 1].second = ptr;
            }
            i = j;
            ptr++;
        }
        return res;
    };
 
    auto calc_intersections = [&](vector<pii> segs) -> ll {
        for (auto& s : segs)
            if (s.first > s.second)
                swap(s.first, s.second);
        sort(segs.begin(), segs.end());
        int mx = 0;
        for (auto s : segs)
            mx = max({mx, s.first, s.second});
        mx++;
        CyclicRangeProcessor processor_l(mx), processor_r(mx);
        auto get_next = [&](int x) -> int {
            return x + 1 < mx ? x + 1 : 0;
        };
        auto get_prev = [&](int x) -> int {
            return x > 0 ? x - 1 : mx - 1;
        };
        auto get_len = [&](int l, int r) -> int {
            return l <= r ? r - l + 1 : (mx - 1 - l + 1) + (r + 1);
        };
        ll res = 0;
        for (int i = 0; i < (int) segs.size(); i++) {
            int j = i;
            while (j < (int) segs.size() && segs[i].first == segs[j].first)
                j++;
            j--;
            // [i, j]
            for (int q = i; q <= j; q++) {
                // query
                auto [l, r] = segs[q];
                int len = r - l + 1;
                if (len >= 3 && len < mx)
                    res += processor_r.query(l + 1, r - 1);
            }
            for (int q = i; q <= j; q++) {
                // add
                auto [l, r] = segs[q];
                int len = r - l + 1;
                if (len >= 3 && len < mx)
                    processor_r.upd(r, +1);
            }
            i = j;
        }
        return res;
    };
 
    auto calc_zero_rad = [&](ld R) -> ll {
        vector<ld> alphas;
        for (int i = 0; i < n; i++) {
            ld alpha = p[i].get_angle();
            if (alpha < 0)
                alpha += pi;
            alphas.push_back(alpha);
        }
        sort(alphas.begin(), alphas.end());
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && abs(alphas[j] - alphas[j + 1]) < eps)
                j++;
            int len = j - i + 1;
            res += 1ll * len * (len - 1) / 2;
            i = j;
        }
        return res;
    };
 
    auto calc = [&](ld R) -> ll {
        if (abs(R) < eps)
            return calc_zero_rad(R);
        vector<pii> segments = q_segs(get_segments(R));
        int sz = (int) segments.size();
//        for (auto s : segments) {
//            cout << s.first << " .. " << s.second << "\n";
//        }
        ll ci = calc_intersections(segments);
//        cout << "ci = " << ci << "\n";
        return 1ll * (n - sz) * (n - sz - 1) / 2 + 1ll * (n - sz) * sz  + 1ll * sz * (sz - 1) / 2 - ci;
    };
 
    const int ITERS = 100;
 
    ld bl = 0, br = 1e5, bm;
    for (int iter = 0; iter < ITERS; iter++) {
        bm = (bl + br) / 2;
        if (calc(bm) >= k)
            br = bm;
        else
            bl = bm;
    }
 
    cout.precision(20);
    cout << fixed;
    cout << (bl + br) / 2 << "\n";
 
    return 0;
}