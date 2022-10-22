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

#pragma pack(push, 1)
struct Line {
    ll k, b;
    char type;
    ld x;

    Line(): k(0), b(0), type(0), x(0) { }

    Line(ll _k, ll _b, ld _x = 4e40, int _type = 0): k(_k), b(_b), x(_x), type(_type) { }

    bool operator<(const Line& other) const {
        if(type + other.type > 0) {
            return x < other.x;
        }else {
            return k < other.k;
        }
    }

    ld intersect(const Line& other) const {
        return ld(b - other.b) / ld(other.k - k);
    }

    ll get_func(ll x0, ll y0) const {
        return k * x0 + b * y0;
    }
};
#pragma pack(pop)

struct CHT {
    set< Line > qs;
    set< Line > :: iterator fnd, help;

    bool hasr(const set< Line > :: iterator& it) {
        return it != qs.end() && next(it) != qs.end();
    }

    bool hasl(const set< Line > :: iterator& it) {
        return it != qs.begin();
    }

    bool check(const set< Line > :: iterator& it) {
        if(!hasr(it)) return true;
        if(!hasl(it)) return true;
        return it->intersect(*prev(it)) < it->intersect(*next(it));
    }

    void update_intersect(const set< Line > :: iterator& it) {
        if(it == qs.end()) return;
        if(!hasr(it)) return;
        Line tmp = *it;
        tmp.x = tmp.intersect(*next(it));
        qs.insert(qs.erase(it), tmp);
    }

    void add_line(Line L) {
        if(qs.empty()) {
            qs.insert(L);
            return;
        }
        {
            fnd = qs.lower_bound(L);
            if(fnd != qs.end() && fnd->k == L.k) {
                if(fnd->b >= L.b) return;
                else qs.erase(fnd);
            }
        }
        fnd = qs.insert(L).first;
        if(!check(fnd)) {
            qs.erase(fnd);
            return;
        }
        while(hasr(fnd) && !check(help = next(fnd))) {
            qs.erase(help);
        }
        while(hasl(fnd) && !check(help = prev(fnd))) {
            qs.erase(help);
        }
        if(hasl(fnd)) {
            update_intersect(prev(fnd));
        }
        update_intersect(fnd);
    }

    ll get_max(ll x, ll y) {
        ld x0 = ld(x) / ld(y);
        if(qs.empty()) return -4 * inf64;
        fnd = qs.lower_bound(Line(0, 0, x0, 1));
        if(fnd == qs.end()) fnd--;
        ll res = -4 * inf64;
        int i = 0;
        while(i < 4 && fnd != qs.end()) {
            res = max(res, fnd->get_func(x, y));
            fnd++;
            i++;
        }
        while(i-- > 0) fnd--;
        while(i < 4) {
            res = max(res, fnd->get_func(x, y));
            if(hasl(fnd)) {
                fnd--;
                i++;
            }else {
                break;
            }
        }
        return res;
    }
};

struct DO_CHT {
    vector<int> keys;
    int n = 0;
    vector<CHT> cht;
    vector<ll> mna;

    DO_CHT(vector<int> keys_) {
        keys = keys_;
        sort(keys.begin(), keys.end());
        keys.erase(unique(keys.begin(), keys.end()), keys.end());
        n = (int) keys.size();
        int sz = 1;
        while (sz < n)
            sz <<= 1;
        sz <<= 1;
        cht.resize(sz);
        mna.resize(sz, 4 * inf64);
    }

    void clear() {
        for (auto& x : cht)
            x.qs.clear();
        mna.assign(mna.size(), 4 * inf64);
    }

    void add_line(int v, int tl, int tr, int pos, ll a, ll b) {
        cht[v].add_line(Line(-a, -b));
        mna[v] = min(mna[v], a);
        if (tl < tr) {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                add_line(v << 1, tl, tm, pos, a, b);
            else
                add_line(v << 1 | 1, tm + 1, tr, pos, a, b);
        }
    }

    vector<tuple<int, ll, ll>> lines;

    void add_line(int key, ll a, ll b) {
        int pos = lower_bound(keys.begin(), keys.end(), key) - keys.begin();
        add_line(1, 0, n - 1, pos, a, b);
//        cout << "add line key = " << key << ", a = " << a << ", b = " << b << "\n";
        lines.emplace_back(key, a, b);
    }

    ll query(int v, int tl, int tr, int l, int r, ll x0, ll y0) {
        if (l <= tl && tr <= r) {
            if (cht[v].qs.empty())
                return 4 * inf64;
            if (y0 == 0)
                return mna[v] * x0;
            else
                return -cht[v].get_max(x0, y0);
        } else {
            int tm = (tl + tr) >> 1;
            ll res = 4 * inf64;
            if (l <= tm)
                res = min(res, query(v << 1, tl, tm, l, r, x0, y0));
            if (r > tm)
                res = min(res, query(v << 1 | 1, tm + 1, tr, l, r, x0, y0));
            return res;
        }
    }

