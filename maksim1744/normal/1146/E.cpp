/*
    author:  Maksim1744
    created: 20.04.2019 22:38:51
*/

#include <bits/stdc++.h>

using namespace std;

struct item;
string to_string(item t);

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

#ifdef HOMEn
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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int inf = 2 * 1e9 + 100;

struct item {
    bool is_equal = false;
    int equal = 0;
    int mx;
    int sm = 0;
    int mod_sm = 0;
    int l = 0, r = 0;

    item(int value = -inf, int l = -1, int r = -1): mx(value), l(l), r(r), sm(value == -inf ? 0 : value) {}

    auto ask_mx() {
        return is_equal ? equal : mx;
    }

    auto ask_sm() {
        return is_equal ? equal * (r - l + 1) : sm;
    }

    auto update(item& a, item& b) {
        equal = 0;
        is_equal = false;
        mod_sm = 0;
        if (a.ask_mx() >= b.ask_mx()) {  // return left maximum
            mx = a.ask_mx();
        } else {
            mx = b.ask_mx();
        }
        sm = a.ask_sm() + b.ask_sm();
        l = a.l; r = b.r;
        return *this;
    }
};

string to_string(item t) {
    return "[is_eq = " + to_string(t.is_equal) + ", equal = " + to_string(t.equal) + ", mx = " + to_string(t.mx) +
        ", sm = " + to_string(t.sm) + ", mod_sm = " + to_string(t.mod_sm) +
        ", (l,r) = (" + to_string(t.l) + "," + to_string(t.r) + ")]";
}

item operator + (item a, item b) {
    return item().update(a, b);
}

