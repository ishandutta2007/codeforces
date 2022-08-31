/*
    author:  Maksim1744
    created: 27.06.2021 03:05:19
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

ll intersect(const pair<ll, ll> &l1, const pair<ll, ll> &l2) {
    assert(l1.first < l2.first);
    // l1.first * x + l1.second = l2.first * x + l2.second
    // x = (l1.second - l2.second) / (l2.first - l1.first)
    return max(0ll, (l1.second - l2.second + l2.first - l1.first - 1) / (l2.first - l1.first));
}

struct convex_hull {
    vector<pair<ll, pair<ll, ll>>> v;

    void push(const pair<ll, ll> &line) {
        if (v.empty()) {
            v.eb(0, line);
            return;
        }
        assert(line.first >= v.back().second.first);
        while (!v.empty()) {
            if (v.back().second.first == line.first) {
                if (v.back().second.second >= line.second) return;
                v.pop_back();
                continue;
            }
            if ((v.size() >= 2 && intersect(v[v.size() - 2].second, v[v.size() - 1].second) >= intersect(v[v.size() - 1].second, line)) ||
                (v.size() == 1 && intersect(v.back().second, line) == 0)) {
                v.pop_back();
            } else {
                break;
            }
        }


        if (v.empty()) {
            v.eb(0, line);
            return;
        }
        v.eb(intersect(v.back().second, line), line);
    }

    ll ask(ll x) {
        assert(!v.empty());
        int L = 0, R = v.size();
        while (R - L > 1) {
            int C = (L + R) / 2;
            if (v[C].first <= x)
                L = C;
            else
                R = C;
        }
        return v[L].second.first * x + v[L].second.second;
    }

    static convex_hull merge(const convex_hull &a_, const convex_hull &b_) {
        if (a_.v.empty()) return b_;
        if (b_.v.empty()) return a_;
        auto &a = a_.v;
        auto &b = b_.v;
        convex_hull res;

        int ia = 0, ib = 0;
        while (ia < a.size() || ib < b.size()) {
            bool choosea;
            if (ib == b.size()) choosea = true;
            else if (ia == a.size()) choosea = false;
            else if (a[ia].second.first <= b[ib].second.first) choosea = true;
            else choosea = false;

            if (choosea) {
                res.push(a[ia++].second);
            } else {
                res.push(b[ib++].second);
            }
        }

        return res;
    }

    static convex_hull add(const convex_hull &a_, const convex_hull &b_) {
        if (a_.v.empty()) return b_;
        if (b_.v.empty()) return a_;
        auto &a = a_.v;
        auto &b = b_.v;
        convex_hull res;
        int ia = 0, ib = 0;

        auto ad = [&](ll x, pair<ll, ll> ln) {
            if (!res.v.empty() && res.v.back().first == x) {
                res.v.pop_back();
            }
            res.v.eb(x, ln);
        };

        while (ia != a.size() && ib != b.size()) {
            if (a[ia].first == b[ib].first) {
                ll x = a[ia].first;
                auto ln = a[ia].second + b[ib].second;
                ++ia;
                ++ib;
                ad(x, ln);
                continue;
            }
            bool choosea;
            if (ib == b.size()) choosea = true;
            else if (ia == a.size()) choosea = false;
            else if (a[ia].first <= b[ib].first) choosea = true;
            else choosea = false;

            ll x;
            pair<ll, ll> ln;
            if (choosea) {
                tie(x, ln) = a[ia++];
                ln = ln + b[ib - 1].second;
            } else {
                tie(x, ln) = b[ib++];
                ln = ln + a[ia - 1].second;
            }

            ad(x, ln);
        }

        for (; ia < a.size(); ++ia)
            ad(a[ia].first, a[ia].second + b.back().second);
        for (; ib < b.size(); ++ib)
            ad(b[ib].first, b[ib].second + a.back().second);

        return res;
    }
};

struct item {
    convex_hull ch_a, ch_b, ch_c, ch_ac, ch_cb, ch_acb;

    template<typename T>
    void init(const T &t, int l, int r) {
        ch_a.push(t);
        ch_b.push(t);
        ch_c.push({-t.first * 2, -t.second * 2});
        ch_ac = convex_hull::add(ch_a, ch_c);
        ch_cb = convex_hull::add(ch_c, ch_b);
        ch_acb = convex_hull::add(ch_ac, ch_b);
    }

    void update(item &first, item &second, int l, int r) {
        ch_a = convex_hull::merge(first.ch_a, second.ch_a);
        ch_b = convex_hull::merge(first.ch_b, second.ch_b);
        ch_c = convex_hull::merge(first.ch_c, second.ch_c);

        ch_ac = convex_hull::merge(convex_hull::merge(first.ch_ac, second.ch_ac), convex_hull::add(first.ch_a, second.ch_c));
        ch_cb = convex_hull::merge(convex_hull::merge(first.ch_cb, second.ch_cb), convex_hull::add(first.ch_c, second.ch_b));

        ch_acb = convex_hull::merge(convex_hull::merge(first.ch_acb, second.ch_acb),
                 convex_hull::merge(convex_hull::add(first.ch_ac, second.ch_b), convex_hull::add(first.ch_a, second.ch_cb)));

        auto shr = [&](convex_hull &ch) {
            ch.v.clear();
            ch.v.shrink_to_fit();
        };

        shr(first.ch_a);
        shr(first.ch_b);
        shr(first.ch_c);
        shr(first.ch_ac);
        shr(first.ch_cb);
        shr(first.ch_acb);
        shr(second.ch_a);
        shr(second.ch_b);
        shr(second.ch_c);
        shr(second.ch_ac);
        shr(second.ch_cb);
        shr(second.ch_acb);
    }

    static item merge(item &first, item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}
ostream& operator << (ostream &o, const item &i) {
    return o << to_string(i);
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(n - 1) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    // item ask(int l, int r, int i, int vl, int vr) {
    //     if (l == vl && r == vr) {
    //         return tree[i];
    //     }
    //     int m = (vl + vr) >> 1;
    //     if (r <= m) {
    //         return ask(l, r, i * 2 + 1, vl, m);
    //     } else if (m < l) {
    //         return ask(l, r, i * 2 + 2, m + 1, vr);
    //     } else {
    //         return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
    //     }
    // }

    // item ask(int l, int r) {
    //     l = max(l, 0); r = min(r, n - 1);
    //     if (l > r) return item();
    //     return ask(l, r, 0, 0, n - 1);
    // }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, pair<int, int>>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --b;
        g[a].eb(b, mp(c, d));
        g[b].eb(a, mp(c, d));
    }

    vector<pair<ll, ll>> lines;

    y_combinator([&](auto dfs, int v, int p = -1, ll A = 0, ll B = 0) -> void {
        lines.eb(A, B);
        for (auto [k, ln] : g[v]) {
            if (k == p) continue;
            dfs(k, v, A + ln.first, B + ln.second);
            lines.eb(A, B);
        }
    })(0);
    show(lines);

    segtree tree(lines.size());
    tree.build(lines);
    auto ch = tree.tree[0].ch_acb;

    for (int t = 0; t < m; ++t) {
        cout << ch.ask(t) << ' ';
    }
    cout << '\n';

    // show(lines);
    // convex_hull ch;
    // for (int c = 0; c < lines.size(); ++c) {
    //     vector v1(lines.begin(), lines.begin() + c + 1);
    //     vector v2(lines.begin() + c, lines.end());
    //     sort(v1.begin(), v1.end());
    //     sort(v2.begin(), v2.end());
    //     convex_hull c1, c2;
    //     convex_hull cc;
    //     cc.push({-lines[c].first, -lines[c].second});
    //     for (auto p : v1)
    //         c1.push(p);
    //     for (auto p : v2)
    //         c2.push(p);

    //     c1 = convex_hull::add(c1, cc);
    //     c2 = convex_hull::add(c2, cc);

    //     ch = convex_hull::merge(ch, convex_hull::add(c1, c2));
    // }

    // for (int t = 0; t < m; ++t) {
    //     ll ans = 0;
    //     umax(ans, ch.ask(t));
    //     // for (int c = 0; c < ch.size(); ++c) {
    //     // }
    //     cout << ans << ' ';
    // }
    // cout << '\n';

    return 0;
}