    ll query(int lkey, int rkey, ll x0, ll y0) {
        int l = lower_bound(keys.begin(), keys.end(), lkey) - keys.begin();
        int r = upper_bound(keys.begin(), keys.end(), rkey) - keys.begin() - 1;
        if (l > r)
            return 4 * inf64;
        ll res = query(1, 0, n - 1, l, r, x0, y0);
        ll tmp = 4 * inf64;
        for (auto [key, a, b] : lines) {
            if (lkey <= key && key <= rkey) {
                tmp = min(tmp, 1ll * a * x0 + 1ll * b * y0);
            }
        }
//        cout << "query [" << lkey << ", " << rkey << "] x0 = " << x0 << ", y0 = " << y0 << " ---> " << res << " v.s. " << tmp << "\n";
        return res;
    }
};

struct pt {
    int x = 0;
    int y = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    pt& operator -= (const pt& o) {
        return *this = *this - o;
    }
};

struct RangeTree {
    int n = 0;
    vector<ll> xs, mn, mx;

    RangeTree(const vector<ll>& a) {
        xs.resize(a.size());
        for (int i = 0; i < (int) xs.size(); i++)
            xs[i] = i;
        n = (int) xs.size();
        int sz = 1;
        while (sz < n)
            sz <<= 1;
        sz <<= 1;
        mx.resize(sz, -4 * inf64);
        mn.resize(sz, +4 * inf64);
        for (int i = 0; i < (int) a.size(); i++)
            update(i, a[i]);
    }

    RangeTree(const vector<pt>& a) {
        xs.reserve(a.size());
        for (pt p : a)
            xs.push_back(p.x);
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = (int) xs.size();
        int sz = 1;
        while (sz < n)
            sz <<= 1;
        sz <<= 1;
        mx.resize(sz, -4 * inf64);
        mn.resize(sz, +4 * inf64);
        for (auto [x, y] : a) {
            int pos = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            update(pos, y);
        }
    }

    void update(int v, int tl, int tr, int pos, ll value) {
        mn[v] = min(mn[v], value);
        mx[v] = max(mx[v], value);
        if (tl < tr) {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                update(v << 1, tl, tm, pos, value);
            else
                update(v << 1 | 1, tm + 1, tr, pos, value);
        }
    }

    void update(int pos, ll value) {
        update(1, 0, n - 1, pos, value);
    }

    pll query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return {+4 * inf64, -4 * inf64};
        if (l <= tl && tr <= r) {
            return {mn[v], mx[v]};
        } else {
            int tm = (tl + tr) >> 1;
            pll res = {+4 * inf64, -4 * inf64}, tmp;
            if (l <= tm) {
                tmp = query(v << 1, tl, tm, l, r);
                res.first = min(res.first, tmp.first);
                res.second = max(res.second, tmp.second);
            }
            if (r > tm) {
                tmp = query(v << 1 | 1, tm + 1, tr, l, r);
                res.first = min(res.first, tmp.first);
                res.second = max(res.second, tmp.second);
            }
            return res;
        }
    }

    pll query_(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    pll query(int lx, int rx) {
        int l = lower_bound(xs.begin(), xs.end(), lx) - xs.begin();
        int r = upper_bound(xs.begin(), xs.end(), rx) - xs.begin() - 1;
        return query_(l, r);
    }
};

struct Fen {
    int n = 0;
    vector<int> xs, mx;

    Fen(const vector<pt>& a) {
        xs.reserve(a.size());
        for (pt p : a)
            xs.push_back(p.x);
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = (int) xs.size();
        mx.resize(n, -inf);
        for (pt p : a)
            update(p);
    }

    void update(pt p) {
        int pos = lower_bound(xs.begin(), xs.end(), p.x) - xs.begin();
        int value = p.y;
        for (int cur = pos; cur < n; cur |= (cur + 1))
            mx[cur] = max(mx[cur], value);
    }

    int query(int x) {
        int pos = lower_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
        int res = -inf;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res = max(res, mx[cur]);
        return res;
    }
};

struct Cover {
    multiset<int> xs, ys;

    void update(pt p, char type) {
        if (type == '+') {
            xs.insert(p.x);
            ys.insert(p.y);
        } else {
            xs.erase(xs.find(p.x));
            ys.erase(ys.find(p.y));
        }
    }

    ll area() const {
        if (xs.empty() || ys.empty())
            return 0;
        return 1ll * (*(--xs.end())- *xs.begin()) * (*(--ys.end()) - *ys.begin());
    }

