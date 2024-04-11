/*
    author:  Maksim1744
    created: 19.01.2021 17:54:12
*/

#include "bits/stdc++.h"

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
    ll mn = 0;
    ll mod = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        mn = t;
        mod = 0;
    }

    void update(const item &first, const item &second, int l, int r) {
        mn = min(first.mn, second.mn);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        // apply here, save for children
        mn += m;
        mod += m;
    }

    void push(item &first, item &second, int l, int r) {
        int m = (l + r) / 2;
        first.modify(mod, l, m);
        second.modify(mod, m + 1, r);
        // reset modifier
        mod = 0;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
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
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
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
        if (l > r) return item();
        return ask(l, r, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            if (l != r) {
                tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
            }
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

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        if (l == vl && r == vr) {
            tree[i].modify(modifier, vl, vr);
            return;
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            modify(l, r, modifier, i * 2 + 1, vl, m);
        } else if (m < l) {
            modify(l, r, modifier, i * 2 + 2, m + 1, vr);
        } else {
            modify(l, m, modifier, i * 2 + 1, vl, m);
            modify(m + 1, r, modifier, i * 2 + 2, m + 1, vr);
        }
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
    }

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier) {
        if (l > r) return;
        modify(l, r, modifier, 0, 0, n - 1);
    }
};

struct S {
    vector<ll> a;
    vector<ll> pref_min, suf_min;
    int cur_last, cur_mn;
    int n;
    vector<pair<int, ll>> mods1;
    vector<pair<pair<int, int>, ll>> mods2;

    S (const vector<ll> &v) : a(v) {
        pref_min = suf_min = a;
        n = a.size();
        for (int i = 1; i < a.size(); ++i)
            pref_min[i] = min(pref_min[i - 1], a[i]);
        for (int i = (int)a.size() - 2; i >= 0; --i)
            suf_min[i] = min(suf_min[i + 1], a[i]);
    }

    void modify(int l, int r, ll x) {
        r = min(r, n - 1);
        l = max(l, 0);
        if (l > r) return;
        if (l == r && mods1.empty()) {
            mods1.eb(l, x);
        } else {
            assert(r == n - 1);
            mods2.eb(mp(l, r), x);
        }
    }

    ll get_last() {
        if (!mods1.empty() && mods1.back().first == n - 1) {
            return a.back() + mods1.back().second;
        }
        if (!mods2.empty())
            return a.back() + mods2.back().second;
        return a.back();
    }

    ll ask() {
        ll res = 1e18;
        int ind = n;
        // cerr << "a" << endl;
        show(mods1, mods2, a);
        if (!mods1.empty()) ind = min(ind, mods1.back().first);
        if (!mods2.empty()) ind = min(ind, mods2.back().first.first);
        if (ind > 0) res = min(res, pref_min[ind - 1]);
        show(ind, res);
        // cerr << "b" << endl;
        if (!mods2.empty()) res = min(res, suf_min[mods2.back().first.first] + mods2.back().second);
        if (!mods1.empty()) res = min(res, a[mods1.back().first] + mods1.back().second);
        // cerr << "c" << endl;
        return res;
    }

    void cancel() {
        mods1.clear();
        mods2.clear();
    }
};

void test_case(int test) {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<ll> sums(n);
    sums[0] = a[0];
    for (int i = 1; i < n; ++i)
        sums[i] = a[i] - sums[i - 1];
    if (mine(sums) >= 0 && sums.back() == 0) {
        cout << "YES\n";
        return;
    }
    vector<ll> ae, ao;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) ao.pb(sums[i]);
        else ae.pb(sums[i]);
    }
    S even(ae);
    S odd(ao);
    // segtree even(ae.size());
    // even.build(ae);
    // segtree odd(ao.size());
    // odd.build(ao);
    show(ae, ao);
    for (int i = 0; i + 1 < n; ++i) {
        ll delta = a[i + 1] - a[i];
        delta *= 2;
        if (i % 2 == 0) {
            // cerr << "1" << endl;
            even.modify(i / 2, i / 2, a[i + 1] - a[i]);
            even.modify((i + 2) / 2, (int)ae.size() - 1, delta);
            // cerr << "2" << endl;
            // cerr << "3" << endl;
            odd.modify(i / 2, (int)ao.size() - 1, -delta);
            // cerr << "4" << endl;
            bool last_ok = false;
            if (n % 2 == 0) {
                last_ok = (odd.get_last() == 0);
            } else {
                last_ok = (even.get_last() == 0);
            }
            // cerr << "5" << endl;
            if (last_ok && min(even.ask(), odd.ask()) >= 0) {
                show(i);
                cout << "YES\n";
                return;
            }
            // cerr << "6" << endl;
            even.cancel();
            odd.cancel();
            // even.modify((i + 2) / 2, (int)ae.size() - 1, -delta);
            // even.modify(i / 2, i / 2, -a[i + 1] + a[i]);
            // odd.modify(i / 2, (int)ao.size() - 1, delta);
        } else {
            odd.modify(i / 2, i / 2, a[i + 1] - a[i]);
            even.modify((i + 2) / 2, (int)ae.size() - 1, -delta);
            odd.modify((i + 2) / 2, (int)ao.size() - 1, delta);
            bool last_ok = false;
            if (n % 2 == 0) {
                last_ok = (odd.get_last() == 0);
            } else {
                last_ok = (even.get_last() == 0);
            }
            show(even.ask());
            show(odd.ask());
            if (last_ok && min(even.ask(), odd.ask()) >= 0) {
                show(i);
                cout << "YES\n";
                return;
            }
            even.cancel();
            odd.cancel();
            // even.modify((i + 2) / 2, (int)ae.size() - 1, delta);
            // odd.modify(i / 2, i / 2, -a[i + 1] + a[i]);
            // odd.modify((i + 2) / 2, (int)ao.size() - 1, -delta);
        }
        show(i);
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}