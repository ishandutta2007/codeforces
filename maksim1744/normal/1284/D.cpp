/*
    author:  Maksim1744
    created: 04.01.2020 15:37:00
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

const int inf = 2 * 1e9 + 100;

struct item {
    bool is_equal = false;
    int equal = 0;
    int mx;

    item(int mx = -inf): mx(mx) {}

    int ask() {
        return is_equal ? equal : mx;
    }

    auto update(item& a, item& b) {
        if (a.ask() >= b.ask()) {  // return left maximum
            mx = a.ask();
        } else {
            mx = b.ask();
        }
    }
};

item operator + (item a, item b) {
    return item(max(a.ask(), b.ask()));
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
            tree[i] = item(v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template<typename InType>
    void set(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].is_equal = true;
            tree[i].equal = k;
            return;
        }
        int m = (vl + vr) / 2;
        if (tree[i].is_equal) {
            tree[i].is_equal = false;
            tree[2 * i + 1].is_equal = true;
            tree[2 * i + 1].equal = tree[i].equal;
            tree[2 * i + 2].is_equal = true;
            tree[2 * i + 2].equal = tree[i].equal;
        }
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
        set(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (tree[i].is_equal) {
            return tree[i].equal;
        }
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m);
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr);
        return max(ask(l, m, 2 * i + 1, vl, m), ask(m + 1, r, 2 * i + 2, m + 1, vr));
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> v(n);
    cin >> v;
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        x.pb(v[i].first.first);
        x.pb(v[i].first.second);
        x.pb(v[i].second.first);
        x.pb(v[i].second.second);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < n; ++i) {
        v[i].first.first = lowb(x, v[i].first.first);
        v[i].first.second = lowb(x, v[i].first.second);
        v[i].second.first = lowb(x, v[i].second.first);
        v[i].second.second = lowb(x, v[i].second.second);
    }
    for (int iii = 0; iii < 2; ++iii) {
        sort(v.begin(), v.end());
        vector<vector<pair<int, int>>> ad(x.size()), ch(x.size());
        for (int i = 0; i < n; ++i) {
            ch[v[i].first.second].pb(v[i].second);
            ad[v[i].first.first].pb(v[i].second);
        }
        segtree tree(x.size());
        tree.set(0, x.size() - 1, 0);
        for (int i = x.size() - 1; i >= 0; --i) {
            for (auto p : ch[i]) {
                if (tree.ask(p.first, p.second) != 0) {
                    cout << "NO\n";
                    return 0;
                }
            }
            for (auto p : ad[i]) {
                tree.set(p.first, p.second, 1);
            }
        }
        // vector<int> lt(n);
        // lt.back() = v.back().second.first;
        // for (int i = n - 2; i >= 0; --i) {
        //     lt[i] = min(lt[i + 1], v[i].second.first);
        // }
        // for (int i = 0; i < n; ++i) {
        //     int ind = lowb(v, mp(mp(v[i].first.second + 1, -1), mp(-1, -1)));
        //     // if (ind >= n) break;
        //     if (ind < n && lt[ind] <= v[i].second.second) {
        //         // show(i, ind, v, lt);
        //         cout << "NO\n";
        //         return 0;
        //     }
        // }
        for (int i = 0; i < n; ++i) {
            swap(v[i].first, v[i].second);
        }
    }
    cout << "YES\n";

    return 0;
}