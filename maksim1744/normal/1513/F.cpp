/*
    author:  Maksim1744
    created: 11.04.2021 18:28:13
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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

struct item {
    ll mx = 0;

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
        tree[i].init(max(tree[i].mx, t), l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }

    int first_at_least(int l, int r, int v, int i, int vl, int vr) {
        show(l, r, tree[i].mx);
        if (tree[i].mx < v) return -1;
        if (vl == vr) {
            return vl;
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            return first_at_least(l, r, v, i * 2 + 1, vl, m);
        } else if (l > m) {
            return first_at_least(l, r, v, i * 2 + 2, m + 1, vr);
        } else {
            int ans = first_at_least(l, m, v, i * 2 + 1, vl, m);
            if (ans != -1) return ans;
            return first_at_least(m + 1, r, v, i * 2 + 2, m + 1, vr);
        }
    };

    int first_at_least(int l, int r, int v) {
        return first_at_least(l, r, v, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    cin >> a >> b;
    vector<pair<ll, ll>> v;
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        v.eb(a[i], b[i]);
        tot += abs(a[i] - b[i]);
    }
    ll ans = tot;

    vector<ll> x;
    for (int i = 0; i < n; ++i) {
        x.pb(a[i]);
        x.pb(b[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    for (int ii = 0; ii < 2; ++ii) {

        {
            segtree tree(x.size());

            for (auto [a, b] : v) {
                tree.set(lowb(x, a), b);
            }
            for (auto [a, b] : v) {
                if (a > b) {
                    if (tree.ask(0, lowb(x, b)).mx >= a) {
                        ans = min(ans, tot - 2 * abs(a - b));
                    }
                }
            }
        }

        {
            sort(v.begin(), v.end());

            show(v);

            segtree tree(x.size());
            for (auto [a, b] : v) {
                if (a <= b) {
                    tree.set(lowb(x, a), b);
                } else {
                    shows;
                    int ind = lowb(x, b);
                    int i2 = tree.first_at_least(ind, lowb(x, a), a);
                    show(ind, a);
                    show(x);
                    show(i2);
                    debug {
                        for (int i = 0; i < x.size(); ++i)
                            cerr << tree.ask(i, i).mx << ' ';
                        cerr << endl;
                    }
                    if (i2 != -1) {
                        ans = min(ans, tot - 2 * abs(a - x[i2]));
                    }
                }
            }
        }

        for (int i = 0; i < v.size(); ++i) {
            swap(v[i].first, v[i].second);
        }
    }

    cout << ans << '\n';

    return 0;
}