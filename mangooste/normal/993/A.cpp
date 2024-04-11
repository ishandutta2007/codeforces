#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

struct point {
    int x, y;

    point() {}
    point(int x, int y) : x(x), y(y) {}

    friend istream& operator>>(istream &in, point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    vec<point> a(4);
    for (auto &p : a)
        cin >> p;

    vec<point> b(4);
    for (auto &p : b)
        cin >> p;

    for (int i = 0; i < 4; i++) {
        a[i].x *= 2, a[i].y *= 2;
        b[i].x *= 2, b[i].y *= 2;
    }

    bool ok = false;

    int min_x = min({a[0].x, a[1].x, a[2].x, a[3].x});
    int max_x = max({a[0].x, a[1].x, a[2].x, a[3].x});
    int min_y = min({a[0].y, a[1].y, a[2].y, a[3].y});
    int max_y = max({a[0].y, a[1].y, a[2].y, a[3].y});

    auto in_a = [&](point p) {
        return min_x <= p.x && p.x <= max_x && min_y <= p.y && p.y <= max_y;
    };

    for (auto p : b)
        ok |= in_a(p);

    int st = 0;
    if (b[st].y != b[st + 2].y)
        st++;

    ok |= in_a({b[st + 1].x, b[st].y});

    auto in_b = [&](point p) {
        return abs(p.x - b[st + 1].x) + abs(p.y - b[st].y) <= abs(b[st].x - b[st + 1].x);
    };

    for (auto p : a)
        ok |= in_b(p);

    cout << (ok ? "YES" : "NO") << '\n';
}