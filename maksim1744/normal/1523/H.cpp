/*
    author:  Maksim1744
    created: 03.06.2021 21:14:26
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
    int mx = 0;
    int ind = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        mx = t;
        ind = l;
    }

    void update(const item &first, const item &second, int l, int r) {
        mx = max(first.mx, second.mx);
        if (first.mx > second.mx)
            ind = first.ind;
        else
            ind = second.ind;
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
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};

const int B = 16;
const int K = 32;

const int N = 2e4 + 20;
array<array<array<pair<int, int>, N>, K>, B> dp;
array<array<array<int, N>, K>, B> longest;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    cin >> a;

    segtree tree(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + i;
    }
    tree.build(b);
    vector<pair<int, int>> next(n);
    next[n - 1] = {1e9, n};
    for (int i = 0; i + 1 < n; ++i) {
        auto it = tree.ask(i + 1, i + a[i]);
        next[i] = {it.mx, it.ind};
    }

    for (int i = 0; i < n; ++i) {
        dp[0][0][i] = next[i];
        longest[0][0][i] = a[i] + i;
        for (int k = 1; k < K; ++k) {
            dp[0][k][i] = dp[0][k - 1][i];
            if (a[i] + i + k < n)
                umax(dp[0][k][i], mp(a[a[i] + i + k] + a[i] + i + k, a[i] + i + k));
            longest[0][k][i] = longest[0][k - 1][i] + 1;
        }
    }

    for (int b = 1; b < B; ++b) {
        for (int k = 0; k < K; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[b][k][i] = dp[b - 1][k][i];
                longest[b][k][i] = longest[b - 1][k][i];
                if (dp[b - 1][k][i].second >= n) continue;
                for (int k1 = 0; k1 <= k; ++k1) {
                    int k2 = k - k1;
                    umax(dp[b][k][i], dp[b - 1][k2][dp[b - 1][k1][i].second]);
                    umax(longest[b][k][i], longest[b - 1][k2][dp[b - 1][k1][i].second]);
                }
            }
        }
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l; --r;
        if (l == r) {
            cout << 0 << '\n';
            continue;
        }
        if (r - l - 1 <= k) {
            cout << 1 << '\n';
            continue;
        }
        vector<pair<int, int>> cur(k + 1, mp(a[l] + l, l));
        vector<pair<int, int>> next(k + 1, mp(a[l] + l, l));
        int ans = 0;
        for (int b = B - 1; b >= 0; --b) {
            bool ok = true;
            next = cur;
            for (int k = 0; k < cur.size(); ++k) {
                for (int k1 = 0; k1 <= k; ++k1) {
                    int k2 = k - k1;
                    if (longest[b][k2][cur[k1].second] >= r) {
                        ok = false;
                        break;
                    }
                    umax(next[k], dp[b][k2][cur[k1].second]);
                }
                if (!ok) break;
            }
            if (!ok) continue;
            ans += (1 << b);
            swap(cur, next);
        }
        ++ans;
        cout << ans << '\n';
    }

    return 0;
}