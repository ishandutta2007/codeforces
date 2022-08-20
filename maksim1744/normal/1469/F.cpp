/*
    author:  Maksim1744
    created: 28.12.2020 18:41:10
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
    ll sm = 0;
    ll mod = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        sm = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        sm = first.sm + second.sm;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        // apply here, save for children
        sm += m * (r - l + 1);
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
        r = min(r, n - 1);
        l = max(l, 0);
        if (l > r) return;
        modify(l, r, modifier, 0, 0, n - 1);
    }

    int first_one(int i, int l, int r) {
        if (l != r) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
        }
        if (l == r) {
            assert(tree[i].sm > 0);
            return l;
        }
        int m = (l + r) >> 1;
        if (tree[i * 2 + 1].sm != 0) return first_one(i * 2 + 1, l, m);
        else return first_one(i * 2 + 2, m + 1, r);
    }

    int first_one() {
        if (ask(0, n - 1).sm == 0) return 1e9;
        return first_one(0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> ln(n);
    cin >> ln;
    sort(ln.begin(), ln.end());
    reverse(ln.begin(), ln.end());
    ll can = 1;
    bool ok = false;
    for (auto l : ln) {
        can = can + l - 2;
    }
    if (can < k) {
        cout << -1 << '\n';
        return 0;
    }
    ll l = 0, r = 1e6;
    while (r - l > 1) {
        ll c = (l + r) / 2;
        segtree tree(c + 1);
        tree.set(0, 1);
        int done = 0;
        for (auto l : ln) {
            ++done;
            ll was = tree.ask(0, c).sm;
            if (was >= k) break;
            int ind = tree.first_one();
            if (ind >= c - 1) break;

            // {
            //     int iind = -1;
            //     for (int i = 0; i <= c; ++i) {
            //         ll u = tree.ask(i, i).sm;
            //         assert(u >= 0);
            //         if (u > 0) {
            //             iind = i;
            //             break;
            //         }
            //     }
            //     assert(iind == ind);
            // }

            tree.modify(ind, ind, -1);
            ll a = (l - 1) / 2;
            ll b = l - 1 - a;
            // if (c == 2) show(l, a, b, c);
            tree.modify(ind + 2, ind + 2 + a - 1, 1);
            tree.modify(ind + 2, ind + 2 + b - 1, 1);
            ll cur = tree.ask(0, c).sm;
            assert(cur > was);
            if (cur >= k) break;
            // if (c == 22 && __builtin_popcount(done + 1) == 1) {
            //     cerr << "done: " << done << endl;
            //     for (int i = 0; i <= c; ++i) {
            //         cerr << tree.ask(i, i).sm << ' ';
            //     }
            //     cerr << '\n';
            // }
        }
        // cerr << c << ' ' << tree.ask(0, c).sm << '\n';
        if (tree.ask(0, c).sm >= k) {
            r = c;
        } else {
            l = c;
        }
    }
    assert(r != 1e6);
    cout << r << '\n';

    return 0;
}