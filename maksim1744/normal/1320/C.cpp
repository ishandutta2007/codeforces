/*
    author:  Maksim1744
    created: 01.03.2020 16:48:09
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int N = 15;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
const int N = 1e6 + 20;
#endif

const int inf = 1e9 * 2 + 5;

struct item {
    int mx = 0;
    int ind = 0;  // index of maximum
    int sm = 0;

    item() {}
    item(int mx, int ind = 0): mx(mx), ind(ind), sm(0) {}

    auto ask() {
        return mx + sm;
    }

    auto update(item& a, item& b) {
        if (a.ask() >= b.ask()) {  // return left maximum
            mx = a.ask();
            ind = a.ind;
        } else {
            mx = b.ask();
            ind = b.ind;
        }
        return *this;
    }
};

item operator + (item a, item b) {
    return item().update(a, b);
}

item operator + (item a, int b) {
    item c = a;
    c.mx += b;
    return c;
}

struct segtree {
    vector<item> tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, item()) {
        vector<decltype(item().mx)> v(n, -inf);
        build(v, 0, 0, n - 1);
    }
    template<typename InType>
    segtree(vector<InType>& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template<typename InType>
    void build(vector<InType>& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item(v[l], l);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template<typename InType>
    void set(int ind, InType k, int i, int vl, int vr) {
        if (vl == vr) {
            tree[i].mx = k - tree[i].sm;
            return;
        }
        int m = (vl + vr) / 2;
        if (ind <= m) set(ind, k - tree[i].sm, 2 * i + 1, vl, m);
        else set(ind, k - tree[i].sm, 2 * i + 2, m + 1, vr);
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template<typename InType>
    void set(int ind, InType k) {
        set(ind, k, 0, 0, n - 1);
    }

    template<typename InType>
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            add(    l, m, k, 2 * i + 1,    vl,  m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template<typename InType>
    void add(int l, int r, InType k) {
        if (l > r)
            return;
        add(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        return max(ask(l, m, 2 * i + 1, vl, m), ask(m + 1, r, 2 * i + 2, m + 1, vr)) + tree[i].sm;
    }

    auto ask(int l, int r) {
        if (l > r)
            return -inf;
        return ask(l, r, 0, 0, n - 1);
    }

    auto ask_item(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return item(tree[i].ask(), tree[i].ind);
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_item(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        if (l > m)
            return ask_item(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        return ask_item(l, m, 2 * i + 1, vl, m) + ask_item(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
    }

    auto ask_item(int l, int r) {
        if (l > r)
            return item(-inf);
        return ask_item(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<int, int>> a(n), b(m);
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        a[i].first--;
    }
    for (int i = 0; i < m; ++i) {
        b[i].first--;
    }
    vector<pair<pair<int, int>, int>> c(p);
    cin >> c;
    int ic = 0;
    sort(c.begin(), c.end());

    vector<int> mnx(N, inf);
    for (auto [x, y] : b) {
        mnx[x] = min(mnx[x], y);
    }
    for (int i = N - 2; i >= 0; --i)
        mnx[i] = min(mnx[i], mnx[i + 1]);
    for (int i = 0; i < N; ++i) {
        mnx[i] = -mnx[i];
    }
    show(mnx);
    segtree tree(mnx);
    int ans = -inf;
    show(c);
    for (auto [x, y] : a) {
        shows;
        while (ic < c.size() && c[ic].first.first <= x) {
            tree.add(c[ic].first.second, N - 1, c[ic].second);
            ++ic;
        }
        show(ic);
        show(y);
        ans = max(ans, tree.ask(0, N - 1) - y);
    }
    cout << ans << endl;

    return 0;
}