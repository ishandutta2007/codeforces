/*
    author:  Maksim1744
    created: 01.08.2021 23:51:10
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct item {
    int mx = -1;

    template<typename T>
    void init(const T &t, int l, int r) {
        mx = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        mx = max(first.mx, second.mx);
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n), b(m);
    cin >> a >> b;

    auto getmx = [&](const vector<int> &a) {
        int n = a.size();
        vector<int> mx(n, 0);
        vector<int> left(n, -1);
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && a[st.back()] >= a[i])
                st.pop_back();
            if (!st.empty())
                left[i] = st.back();
            st.pb(i);
        }

        st.clear();
        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && a[st.back()] > a[i])
                st.pop_back();
            if (!st.empty())
                right[i] = st.back();
            st.pb(i);
        }
        segtree tree(n);
        tree.build(a);
        const int inf = 1e6;
        for (int i = 0; i < n; ++i) {
            mx[i] = min((left[i] == -1 ? inf : tree.ask(left[i] + 1, i).mx), (right[i] == n ? inf : tree.ask(i, right[i] - 1).mx));
        }
        return mx;
    };

    auto mxa = getmx(a);
    auto mxb = getmx(b);

    vector<pair<int, int>> pts;
    for (int i = 0; i < m; ++i) {
        pts.eb(-mxb[i], b[i]);
    }

    vector<pair<int, pair<int, int>>> que;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        // a[i] + b[j] <= x, mxa[i] + b[j] > x => x - mxa[i] + 1 <= b[j] <= x - a[i]
        // a[i] + mxb[j] > x => -x + a[i] - 1 >= -mxb[j]
        que.eb(-x + a[i] - 1, mp(x - mxa[i] + 1, x - a[i]));
    }

    auto xs = b;
    for (auto [j, lr] : que) {
        xs.pb(lr.first);
        xs.pb(lr.second);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    fenwick<int> tree(xs.size());
    sort(pts.begin(), pts.end());
    sort(que.begin(), que.end());

    int ind = 0;
    for (auto [j, lr] : que) {
        while (ind < pts.size() && pts[ind].first <= j) {
            tree.add(lowb(xs, pts[ind].second), 1);
            ++ind;
        }

        auto [l, r] = lr;
        ans += tree.ask(lowb(xs, l), lowb(xs, r));
    }

    cout << ans << '\n';

    return 0;
}