/*
    author:  Maksim1744
    created: 24.05.2021 12:14:21
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

struct item {
    int sm = 0;
    bool has_mod = false;
    int mod = 0;

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
        sm = (r - l + 1) * m;
        mod = m;
        has_mod = true;
    }

    void push(item &first, item &second, int l, int r) {
        if (has_mod) {
            int m = (l + r) / 2;
            first.modify(mod, l, m);
            second.modify(mod, m + 1, r);
            has_mod = false;
        }
        // reset modifier
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

    int last_one(int i, int l, int r) {
        if (l != r) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
        }
        if (tree[i].sm == 0) return -1;
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        int res = last_one(i * 2 + 2, m + 1, r);
        if (res != -1) return res;
        return last_one(i * 2 + 1, l, m);
    }

    int last_one() {
        return last_one(0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    cin >> v;
    set<int> locks, unlocks;
    segtree tree(n);
    bool locked = false;
    for (int i = 0; i < n; ++i) {
        if (v[i] == "lock") {
            locks.insert(i);
            locked = true;
        } else if (v[i] == "unlock") {
            unlocks.insert(i);
            locked = false;
        } else {
            if (!locked)
                tree.set(i, 1);
        }
    }
    locks.insert(n);
    unlocks.insert(n);
    locks.insert(-2);
    unlocks.insert(-1);

    auto ask = [&]() {
        int ind = tree.last_one();
        if (ind == -1)
            cout << "blue\n";
        else
            cout << v[ind] << '\n';
    };
    ask();

    int q;
    cin >> q;
    while (q--) {
        shows;
        int i;
        string s;
        cin >> i >> s;
        --i;

        if (v[i] == "lock") {
            locks.erase(i);
            int r = min(*unlocks.lower_bound(i), *locks.lower_bound(i + 1));
            tree.modify(i + 1, r - 1, 1);
            auto it = prev(locks.lower_bound(i));
            r = min(*unlocks.lower_bound(*it), *locks.lower_bound(i + 1));
            tree.modify(*it + 1, r - 1, 0);
        } else if (v[i] == "unlock") {
            unlocks.erase(i);
            int r = min(*locks.lower_bound(i), *unlocks.lower_bound(i + 1));
            tree.modify(i + 1, r - 1, 0);
            auto it = prev(unlocks.lower_bound(i));
            r = min(*locks.lower_bound(*it), *unlocks.lower_bound(i + 1));
            tree.modify(*it + 1, r - 1, 1);
        }

        if (s == "lock") {
            int r = *unlocks.lower_bound(i);
            tree.modify(i + 1, r - 1, 0);
            locks.insert(i);
        } else if (s == "unlock") {
            int r = min(*locks.lower_bound(i), *unlocks.lower_bound(i));
            tree.modify(i + 1, r - 1, 1);
            unlocks.insert(i);
        }

        if (s == "lock" || s == "unlock") tree.set(i, 0);
        else if (*prev(locks.lower_bound(i)) <= *prev(unlocks.lower_bound(i))) tree.set(i, 1);
        else tree.set(i, 0);

        v[i] = s;
        debug {
            show(v);
            show(locks, unlocks);
            for (int i = 0; i < n; ++i) {
                cerr << tree.ask(i, i).sm << ' ';
            }
            cerr << endl;
        }
        ask();
    }

    return 0;
}