    pt get_min() const {
        return pt{*xs.begin(), *ys.begin()};
    }

    pt get_max() const {
        return pt{*(--xs.end()), *(--ys.end())};
    }
};

void flip(vector<pt>& a) {
    for (auto& p : a)
        swap(p.x, p.y);
}

void mirror(vector<pt>& a) {
    for (auto& p : a)
        p.x *= -1;
}

pt shift_to_zero(vector<pt>& a) {
    pt min_p = {+inf, +inf};
    pt max_p = {-inf, -inf};
    for (pt p : a) {
        min_p.x = min(min_p.x, p.x);
        min_p.y = min(min_p.y, p.y);

        max_p.x = max(max_p.x, p.x);
        max_p.y = max(max_p.y, p.y);
    }
    pt Q = max_p - min_p;
    for (pt& p : a)
        p -= min_p;
    return Q;
}

ll fast1(int n, vector<pt> a) {
    pt Q = shift_to_zero(a);
    vector<pt> b = a;
    flip(b);
    Fen fa(a), fb(b);
    ll res = 4 * inf64;
    vector<pt> A, B;
    for (int x : fa.xs) {
        int U = fa.query(x);
        U = max(U, 0);
        A.push_back({x, U});
    }
    for (int y : fb.xs) {
        int R = fb.query(y);
        R = max(R, 0);
        B.push_back({y, R});
    }
    sort(A.begin(), A.end(), [&](const pt& p1, const pt& p2) {
        return p1.x < p2.x;
    });
    sort(B.begin(), B.end(), [&](const pt& p1, const pt& p2) {
        return p1.y < p2.y;
    });
    vector<int> keys;
    for (auto [y, R] : B)
        keys.push_back(y);
    DO_CHT do_cht(keys);
    for (int j = 0, i = 0; i < (int) A.size(); i++) {
        auto [x, U] = A[i];
        while (j < (int) B.size() && B[j].y <= x) {
            auto [y, R] = B[j];
            do_cht.add_line(y, Q.y - y, y);
            j++;
        }
        res = min(res, do_cht.query(U, Q.y, Q.x - x, x));
    }
    do_cht.clear();
    for (int j = 0, i = 0; i < (int) A.size(); i++) {
        auto [x, U] = A[i];
        while (j < (int) B.size() && B[j].y <= x) {
            auto [y, R] = B[j];
            do_cht.add_line(y, 1, Q.y - y);
            j++;
        }
        res = min(res, do_cht.query(0, U, 1ll * U * x, Q.x - x));
    }
    do_cht.clear();
    for (int j = (int) B.size() - 1, i = (int) A.size() - 1; i >= 0; i--) {
        auto [x, U] = A[i];
        while (j >= 0 && B[j].y > x) {
            auto [y, R] = B[j];
            do_cht.add_line(y, Q.y - y, R);
            j--;
        }
        res = min(res, do_cht.query(0, U, Q.x - x, U));
    }
    do_cht.clear();
    for (int j = (int) B.size() - 1, i = (int) A.size() - 1; i >= 0; i--) {
        auto [x, U] = A[i];
        while (j >= 0 && B[j].y > x) {
            auto [y, R] = B[j];
            do_cht.add_line(y, Q.y - y, 1ll * y * R);
            j--;
        }
        res = min(res, do_cht.query(U, Q.y, Q.x - x, 1));
    }
    return res;
}

