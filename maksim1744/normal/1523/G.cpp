/*
    author:  Maksim1744
    created: 30.05.2021 19:03:29
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

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }
};

const int inf = 1e9;

struct item {
    set<pair<int, int>> s = {{-1, inf}};

    int ask(int r) const {
        auto it = s.lower_bound({r, -1});
        if (it == s.end() || it->first > r) --it;
        return it->second;
    }

    template<typename T>
    void init(const T &t, int, int) {
        auto [r, val] = t;
        if (ask(r) <= val) return;
        auto it = s.lower_bound({r, val});
        while (it != s.end()) {
            auto it1 = next(it);
            if (it->second < val) break;
            s.erase(it);
            it = it1;
        }
        s.emplace(r, val);
    }

    void update(const item &first, const item &second, int l, int r) {
        assert(false);
    }

    static item merge(const item &first, const item &second, int l, int r) {
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

    int ask(int l, int r, int R, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask(R);
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, R, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, R, i * 2 + 2, m + 1, vr);
        } else {
            return min(ask(l, m, R, i * 2 + 1, vl, m), ask(m + 1, r, R, i * 2 + 2, m + 1, vr));
        }
    }

    int ask(int l, int R) {
        int r = n - 1;
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return 1e9;
        return ask(l, r, R, 0, 0, n - 1);
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
            // tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            tree[i].init(t, st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    cin >> v;
    --v;
    const int B = 20;
    vector<int> ans(n + 1, 0);

    for (int k = 1; k <= n && k <= B; ++k) {
        shows;
        if (k <= B) {
            fenwick<int> tree(n);
            for (auto [l, r] : v) {
                if (r - l + 1 < k) continue;
                int s = tree.ask(l, r);
                if (s != 0) continue;
                show(l, r);
                ans[k] += r - l + 1;
                for (int i = l; i <= r; ++i)
                    tree.add(i, 1);
            }
        }
    }
    if (B + 1 <= n) {
        vector<vector<int>> with_len(n + 1);
        for (int i = 0; i < m; ++i) {
            auto [l, r] = v[i];
            with_len[r - l + 1].pb(i);
        }
        // k > B
        segtree tree(n);

        auto get_ans = y_combinator([&](auto get_ans, int l, int r) -> int {
            if (l > r) return 0;
            int ind = tree.ask(l, r);
            if (ind == inf) return 0;
            auto [l1, r1] = v[ind];
            return r1 - l1 + 1 + get_ans(l, l1 - 1) + get_ans(r1 + 1, r);
        });

        for (int k = n; k >= B + 1; --k) {
            for (int i : with_len[k]) {
                tree.set(v[i].first, mp(v[i].second, i));
            }
            ans[k] = get_ans(0, n - 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    cout << '\n';

    return 0;
}