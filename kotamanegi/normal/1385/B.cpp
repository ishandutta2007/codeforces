#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
#undef int 

#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
#undef int 

typedef complex<long double> Point;
typedef pair<complex<long double>, complex<long double>> Line;

typedef struct Circle {
    complex<long double> center;
    long double r;
}Circle;

long double dot(Point a, Point b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}
long double cross(Point a, Point b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

long double Dist_Line_Point(Line a, Point b) {
    if (dot(a.second - a.first, b - a.first) < eps) return abs(b - a.first);
    if (dot(a.first - a.second, b - a.second) < eps) return abs(b - a.second);
    return abs(cross(a.second - a.first, b - a.first)) / abs(a.second - a.first);
}

int is_intersected_ls(Line a, Line b) {
    return (cross(a.second - a.first, b.first - a.first) * cross(a.second - a.first, b.second - a.first) < eps) &&
        (cross(b.second - b.first, a.first - b.first) * cross(b.second - b.first, a.second - b.first) < eps);
}

Point intersection_l(Line a, Line b) {
    Point da = a.second - a.first;
    Point db = b.second - b.first;
    return a.first + da * cross(db, b.first - a.first) / cross(db, da);
}

long double Dist_Line_Line(Line a, Line b) {
    if (is_intersected_ls(a, b) == 1) {
        return 0;
    }
    return min({ Dist_Line_Point(a,b.first), Dist_Line_Point(a,b.second),Dist_Line_Point(b,a.first),Dist_Line_Point(b,a.second) });
}

pair<Point, Point> intersection_Circle_Circle(Circle a, Circle b) {
    long double dist = abs(a.center - b.center);
    assert(dist <= eps + a.r + b.r);
    assert(dist + eps >= abs(a.r - b.r));
    Point target = b.center - a.center;
    long double pointer = target.real() * target.real() + target.imag() * target.imag();
    long double aa = pointer + a.r * a.r - b.r * b.r;
    aa /= 2.0L;
    Point l{ (aa * target.real() + target.imag() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
            (aa * target.imag() - target.real() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer };
    Point r{ (aa * target.real() - target.imag() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
        (aa * target.imag() + target.real() * sqrt(pointer * a.r * a.r - aa * aa)) / pointer };
    r = r + a.center;
    l = l + a.center;
    return mp(l, r);
}

//end of geometry

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template<typename A>
A pows(A val, ll b) {
    assert(b >= 1);
    A ans = val;
    b--;
    while (b) {
        if (b % 2) {
            ans *= val;
        }
        val *= val;
        b /= 2LL;
    }
    return ans;
}

template<typename A>
class Compressor {
public:
    bool is_zipped = false;
    map<A, ll> zipper;
    map<ll, A> unzipper;
    queue<A> fetcher;
    Compressor() {
        is_zipped = false;
        zipper.clear();
        unzipper.clear();
    }
    void add(A now) {
        assert(is_zipped == false);
        zipper[now] = 1;
        fetcher.push(now);
    }
    void exec() {
        assert(is_zipped == false);
        int cnt = 0;
        for (auto i = zipper.begin(); i != zipper.end(); ++i) {
            i->second = cnt;
            unzipper[cnt] = i->first;
            cnt++;
        }
        is_zipped = true;
    }
    ll fetch() {
        assert(is_zipped == true);
        A hoge = fetcher.front();
        fetcher.pop();
        return zipper[hoge];
    }
    ll zip(A now) {
        assert(is_zipped == true);
        assert(zipper.find(now) != zipper.end());
        return zipper[now];
    }
    A unzip(ll a) {
        assert(is_zipped == true);
        assert(a < unzipper.size());
        return unzipper[a];
    }
    ll next(A now) {
        auto x = zipper.upper_bound(now);
        if (x == zipper.end()) return zipper.size();
        return (ll)((*x).second);
    }
    ll back(A now) {
        auto x = zipper.lower_bound(now);
        if (x == zipper.begin()) return -1;
        x--;
        return (ll)((*x).second);
    }
};

template<typename A>
class Matrix {
public:
    vector<vector<A>> data;
    Matrix(vector<vector<A>> a) :data(a) {

    }
    Matrix operator + (const Matrix obj) {
        vector<vector<A>> ans;
        assert(obj.data.size() == this->data.size());
        assert(obj.data[0].size() == this->data[0].size());
        REP(i, obj.data.size()) {
            ans.push_back(vector<A>());
            REP(q, obj.data[i].size()) {
                A hoge = obj.data[i][q] + (this->data[i][q]);
                ans.back().push_back(hoge);
            }
        }
        return Matrix(ans);
    }
    Matrix operator - (const Matrix obj) {
        vector<vector<A>> ans;
        assert(obj.data.size() == this->data.size());
        assert(obj.data[0].size() == this->data[0].size());
        REP(i, obj.data.size()) {
            ans.push_back(vector<A>());
            REP(q, obj.data[i].size()) {
                A hoge = this->data[i][q] - obj.data[i][q];
                ans.back().push_back(hoge);
            }
        }
        return Matrix(ans);
    }
    Matrix operator * (const Matrix obj) {
        vector<vector<A>> ans;
        assert(obj.data.size() == this->data[0].size());
        REP(i, this -> data.size()) {
            ans.push_back(vector<A>());
            REP(q, obj.data[0].size()) {
                A hoge = ((this->data[i][0]) * (obj.data[0][q]));
                for (int t = 1; t < obj.data.size(); ++t) {
                    hoge += ((this->data[i][t]) * obj.data[t][q]);
                }
                ans.back().push_back(hoge);
            }
        }
        return Matrix(ans);
    }
    Matrix& operator *= (const Matrix obj) {
        *this = (*this * obj);
        return *this;
    }
    Matrix& operator += (const Matrix obj) {
        *this = (*this + obj);
        return *this;
    }
    Matrix& operator -= (const Matrix obj) {
        *this = (*this - obj);
        return *this;
    }
};


struct Fraction {
    ll a;
    ll b;
    Fraction() :a(0LL), b(1LL) {

    }
    Fraction(ll c, ll d) {
        int hoge = gcd(llabs(c), llabs(d));
        if (hoge != 0) {
            c /= hoge;
            d /= hoge;
            if (d < 0 or (d == 0 and c < 0)) {
                d *= -1;
                c *= -1;
            }
        }
        a = c;
        b = d;
    }
    bool operator <(Fraction rhs) const {
        if (a < 0 and rhs.a > 0) return 1;
        if (a > 0 and rhs.a < 0) return 0;
        return a * rhs.b < rhs.a * b;
    }
    bool operator ==(Fraction rhs) const {
        return a == rhs.a and b == rhs.b;
    }
};

template <std::uint_fast64_t mod>
class modint {
public:
    using u64 = std::uint_fast64_t;
    u64 value = 0;
    modint() :value(0LL) {

    }
    modint(ll a) : value(((a% mod) + 2 * mod) % mod) {

    }

    constexpr modint operator+(const modint rhs) const {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) {
        value += rhs.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) {
        if (value < rhs.value) {
            value += mod;
        }
        value -= rhs.value;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) {
        value = (value * rhs.value) % mod;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) {
        ll rem = mod - 2;
        while (rem) {
            if (rem % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            rem /= 2LL;
        }
        return *this;
    }
    bool operator <(modint rhs) const {
        return value < rhs.value;
    }
    friend ostream& operator<<(ostream& os, modint& p) {
        os << p.value;
        return (os);
    }
};

class Dice {
public:
    vector<ll> vertexs;
    //Up: 0,Left: 1,Center: 2,Right: 3,Adj: 4, Down: 5
    Dice(vector<ll> init) :vertexs(init) {

    }
    //Look from Center
    void RtoL() {
        for (int q = 1; q < 4; ++q) {
            swap(vertexs[q], vertexs[q + 1]);
        }
    }
    void LtoR() {
        for (int q = 3; q >= 1; --q) {
            swap(vertexs[q], vertexs[q + 1]);
        }
    }
    void UtoD() {
        swap(vertexs[5], vertexs[4]);
        swap(vertexs[2], vertexs[5]);
        swap(vertexs[0], vertexs[2]);
    }
    void DtoU() {
        swap(vertexs[0], vertexs[2]);
        swap(vertexs[2], vertexs[5]);
        swap(vertexs[5], vertexs[4]);
    }
    bool ReachAble(Dice now) {
        set<Dice> hoge;
        queue<Dice> next;
        next.push(now);
        hoge.insert(now);
        while (next.empty() == false) {
            Dice seeing = next.front();
            next.pop();
            if (seeing == *this) return true;
            seeing.RtoL();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
            seeing.LtoR();
            seeing.LtoR();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
            seeing.RtoL();
            seeing.UtoD();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
            seeing.DtoU();
            seeing.DtoU();
            if (hoge.count(seeing) == 0) {
                hoge.insert(seeing);
                next.push(seeing);
            }
        }
        return false;
    }
    bool operator ==(const Dice& a) {
        for (int q = 0; q < 6; ++q) {
            if (a.vertexs[q] != (*this).vertexs[q]) {
                return false;
            }
        }
        return true;
    }
    bool operator <(const Dice& a) const {
        return (*this).vertexs < a.vertexs;
    }
};

pair<Dice, Dice> TwoDimDice(int center, int up) {
    int target = 1;
    while (true) {
        if (center != target && 7 - center != target && up != target && 7 - up != target) {
            break;
        }
        target++;
    }
    return mp(Dice(vector<ll>{up, target, center, 7 - target, 7 - center, 7 - up}), Dice(vector<ll>{up, 7 - target, center, target, 7 - center, 7 - up}));
}

tuple<Dice, Dice, Dice, Dice> OneDimDice(int center) {
    int bo = min(center, 7 - center);
    pair<int, int> goa;
    if (bo == 1) {
        goa = mp(2, 3);
    }
    else if (bo == 2) {
        goa = mp(1, 3);
    }
    else if (bo == 3) {
        goa = mp(1, 2);
    }
    tuple<Dice, Dice, Dice, Dice> now = make_tuple(Dice(vector<ll>{goa.first, goa.second, center, 7 - goa.second, 7 - center, 7 - goa.first}),
        Dice(vector<ll>{goa.first, 7 - goa.second, center, goa.second, 7 - center, 7 - goa.first}),
        Dice(vector<ll>{7 - goa.first, goa.second, center, 7 - goa.second, 7 - center, goa.first}),
        Dice(vector<ll>{7 - goa.first, 7 - goa.second, center, goa.second, 7 - center, goa.first}));
    return now;
}

template<typename A, typename B>
class Dijkstra {
public:
    vector<vector<pair<int, A>>> vertexs;
    B Cost_Function;
    Dijkstra(int n, B cost) : Cost_Function(cost) {
        vertexs = vector<vector<pair<int, A>>>(n, vector<pair<int, A>>{});
    }
    ~Dijkstra() {
        vertexs.clear();
    }
    void add_edge(int a, int b, A c) {
        vertexs[a].push_back(mp(b, c));
    }
    vector<ll> build_result(int StartPoint) {
        vector<ll> dist(vertexs.size(), 2e18);
        dist[StartPoint] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> next;
        next.push(make_pair(0, StartPoint));
        while (next.empty() == false) {
            pair<ll, int> now = next.top();
            next.pop();
            if (dist[now.second] != now.first) continue;
            for (auto x : vertexs[now.second]) {
                ll now_cost = now.first + Cost_Function(x.second);
                if (dist[x.first] > now_cost) {
                    dist[x.first] = now_cost;
                    next.push(mp(now_cost, x.first));
                }
            }
        }
        return dist;
    }
};

class Dinic {
public:
    struct edge {
        int to;
        int cap;
        int rev;
    };
    vector<vector<edge>> Graph;
    vector<int> level;
    vector<int> itr;
    Dinic(int n) {
        Graph = vector<vector<edge>>(n, vector<edge>());
    }
    void add_edge(int a, int b, int cap) {
        Graph[a].push_back(edge{ b, cap ,(int)Graph[b].size() });
        Graph[b].push_back(edge{ a,0,(int)Graph[a].size() - 1 });
    }
    void bfs(int s) {
        level = vector<int>(Graph.size(), -1);
        level[s] = 0;
        queue<int> next;
        next.push(s);
        while (next.empty() == false) {
            int now = next.front();
            next.pop();
            for (auto x : Graph[now]) {
                if (x.cap == 0) continue;
                if (level[x.to] == -1) {
                    level[x.to] = level[now] + 1;
                    next.push(x.to);
                }
            }
        }
    }
    int dfs(int now, int goal, int val) {
        if (goal == now) return val;
        for (int& i = itr[now]; i < (int)Graph[now].size(); ++i) {
            edge& target = Graph[now][i];
            if (target.cap > 0 && level[now] < level[target.to]) {
                int d = dfs(target.to, goal, min(val, target.cap));
                if (d > 0) {
                    target.cap -= d;
                    Graph[target.to][target.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int run(int s, int t) {
        int ans = 0;
        int f = 0;
        while (bfs(s), level[t] >= 0) {
            itr = vector<int>(Graph.size(), 0);
            while ((f = dfs(s, t, 1e9)) > 0) {
                ans += f;
            }
        }
        return ans;
    }
};


class HLDecomposition {
public:
    vector<vector<int>> vertexs;
    vector<int> depth;
    vector<int> backs;
    vector<int> connections;
    vector<int> zip, unzip;
    HLDecomposition(int n) {
        vertexs = vector<vector<int>>(n, vector<int>());
        depth = vector<int>(n);
        zip = vector<int>(n);
        unzip = zip;
    }
    void add_edge(int a, int b) {
        vertexs[a].push_back(b);
        vertexs[b].push_back(a);
    }
    int depth_dfs(int now, int back) {
        depth[now] = 0;
        for (auto x : vertexs[now]) {
            if (x == back) continue;
            depth[now] = max(depth[now], 1 + depth_dfs(x, now));
        }
        return depth[now];
    }
    void dfs(int now, int backing) {
        zip[now] = backs.size();
        unzip[backs.size()] = now;
        backs.push_back(backing);
        int now_max = -1;
        int itr = -1;
        for (auto x : vertexs[now]) {
            if (depth[x] > depth[now]) continue;
            if (now_max < depth[x]) {
                now_max = depth[x];
                itr = x;
            }
        }
        if (itr == -1) return;
        connections.push_back(connections.back());
        dfs(itr, backing);
        for (auto x : vertexs[now]) {
            if (depth[x] > depth[now]) continue;
            if (x == itr) continue;
            connections.push_back(zip[now]);
            dfs(x, backs.size());
        }
        return;
    }
    void build() {
        depth_dfs(0, -1);
        connections.push_back(-1);
        dfs(0, -1);
    }
    vector<pair<int, int>> query(int a, int b) {
        a = zip[a];
        b = zip[b];
        vector<pair<int, int>> ans;
        while (backs[a] != backs[b]) {
            if (a < b) swap(a, b);
            ans.push_back(mp(backs[a], a + 1));
            a = connections[a];
        }
        if (a > b) swap(a, b);
        ans.push_back(mp(a, b + 1));
        return ans;
    }
    int lca(int a, int b) {
        a = zip[a];
        b = zip[b];
        while (backs[a] != backs[b]) {
            if (a < b) swap(a, b);
            a = connections[a];
        }
        return unzip[min(a, b)];
    }
};
//by ei1333
//https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz + 1, M1);
    }

    void set(int k, const Monoid& x) {
        seg[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid& x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int& k) const {
        return seg[k + sz];
    }

    template< typename C >
    int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }


    template< typename C >
    int find_first(int a, const C& check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template< typename C >
    int find_last(int b, const C& check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

    int sz, height;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;


    LazySegmentTree(int n, const F f, const G g, const H h,
        const Monoid& M1, const OperatorMonoid OM0)
        : f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        height = 0;
        while (sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid& x) {
        data[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if (lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = reflect(k);
            lazy[k] = OM0;
        }
    }

    inline Monoid reflect(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    inline void recalc(int k) {
        while (k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid& x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, reflect(l++));
            if (r & 1) R = f(reflect(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int& k) {
        return query(k, k + 1);
    }

    template< typename C >
    int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < sz) {
            propagate(a);
            Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
            if (check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template< typename C >
    int find_first(int a, const C& check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + sz);
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, reflect(a));
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }


    template< typename C >
    int find_last(int b, const C& check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(reflect(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + sz - 1);
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(reflect(--b), R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

class KMP {
public:
    vector<ll> table;
    vector<ll> Pattern;
    KMP(vector<ll> a) {
        build(a);
    }
    void build(vector<ll> a) {
        Pattern = a;
        table = vector<ll>(a.size() + 1, -1);
        int j = -1;
        for (int i = 0; i < a.size(); ++i) {
            while (j >= 0 && Pattern[i] != Pattern[j]) {
                j = table[j];
            }
            table[i + 1] = ++j;
        }
        return;
    }
    vector<ll> search(vector<ll> a) {
        vector<ll> ans;
        for (int i = 0, k = 0; i < a.size(); ++i) {
            while (k >= 0 && a[i] != Pattern[k]) k = table[k];
            ++k;
            if (k >= Pattern.size()) {
                ans.push_back(i - Pattern.size() + 1);
                k = table[k];
            }
        }
        return ans;
    }
};

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}

#define int ll

template< typename flow_t, typename cost_t >
struct PrimalDual {
    const cost_t INF;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool isrev;
    };
    vector< vector< edge > > graph;
    vector< cost_t > potential, min_cost;
    vector< int > prevv, preve;

    PrimalDual(int V) : graph(V), INF(numeric_limits< cost_t >::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
        graph[from].emplace_back(edge{ to, cap, cost, (int)graph[to].size(), false });
        graph[to].emplace_back(edge{ from, 0, -cost, (int)graph[from].size() - 1, true });
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int)graph.size();
        cost_t ret = 0;
        using Pi = pair< cost_t, int >;
        priority_queue< Pi, vector< Pi >, greater< Pi > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while (!que.empty()) {
                Pi p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < graph[p.second].size(); i++) {
                    edge& e = graph[p.second][i];
                    cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if (min_cost[t] == INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto& e : graph[i]) {
                if (e.isrev) continue;
                auto& rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
            }
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> inputs;
    REP(i, 2 * n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    set<int> ans;
    REP(i, 2 * n) {
        if (ans.count(inputs[i]) == 0) {
            cout << inputs[i] << " ";
        }
        ans.insert(inputs[i]);
    }
    cout << endl;
}
#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(tea,t)
    solve();
}