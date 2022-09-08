/*
    author:  Maksim1744
    created: 06.09.2022 18:31:19
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

namespace segtree {

template<typename Item>
Item tree_merge(const Item& a, const Item& b) {
    Item i;
    i.update(a, b);
    return i;
}

template<typename Item, bool lazy>
struct Pusher {};

template<typename Item>
struct Pusher<Item, false> {
    void push(const vector<Item>&, int, int, int) {}
    Item ask_on_segment(const vector<Item>& tree, int n, int l, int r) {
        l |= n;
        r |= n;
        Item resl, resr;
        while (l <= r) {
            if (l & 1) {
                resl = tree_merge(resl, tree[l]);
                ++l;
            }
            if (!(r & 1)) {
                resr = tree_merge(tree[r], resr);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return tree_merge(resl, resr);
    }
    void push_point(const vector<Item>&, int, int) {}
};

template<typename Item>
struct Pusher<Item, true> {
    void push(vector<Item>& tree, int ind, int l, int r) {
        tree[ind].push(tree[ind * 2], tree[ind * 2 + 1], l, r);
    }

    Item ask_on_segment(vector<Item>& tree, int n, int l, int r) {
        int vl = 0, vr = n - 1;
        int i = 1;
        Item result;
        while (vl != vr) {
            int m = (vl + vr) / 2;
            if (l > m) {
                push(tree, i, vl, vr);
                i = i * 2 + 1;
                vl = m + 1;
            } else if (r <= m) {
                push(tree, i, vl, vr);
                i = i * 2;
                vr = m;
            } else {
                break;
            }
        }
        if (l == vl && r == vr) {
            return tree[i];
        }
        push(tree, i, vl, vr);
        // left
        {
            int ind = i * 2;
            int L = vl, R = (vl + vr) / 2;
            while (l != L) {
                int m = (L + R) / 2;
                push(tree, ind, L, R);
                if (l <= m) {
                    result = tree_merge(tree[ind * 2 + 1], result);
                    ind *= 2;
                    R = m;
                } else {
                    ind = ind * 2 + 1;
                    L = m + 1;
                }
            }
            result = tree_merge(tree[ind], result);
        }
        // right
        {
            int ind = i * 2 + 1;
            int L = (vl + vr) / 2 + 1, R = vr;
            while (r != R) {
                int m = (L + R) / 2;
                push(tree, ind, L, R);
                if (r > m) {
                    result = tree_merge(result, tree[ind * 2]);
                    ind = ind * 2 + 1;
                    L = m + 1;
                } else {
                    ind = ind * 2;
                    R = m;
                }
            }
            result = tree_merge(result, tree[ind]);
        }
        return result;
    }

    void push_point(vector<Item>& tree, int n, int ind) {
        int l = 0, r = n - 1;
        int i = 1;
        while (l != r) {
            push(tree, i, l, r);
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i *= 2;
            } else {
                l = m + 1;
                i = i * 2 + 1;
            }
        }
    }
};

template<typename Item, bool lazy = false>
struct Segtree {
    vector<Item> tree;
    Pusher<Item, lazy> pusher;
    int n;

    Segtree(int n = 0) {
        build(n);
    }

    template<typename U>
    Segtree(const vector<U>& v) {
        build(v);
    }

    void build(int n) {
        while (n & (n - 1)) ++n;
        this->n = n;
        tree.assign(n * 2, {});
    }

    template<typename U>
    void build(const vector<U>& v) {
        build(v.size());
        for (int i = 0; i < v.size(); ++i) {
            tree[n | i].init(v[i], i);
        }
        build();
    }

    void build() {
        for (int i = n - 1; i >= 1; --i) {
            tree[i].update(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    void push(int ind, int l, int r) {
        pusher.push(tree, ind, l, r);
    }

    template<typename T>
    void set(int ind, const T& t) {
        pusher.push_point(tree, n, ind);
        ind |= n;
        tree[ind].init(t, ind ^ n);
        ind >>= 1;
        while (ind) {
            tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
            ind >>= 1;
        }
    }

    template<typename T>
    void update(int ind, const T& t) {
        pusher.push_point(tree, n, ind);
        ind |= n;
        tree[ind].update(t, ind ^ n);
        ind >>= 1;
        while (ind) {
            tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
            ind >>= 1;
        }
    }

    Item& ith(int ind) {
        static_assert(!lazy, "don't use this method with lazy propagation, unless you're sure you need it");
        return tree[ind | n];
    }

    const Item& root() const {
        return tree[1];
    }

    Item ask(int l, int r) {
        l = max(l, 0);
        r = min(r, n - 1);
        if (l > r) return {};
        return pusher.ask_on_segment(tree, n, l, r);
    }

    template<typename T>
    void modify(int l, int r, const T& t) {
        show(l, r, t);
        static_assert(lazy, "lazy must be set to true to use this function");
        l = max(l, 0);
        r = min(r, n - 1);
        if (l > r) return;
        int vl = 0, vr = n - 1;
        int i = 1;
        while (vl != vr) {
            int m = (vl + vr) / 2;
            if (l > m) {
                push(i, vl, vr);
                i = i * 2 + 1;
                vl = m + 1;
            } else if (r <= m) {
                push(i, vl, vr);
                i = i * 2;
                vr = m;
            } else {
                break;
            }
        }
        if (l == vl && r == vr) {
            tree[i].modify(t, l, r);
        } else {
            push(i, vl, vr);
            // left
            {
                int ind = i * 2;
                int L = vl, R = (vl + vr) / 2;
                while (l != L) {
                    int m = (L + R) / 2;
                    push(ind, L, R);
                    if (l <= m) {
                        tree[ind * 2 + 1].modify(t, m + 1, R);
                        ind *= 2;
                        R = m;
                    } else {
                        ind = ind * 2 + 1;
                        L = m + 1;
                    }
                }
                tree[ind].modify(t, L, R);
                ind >>= 1;
                while (ind != i) {
                    tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
                    ind >>= 1;
                }
            }
            // right
            {
                int ind = i * 2 + 1;
                int L = (vl + vr) / 2 + 1, R = vr;
                while (r != R) {
                    int m = (L + R) / 2;
                    push(ind, L, R);
                    if (r > m) {
                        tree[ind * 2].modify(t, L, m);
                        ind = ind * 2 + 1;
                        L = m + 1;
                    } else {
                        ind = ind * 2;
                        R = m;
                    }
                }
                tree[ind].modify(t, L, R);
                ind >>= 1;
                while (ind != i) {
                    tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
                    ind >>= 1;
                }
            }
            tree[i].update(tree[i * 2], tree[i * 2 + 1]);
        }
        i >>= 1;
        while (i) {
            tree[i].update(tree[i * 2], tree[i * 2 + 1]);
            i >>= 1;
        }
    }
};

}
using segtree::Segtree;

struct Item {
    ll ti = 0;
    ll ans = 0;
    bool is_set = false;
    ll mod = 0;

    template<typename T>
    void init(const T& t, int ind) {
        ti = t;
    }

    void update(const Item& a, const Item& b) {
        ti = b.ti;
        ans = min(a.ans, b.ans);
    }

    //// similar to init, but more convenient for doing a[i] += x, implement only if needed
    // template<typename T> void update(const T& t, int ind) {}

    //// apply here, save for children
    template<typename T>
    void modify(const T& m, int l, int r) {
        mod = m;
        is_set = true;
        ans = mod - ti;
    }

    void push(Item& a, Item& b, int l, int r) {
        if (is_set) {
            int m = (l + r) / 2;
            a.modify(mod, l, m);
            b.modify(mod, m + 1, r);
            mod = 0;
            is_set = false;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    ll t;
    cin >> n >> t;
    vector<pair<ll, ll>> gc(n);
    cin >> gc;
    vector<ll> d(n - 1);
    cin >> d;
    d.insert(d.begin(), 0);
    for (int i = 1; i < n; ++i)
        d[i] += d[i - 1];

    vector<pair<ll, ll>> lrs;
    for (int i = 0; i < n; ++i) {
        auto [g, c] = gc[i];
        ll l = 0;
        l -= c;
        l -= d[i];
        ll r = l + g - 1;

        l = (l % t + t) % t;
        r = (r % t + t) % t;
        lrs.eb(l, r);
    }

    vector<ll> ts;
    ts.pb(0);
    ts.pb(t - 1);
    for (auto [l, r] : lrs) {
        ts.pb(l);
        ts.pb((l - 1 + t) % t);
        ts.pb(r);
        ts.pb((r + 1) % t);
    }
    sort(ts.begin(), ts.end());
    ts.erase(unique(ts.begin(), ts.end()), ts.end());

    Segtree<Item, true> tree(ts);
    show(lrs);

    debug {
        for (int i = 0; i < ts.size(); ++i) {
            cerr << ts[i] << ' ';
        }
        cerr << endl;
        cerr << string(20, '-') << endl;
    }

    for (int i = n - 1; i >= 0; --i) {
        auto [l, r] = lrs[i];
        l = lowb(ts, l);
        r = lowb(ts, r);

        debug {
            for (int i = 0; i < ts.size(); ++i) {
                cerr << tree.ask(i, i).ans << ' ';
            }
            cerr << endl;
        }

        ll start_ans = tree.ask(l, l).ans;
        if (l <= r) {
            if (l) {
                ll mod = start_ans + ts[l];
                tree.modify(0, l - 1, mod);
            }
            if (r != ts.size() - 1) {
                ll mod = start_ans + ts[l] + t;
                tree.modify(r + 1, ts.size() - 1, mod);
            }
        } else {
            ll mod = start_ans + ts[l];
            tree.modify(r + 1, l - 1, mod);
        }
    }

    ll ans = 8e18;
    for (int i = 0; i < ts.size(); ++i) {
        ans = min(ans, tree.ask(i, i).ans);
    }
    show(d);
    cout << ans + d.back() << '\n';

    return 0;
}