ll fast2(int n, vector<pt> a) {
    pt Q = shift_to_zero(a);
    ll res = 4 * inf64;
    for (int iter = 0; iter < 2; iter++) {
        RangeTree rt(a);
        vector<tuple<int, int, int>> A, B;
        for (int x : rt.xs) {
            auto [l1, r1] = rt.query(0, x - 1);
            auto [l2, r2] = rt.query(x + 1, Q.x);
            if (l1 <= r1)
                A.emplace_back(x, l1, r1);
            if (l2 <= r2)
                B.emplace_back(x, l2, r2);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<ll> v1(B.size()), v2(B.size());
        for (int i = 0; i < (int) B.size(); i++) {
            auto [xr, l2, r2] = B[i];
            v1[i] = (1ll * r2 * Q.x + 1ll * xr * Q.y);
            v2[i] = (1ll * xr * Q.y);
        }
        RangeTree rt1(v1), rt2(v2);
        if (!A.empty() && !B.empty()) {
            for (int ptr = 0, i = 0; i < (int) A.size(); i++) {
                auto[xl, l1, r1] = A[i];
                while (ptr < (int) B.size() && get<0>(B[ptr]) < xl)
                    ptr++;
                if (ptr == (int) B.size())
                    break;
                int jl, jr;
                if (get<1>(B.back()) >= l1) {
                    int bl = ptr - 1, br = (int) B.size() - 1, bm;
                    while (br - bl > 1) {
                        bm = (bl + br) >> 1;
                        auto [xr, l2, r2] = B[bm];
                        if (l2 >= l1) br = bm; else bl = bm;
                    }
                    jl = br;
                } else continue;
                assert(0 <= jl && jl < (int) B.size());
                if (r1 > get<2>(B[jl])) {
                    jr = jl;
                } else if (r1 <= get<2>(B.back())) {
                    jr = (int) B.size();
                } else {
                    int bl = jl, br = (int) B.size(), bm;
                    while (br - bl > 1) {
                        bm = (bl + br) >> 1;
                        auto [xr, l2, r2] = B[bm];
                        if (r1 <= r2) bl = bm; else br = bm;
                    }
                    jr = bl + 1;
                }
                assert(jl <= jr);
                {
                    ll tmp = rt1.query(jl, jr - 1).first;
                    if (tmp != 4 * inf64)
                        res = min(res, tmp - 1ll * l1 * Q.x - 1ll * xl * Q.y);
                }
                {
                    ll tmp = rt2.query(jr, (int) B.size() - 1).first;
                    if (tmp != 4 * inf64)
                        res = min(res, tmp + 1ll * (r1 - l1) * Q.x - 1ll * xl * Q.y);
                }
            }
        }
        for (auto& p : a)
            p.x = Q.x - p.x;
    }
    return res;
}

ll fast(int n, vector<pt> a) {
    ll res = 4 * inf64;
    for (int iter = 0; iter < 2; iter++, flip(a)) {
        sort(a.begin(), a.end(), [&](const pt& p1, const pt& p2) {
            return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
        });
        Cover pref, suff;
        for (int i = 0; i < n; i++)
            suff.update(a[i], '+');
        for (int i = 0; i <= n; i++) {
            if (0 < i && i < n && a[i - 1].x < a[i].x)
                res = min(res, pref.area() + suff.area());
            if (i < n) {
                suff.update(a[i], '-');
                pref.update(a[i], '+');
            }
        }
    }
    for (int iter = 0; iter < 2; iter++, mirror(a))
        res = min(res, fast1(n, a));
    res = min(res, fast2(n, a));
    return res;
}

ll slow(int n, vector<pt> a) {
    ll res = 4 * inf64;
    vector<int> xs, ys;
    for (auto [x, y] : a)
        xs.push_back(x), ys.push_back(y);
    for (int lx : xs) {
        for (int rx : xs) {
            if (lx > rx)
                continue;
            for (int ly : ys) {
                for (int ry : ys) {
                    if (ly > ry)
                        continue;
                    ll S1 = 1ll * (rx - lx) * (ry - ly);
                    int LX = +inf, RX = -inf;
                    int LY = +inf, RY = -inf;
                    for (auto [x, y] : a) {
                        if (lx <= x && x <= rx && ly <= y && y <= ry)
                            continue;
                        LX = min(LX, x);
                        RX = max(RX, x);
                        LY = min(LY, y);
                        RY = max(RY, y);
                    }
                    ll S2 = LX <= RX ? 1ll * (RX - LX) * (RY - LY) : 0ll;
                    res = min(res, S1 + S2);
                }
            }
        }
    }
    return res;
}

void work() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pt> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].x >> a[i].y;
        ll fs = fast(n, a);
        cout << fs << "\n";
    }
}

void test() {
    mt19937 rnd(42);
    const int N = 100;
    const int X = inf + 1;
    while (1) {
        int n = rnd() % N + 1;
        vector<pt> a(n);
        for (int i = 0; i < n; i++) {
            a[i].x = rnd() % X;
            a[i].y = rnd() % X;
        }
        ll sl = slow(n, a);
        ll fs = fast(n, a);

        cout << n << endl;
        for (auto [x, y] : a)
            cout << x << " " << y << endl;
        cout << endl;

        if (sl == fs) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            break;
        }
    }
}

void max_test() {
    mt19937 rnd(42);
    const int N = 50;
    const int X = inf + 1;
    while (1) {
        // int n = rnd() % N + 1;
        int n = 2e5;
        vector<pt> a(n);
        for (int i = 0; i < n; i++) {
            a[i].x = rnd() % X;
            a[i].y = rnd() % X;
        }
        ll fs = fast(n, a);
        break;
        ll sl = slow(n, a);

        cout << n << endl;
        for (auto [x, y] : a)
            cout << x << " " << y << endl;
        cout << endl;

        if (sl == fs) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            break;
        }
    }
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