struct segtree {
    vector<item> tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, item()) {}
    template<typename InType>
    segtree(vector<InType>& v) : n(v.size()), tree(v.size() * 4) {
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

    void push(int i, int l, int r) {
        if (l == r)
            return;
        if (tree[i].is_equal) {
            tree[2 * i + 1].equal = tree[i].equal;
            tree[2 * i + 1].is_equal = true;

            tree[2 * i + 2].equal = tree[i].equal;
            tree[2 * i + 2].is_equal = true;
        } else {
            if (tree[2 * i + 1].is_equal) {
                tree[2 * i + 1].equal += tree[i].mod_sm;
            } else {
                tree[2 * i + 1].mod_sm += tree[i].mod_sm;
                tree[2 * i + 1].mx += tree[i].mod_sm;
                tree[2 * i + 1].sm += tree[i].mod_sm * (tree[2 * i + 1].r - tree[2 * i + 1].l + 1);
            }

            if (tree[2 * i + 2].is_equal) {
                tree[2 * i + 2].equal += tree[i].mod_sm;
            } else {
                tree[2 * i + 2].mod_sm += tree[i].mod_sm;
                tree[2 * i + 2].mx += tree[i].mod_sm;
                tree[2 * i + 2].sm += tree[i].mod_sm * (tree[2 * i + 2].r - tree[2 * i + 2].l + 1);
            }
        }
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template<typename InType>
    void set(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].is_equal = true;
            tree[i].equal = k;
            return;
        }
        int m = (vl + vr) / 2;
        push(i, vl, vr);
        if (r <= m) set(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) set(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            set(    l, m, k, 2 * i + 1,    vl,  m);
            set(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template<typename InType>
    void set(int l, int r, InType k) {
        if (l > r)
            return;
        set(l, r, k, 0, 0, n - 1);
    }

    template<typename InType>
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            if (tree[i].is_equal) {
                tree[i].equal += k;
            } else {
                tree[i].mod_sm += k;
                tree[i].sm += k * (tree[i].r - tree[i].l + 1);
                tree[i].mx += k;
            }
            return;
        }
        int m = (vl + vr) / 2;
        push(i, vl, vr);
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

    auto ask_mx(int l, int r, int i, int vl, int vr) {
        if (tree[i].is_equal) {
            return tree[i].equal;
        }
        if (l == vl && r == vr) {
            return tree[i].ask_mx();
        }
        push(i, vl, vr);
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_mx(l, r, 2 * i + 1, vl, m);
        if (l > m)
            return ask_mx(l, r, 2 * i + 2, m + 1, vr);
        return max(ask_mx(l, m, 2 * i + 1, vl, m), ask_mx(m + 1, r, 2 * i + 2, m + 1, vr));
    }

    auto ask_mx(int l, int r) {
        if (l > r)
            return -inf;
        return ask_mx(l, r, 0, 0, n - 1);
    }

    auto ask_sm(int l, int r, int i, int vl, int vr) {
        if (tree[i].is_equal) {
            return tree[i].equal * (r - l + 1);
        }
        if (l == vl && r == vr) {
            return tree[i].ask_sm();
        }
        push(i, vl, vr);
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_sm(l, r, 2 * i + 1, vl, m);
        if (l > m)
            return ask_sm(l, r, 2 * i + 2, m + 1, vr);
        return ask_sm(l, m, 2 * i + 1, vl, m) + ask_sm(m + 1, r, 2 * i + 2, m + 1, vr);
    }

    auto ask_sm(int l, int r) {
        if (l > r)
            return 0;
        return ask_sm(l, r, 0, 0, n - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    // vector<int> b = a;
    // sort(b.begin(), b.end());
    // b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> pos;
    vector<int> neg;
    vector<pair<char, int>> qs(q);
    cin >> qs;
    // for (auto& p : qs) {
    //     qs.second = 
    // }
    for (auto c : a) {
        if (c < 0)
            neg.pb(-c);
        else if (c > 0)
            pos.pb(c);
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    show(pos);
    int m = pos.size();
    vector<int> vpos(max(2, m), 0);
    segtree tpos(vpos);
    if (m == 0) {
        tpos = segtree(2);
    } else {
        for (auto pr : qs) {
            char c = pr.first;
            int x = pr.second;
            if (c == '<') {
                if (x > 0) {
                    int ind = lowb(pos, x);
                    // if (pos[ind] == x)
                        --ind;
                    show(c, x, ind);
                    tpos.add(0, min(m - 1, ind), 1);
                    tpos.set(ind + 1, m - 1, 0);
                } else {
                    x = -x;
                    int ind = lowb(pos, x);
                    if (pos[ind] == x)
                        ++ind;
                    show(c, x, ind);
                    tpos.set(ind, m - 1, 0);
                }
            } else {
                if (x > 0) {
                    int ind = lowb(pos, x);
                    if (pos[ind] == x)
                        ++ind;
                    show(c, x, ind);
                    tpos.set(ind, m - 1, 1);
                } else {
                    x = -x;
                    int ind = lowb(pos, x);
                    // if (pos[ind] == x)
                        --ind;
                    show(c, x, ind);
                    tpos.add(0, min(m - 1, ind), 1);
                    tpos.set(ind + 1, m - 1, 1);
                }
            }
#ifdef TAG_LENGTH
            for (int i = 0; i < m; ++i) {
                cout << tpos.ask_mx(i, i);
            }
            cout << '\n';
#endif
        }
    }

    sort(neg.begin(), neg.end());
    neg.erase(unique(neg.begin(), neg.end()), neg.end());
    show(neg);
    m = neg.size();
    vector<int> vneg(max(2, m), 0);
    segtree tneg(vneg);
    if (m == 0) {
        tneg = segtree(2);
    } else {
        for (auto pr : qs) {
            char c = pr.first;
            int x = pr.second;
            if (c == '<') c = '>';
            else c = '<';
            x = -x;
            if (c == '<') {
                if (x > 0) {
                    int ind = lowb(neg, x);
                    // if (neg[ind] == x)
                        --ind;
                    show(c, x, ind);
                    tneg.add(0, min(m - 1, ind), 1);
                    tneg.set(ind + 1, m - 1, 0);
                } else {
                    x = -x;
                    int ind = lowb(neg, x);
                    if (neg[ind] == x)
                        ++ind;
                    tneg.set(ind, m - 1, 0);
                }
            } else {
                if (x > 0) {
                    int ind = lowb(neg, x);
                    if (neg[ind] == x) {
                        ++ind;
                    }
                    tneg.set(ind, m - 1, 1);
                } else {
                    x = -x;
                    int ind = lowb(neg, x);
                    // if (neg[ind] == x)
                        --ind;
                    tneg.add(0, min(m - 1, ind), 1);
                    tneg.set(ind + 1, m - 1, 1);
                }
            }
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > 0) {
            if (tpos.ask_mx(lowb(pos, a[i]), lowb(pos, a[i])) % 2 == 1)
                a[i] = -a[i];
        } else if (a[i] < 0) {
            if (tneg.ask_mx(lowb(neg, -a[i]), lowb(neg, -a[i])) % 2 == 1)
                a[i] = -a[i];
        }
    }
    cout << a << '\n';
    return 0;
}