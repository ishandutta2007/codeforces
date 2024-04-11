/*
    author:  Maksim1744
    created: 24.03.2022 18:54:11
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

using i128 = __int128_t;

istream& operator >> (istream& i, i128& x) {
    x = 0;
    string s;
    i >> s;
    for (char c : s) {
        c -= '0';
        x = x * 10 + c;
    }
    return i;
}

i128 gcd(i128 a, i128 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

namespace segtree_ns {
struct item {
    i128 v;

    template<typename T>
    void init(const T &t, int l, int r) {
        v = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        v = first.v / gcd(first.v, second.v) * second.v;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }
};
OSTREAM(item, v);

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
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
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, i * 2 + 2, m + 1, vr);
        } else {
            return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
        }
    }

    item ask(int l, int r) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return item();
        return ask(l, r, 0, 0, n - 1);
    }

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

ostream& operator << (ostream& o, segtree& tree) {
#ifdef HOME
    vector<item> items;
    for (int i = 0; i < tree.n; ++i)
        items.push_back(tree.ask(i, i));
    const bool print_horizontal = true;
    if (print_horizontal) {
        for (int i = 0; i < items.size(); ++i) {
            if (i != 0) o << " ";
            o << items[i];
        }
    } else {
        for (int i = 0; i < items.size(); ++i) {
            o << '\n' << string(10, ' ');
            o << items[i];
        }
    }
#endif
    return o;
}

}
using namespace segtree_ns;

string to_string(__int128 x) {
    if (x == 0) return "0";
    __uint128_t k = x;
    if (k == (((__uint128_t)1) << 127)) return "-170141183460469231731687303715884105728";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream &operator << (ostream &o, __int128 x) {
    return o << to_string(x);
}

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<i128> a(n), b(m);
    cin >> a >> b;
    vector<segtree> ab(n);
    vector<segtree> ba(m);
    for (int i = 0; i < n; ++i) {
        vector<i128> cur(m);
        for (int j = 0; j < m; ++j) {
            cur[j] = gcd(a[i], b[j]);
        }
        ab[i].build(cur);
    }
    for (int i = 0; i < m; ++i) {
        vector<i128> cur(n);
        for (int j = 0; j < n; ++j) {
            cur[j] = gcd(b[i], a[j]);
        }
        ba[i].build(cur);
    }

    vector<bool> ua(n, true), ub(m, true);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (ab[i].tree[0].v != a[i]) {
            q.emplace(0, i);
            ua[i] = false;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ba[i].tree[0].v != b[i]) {
            q.emplace(1, i);
            ub[i] = false;
        }
    }

    while (!q.empty()) {
        auto [who, ind] = q.front();
        q.pop();
        if (who == 0) {
            for (int i = 0; i < m; ++i) {
                if (!ub[i]) continue;
                ba[i].set(ind, 1);
                if (ba[i].tree[0].v != b[i]) {
                    ub[i] = false;
                    q.emplace(1, i);
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (!ua[i]) continue;
                ab[i].set(ind, 1);
                if (ab[i].tree[0].v != a[i]) {
                    ua[i] = false;
                    q.emplace(0, i);
                }
            }
        }
    }

    vector<i128> ansa, ansb;
    for (int i = 0; i < n; ++i) {
        if (ua[i]) ansa.pb(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        if (ub[i]) ansb.pb(b[i]);
    }

    if (ansa.empty() || ansb.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ansa.size() << ' ' << ansb.size() << '\n';
    cout << ansa << '\n';
    cout << ansb << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}