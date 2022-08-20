/*
    author:  Maksim1744
    created: 12.04.2021 18:54:00
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

// struct item {
//     int md;
//     int v;

//     template<typename T>
//     void init(const T &t, int l, int r) {
//         int v = 0;
//     }

//     void update(const item &first, const item &second, int l, int r) {
//         v = first.v;
//     }

//     static item merge(const item &first, const item &second, int l, int r) {
//         item res;
//         res.update(first, second, l, r);  // careful with different lengths
//         return res;
//     }

//     template<typename Modifier>
//     void modify(const Modifier &m, int l, int r) {
//         // apply here, save for children
//         md ^= m;
//         v ^= m;
//     }

//     void push(item &first, item &second, int l, int r) {
//         if (md) {
//             int m = (l + r) / 2;
//             first.modify(md, l, m);
//             second.modify(md, m + 1, r);
//         }
//         // reset modifier
//         md = 0;
//     }
// };

// string to_string(const item &i) {
//     stringstream ss;
//     ss << "[" << "]";
//     return ss.str();
// }
// ostream& operator << (ostream &o, const item &i) {
//     return o << to_string(i);
// }

// struct segtree {
//     vector<item> tree;
//     int n = 1;

//     segtree(int n = 1) : n(n) {
//         tree.resize(1 << (__lg(n - 1) + 2));
//     }

//     template<typename T>
//     void build(const vector<T> &v, int i, int l, int r) {
//         if (l == r) {
//             tree[i].init(v[l], l, r);
//             return;
//         }
//         int m = (l + r) >> 1;
//         build(v, i * 2 + 1, l, m);
//         build(v, i * 2 + 2, m + 1, r);
//         tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
//     }

//     template<typename T>
//     void build(const vector<T> &v) {
//         n = v.size();
//         tree.resize(1 << (__lg(n - 1) + 2));
//         build(v, 0, 0, n - 1);
//     }

//     item ask(int l, int r, int i, int vl, int vr) {
//         if (vl != vr) {
//             tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
//         }
//         if (l == vl && r == vr) {
//             return tree[i];
//         }
//         int m = (vl + vr) >> 1;
//         if (r <= m) {
//             return ask(l, r, i * 2 + 1, vl, m);
//         } else if (m < l) {
//             return ask(l, r, i * 2 + 2, m + 1, vr);
//         } else {
//             return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
//         }
//     }

//     item ask(int l, int r) {
//         l = max(l, 0); r = min(r, n - 1);
//         if (l > r) return item();
//         return ask(l, r, 0, 0, n - 1);
//     }

//     template<typename T>
//     void set(int ind, const T &t) {
//         static array<pair<int, int>, 30> st;
//         int l = 0, r = n - 1, i = 0;
//         int ptr = -1;
//         while (l != r) {
//             if (l != r) {
//                 tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
//             }
//             st[++ptr] = {l, r};
//             int m = (l + r) >> 1;
//             if (ind <= m) {
//                 i = i * 2 + 1;
//                 r = m;
//             } else {
//                 i = i * 2 + 2;
//                 l = m + 1;
//             }
//         }
//         tree[i].init(t, l, r);
//         while (i != 0) {
//             i = (i - 1) / 2;
//             tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
//             --ptr;
//         }
//     }

//     template<typename Modifier>
//     void modify(int l, int r, const Modifier &modifier, int i, int vl, int vr) {
//         if (vl != vr) {
//             tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
//         }
//         if (l == vl && r == vr) {
//             tree[i].modify(modifier, vl, vr);
//             return;
//         }
//         int m = (vl + vr) >> 1;
//         if (r <= m) {
//             modify(l, r, modifier, i * 2 + 1, vl, m);
//         } else if (m < l) {
//             modify(l, r, modifier, i * 2 + 2, m + 1, vr);
//         } else {
//             modify(l, m, modifier, i * 2 + 1, vl, m);
//             modify(m + 1, r, modifier, i * 2 + 2, m + 1, vr);
//         }
//         tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
//     }

//     template<typename Modifier>
//     void modify(int l, int r, const Modifier &modifier) {
//         l = max(l, 0); r = min(r, n - 1);
//         if (l > r) return;
//         modify(l, r, modifier, 0, 0, n - 1);
//     }
// };

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] ^= k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res ^= tree[r];
        return res;
    }

    T ask(int l, int r) {
        assert(l == r);
        return ask(r);
        // if (l > r) return 0;
        // return ask(r) ^ ask(l - 1);
    }

    void modify(int l, int r, int v) {
        r = min(r, n - 1);
        if (l > r) return;
        add(l, v);
        if (r + 1 < n)
            add(r + 1, v);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    cin >> c;
    vector<int> has(m + 1, 0);
    for (int k : c)
        has[k] ^= 1;

    int q;
    cin >> q;
    vector<pair<int, int>> que(q);
    cin >> que;
    vector<int> ans(q, 0);
    vector<vector<pair<int, int>>> here(m + 1);
    for (int i = 0; i < q; ++i) {
        auto [l, r] = que[i];
        here[l].eb(l - 1, i);
        if (r != m) {
            here[r + 1].eb(l - 1, i);
        }
    }

    show(que);
    show(here);

    show(has);

    const int B = 11;
    const int BN = 18;
    // const int BN = 4;

    double t1 = 0;
    double t2 = 0;

    vector<fenwick<int>> trees(BN);
    for (int i = B; i < BN; ++i)
        trees[i] = fenwick<int>(m + 5);

    vector<int> cnt(1 << B, 0);
    for (int i = m; i >= 1; --i) {
        int x = i - 1;
        if (has[i]) {
            cnt[x & ((1 << B) - 1)] ^= 1;

            auto s = clock();

            for (int i = B; i < BN; ++i) {
                for (int y = 0; y <= x; y += (1 << B)) {
                    int sh = x - y;
                    int sh2 = x - (y + (1 << B) - 1);
                    sh2 = max(sh2, 0);
                    if ((y >> i) & 1) {
                        trees[i].modify(sh2, sh, 1);
                    }
                }
            }
            t1 += (double)(clock() - s) / CLOCKS_PER_SEC;
        }
        debug {
            for (int i = B; i < BN; ++i) {
                show(i);
                for (int k = 0; k < trees[i].n; ++k)
                    cerr << trees[i].ask(k, k) << ' ';
                cerr << endl;
            }
        }
        show(i, cnt);
        for (auto [shift, ind] : here[i]) {
            auto s = clock();
            for (int j = 0; j < cnt.size(); ++j) {
                if (cnt[j])
                    ans[ind] ^= ((j - shift + (1 << B)) & ((1 << B) - 1));
            }
            t2 += (double)(clock() - s) / CLOCKS_PER_SEC;
            for (int i = B; i < BN; ++i) {
                ans[ind] ^= (trees[i].ask(shift, shift) << i);
            }
        }
    }

    show(ans);

    for (int i = 0; i < q; ++i) {
        if (ans[i]) cout << 'A';
        else cout << 'B';
    }
    cout << '\n';

    cerr << t1 << ' ' << t2 << endl;

    return 0;
}