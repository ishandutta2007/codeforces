/*
    author:  Maksim1744
    created: 12.09.2020 17:13:09
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
#endif

struct item {
    ll value = 0;
    ll l = 0;
    ll r = 0;
    ll mod_sm = 0;  // modify sum, not sum on [l; r] !!!

    item() {}
    item(ll value, ll l = 0, ll r = 0): value(value), l(l), r(r) {}

    ll ask() {
        return value + mod_sm * (r - l + 1);
    }
};

item operator + (item a, item b) {
    return item(a.ask() + b.ask(), a.l, b.r);
}

struct segtree {
    vector<item> tree;
    int n;

    segtree(int size) : segtree(vector<int>(size, 0)) {}
    template<typename InType>
    segtree(vector<InType> v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template<typename InType>
    void build(vector<InType>& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item(v[l], l, l);
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
            tree[i].value = k - tree[i].mod_sm;
            return;
        }
        int m = (vl + vr) / 2;
        if (ind <= m) set(ind, k - tree[i].mod_sm, 2 * i + 1, vl, m);
        else set(ind, k - tree[i].mod_sm, 2 * i + 2, m + 1, vr);
        tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
    }

    template<typename InType>
    void set(int ind, InType k) {
        set(ind, k, 0, 0, n - 1);
    }

    template<typename InType>
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].mod_sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            add(    l, m, k, 2 * i + 1,    vl,  m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
    }

    template<typename InType>
    void add(int l, int r, InType k) {
        add(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].mod_sm * (r - l + 1);
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
        return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<ll> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = max(0ll, a[i + 1] - a[i]);
    }
    ll sm = sum(d);
    segtree tree(n);
    for (int i = 0; i < n; ++i) {
        tree.set(i, a[i]);
    }
    auto upd = [&](int i) {
        if (i >= n - 1 || i <= -1) return;
        ll cur = d[i];
        ll next = max(0ll, tree.ask(i + 1, i + 1) - tree.ask(i, i));
        sm += next - cur;
        d[i] = next;
    };
    auto calc = [&]() {
        ll a0 = tree.ask(0, 0);
        show(a0, sm);
        ll b1 = (a0 - sm) / 2;
        cout << max(b1 + sm, a0 - b1) << '\n';
    };
    calc();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        ll delta;
        cin >> l >> r >> delta;
        --l; --r;
        // show(l, r);
        tree.add(l, r, delta);
        upd(l - 1);
        upd(r);
        calc();
    }

    return 0;
}