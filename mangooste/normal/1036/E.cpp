#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

using int128 = __int128;

istream& operator>>(istream &in, int128 &x) {
    string y; in >> y;
    x = 0;
    bool neg = false;
    if (y[0] == '-') neg = true, y.erase(y.begin());
    for (auto c : y) x = ((x + (x << 2)) << 1) + c - '0';
    if (neg) x = -x;
    return in;
}

ostream& operator<<(ostream &out, int128 x) {
    if (x == 0) return out << "0";
    if (x < 0) x = -x, out << '-';
    string s;
    for (; x; x /= 10) s.push_back(x % 10 + '0');
    reverse(all(s));
    return out << s;
}

inline int128 abs(int128 x) { return x < 0 ? -x : x; }
inline void swap(int128 &a, int128 &b) { a ^= b, b ^= a, a ^= b; }
inline int128 gcd(int128 a, int128 b) { a = abs(a); b = abs(b); for (; b; swap(a, b)) a %= b; return a; }

#define ll int128
#define int int128

const int SHIFT = 1e6;

inline int sgn(int x) { if (x < 0) return -1; return x ? 1 : 0; }

struct pt {
    ll x, y;

    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}

    inline ll operator%(const pt p) const { return x * p.y - y * p.x; }
    inline ll operator*(const pt p) const { return x * p.x + y * p.y; }
    inline pt operator-(const pt p) const { return pt(x - p.x, y - p.y); }

    inline bool operator<(const pt p) const { return x < p.x || (x == p.x && y < p.y); }
    inline bool operator==(const pt p) const { return x == p.x && y == p.y; }
    inline bool operator!=(const pt p) const { return x != p.x || y != p.y; }

    friend istream& operator>>(istream &in, pt &p) { return in >> p.x >> p.y; p.x += SHIFT; p.y += SHIFT; }
    friend ostream& operator<<(ostream &out, pt p) { return out << '(' << p.x << ", " << p.y << ')'; }
};

const ll INF = 1e18;
const pt neutral = pt(INF, INF);

struct ln {
    ll a, b, c;

    ln() {}
    ln(pt pa, pt pb) : a(pb.y - pa.y), b(pa.x - pb.x), c(-a * pa.x - b * pa.y) {}

    inline pt intersect(const ln l) const {
        ll d = pt(a, l.a) % pt(b, l.b);
        if (d == 0)
            return neutral;
        ll px = pt(b, l.b) % pt(c, l.c);
        ll py = -(pt(a, l.a) % pt(c, l.c));
        if (abs(px) % abs(d) != 0 || abs(py) % abs(d) != 0)
            return neutral;
        return pt(px / d, py / d);
    }
};

inline bool intersect1D(int l1, int r1, int l2, int r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return min(r1, r2) >= max(l1, l2);
}

struct seg {
    pt a, b;

    seg() {}
    seg(pt a, pt b) : a(a), b(b) {}

    inline bool contains(const pt p) const { return (a - p) * (b - p) <= 0; }

    inline int get() const {
        int delta_x = abs(b.x - a.x);
        int delta_y = abs(b.y - a.y);
        return gcd(delta_x, delta_y) + 1;
    }

    friend istream& operator>>(istream &in, seg &s) { return in >> s.a >> s.b; }
};

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<seg> segs(n);
    ll ans = 0;
    for (auto &s : segs) {
        cin >> s;
        ans += s.get();
    }

    vec<ln> lines(n);
    for (int i = 0; i < n; i++)
        lines[i] = ln(segs[i].a, segs[i].b);

    set<pt> bad;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            pt now = lines[i].intersect(lines[j]);
            if (now != neutral && segs[i].contains(now) && segs[j].contains(now))
                bad.insert(now);
        }

        dbg(i, bad);
        ans -= len(bad);
        set<pt>().swap(bad);
    }
    cout << ans << '\n';
}