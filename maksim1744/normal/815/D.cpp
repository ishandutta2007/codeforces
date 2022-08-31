/*
    author:  Maksim1744
    created: 31.01.2021 00:29:28
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
    ll sm = 0;
    ll mn = 1e9;
    ll mx = 0;
    ll mod;
    bool is_set = false;

    template<typename T>
    void init(const T &t, int l, int r) {
        mn = mx = sm = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        sm = first.sm + second.sm;
        mx = max(first.mx, second.mx);
        mn = min(first.mn, second.mn);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        is_set = true;
        mod = m;
        sm = (ll)m * (r - l + 1);
        mx = mn = m;
        // apply here, save for children
    }

    void push(item &first, item &second, int l, int r) {
        if (is_set) {
            int m = (l + r) / 2;
            first.modify(mod, l, m);
            second.modify(mod, m + 1, r);
            // reset modifier
            is_set = false;
        }
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
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return;
        modify(l, r, modifier, 0, 0, n - 1);
    }

    ll ask_bad(int l, int r, ll b, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        show(vl, vr, tree[i].mn, tree[i].mx, b);
        if (tree[i].mx <= b) return b * (r - l + 1);
        if (tree[i].mn >= b && l == vl && r == vr) return tree[i].sm;
        int m = (vl + vr) / 2;
        ll ans = 0;
        if (l <= m) ans += ask_bad(l, min(r, m), b, i * 2 + 1, vl, m);
        if (r >= m + 1) ans += ask_bad(max(l, m + 1), r, b, i * 2 + 2, m + 1, vr);
        return ans;
    }

    ll ask_bad(int l, int r, ll b) {
        l = max(l, 0);
        r = min(r, n - 1);
        if (l > r) return 0;
        return ask_bad(l, r, b, 0, 0, n - 1);
    }

    void add_point(int l, int r, ll v, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        // show(i, vl, vr, tree[i].mn, tree[i].mx, v);
        if (tree[i].mn >= v) return;
        if (tree[i].mx <= v && vl == l && vr == r) {
            // show(v, vl, vr);
            tree[i].modify(v, vl, vr);
            return;
        }
        int m = (vl + vr) / 2;
        if (l <= m) add_point(l, min(m, r), v, i * 2 + 1, vl, m);
        if (r >= m + 1) add_point(max(l, m + 1), r, v, i * 2 + 2, m + 1, vr);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
    }

    void add_point(int r, ll v) {
        int l = 0;
        r = min(r, n - 1);
        // show(l, r, v);
        if (l > r) return;
        add_point(l, r, v, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<pair<int, pair<int, int>>> cards(n);
    cin >> cards;
    sort(cards.begin(), cards.end());

    int ind = 0;

    vector<int> mxa(n + 1, 0), mxb(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        mxa[i] = max(mxa[i + 1], cards[i].second.first);
        mxb[i] = max(mxb[i + 1], cards[i].second.second);
    }

    ll ans = 0;
    segtree tree(q + 1);
    {
        vector<int> v(q + 1, 0);
        tree.build(v);
    }

    for (int A = 1; A <= p; ++A) {
        while (ind < n && cards[ind].first < A) {
            tree.add_point(cards[ind].second.first, cards[ind].second.second);
            ++ind;
        }
        int a = mxa[ind];
        int b = mxb[ind];

        // shows;
        // show(A, a, b, ind);
        // for (int i = 1; i <= q; ++i)
        //     cout << tree.ask(i, i).sm << ' ';
        // cout << endl;

        ll bad = tree.ask_bad(a + 1, q, b);
        show(bad);
        bad += (ll)a * r;
        show(bad);
        ans += (ll)q * r - bad;
        show(ans);
    }
    cout << ans << '\n';

    return 0;
}