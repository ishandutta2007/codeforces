/*
    author:  Maksim1744
    created: 26.07.2021 20:36:59
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
#include "/home/maksim/cpplibs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct item {
    int mx = -1e9;

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
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};

void test_case(int test) {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<pair<ll, ll>> bord(n);
    pair<ll, ll> cur = {1, 0};
    for (int i = 0; i < n; ++i) {
        if (cur.first == 1) {
            bord[i] = {1 - cur.second, a[i] - 1 - cur.second};
        } else {
            bord[i] = {cur.second - a[i] + 1, cur.second - 1};
        }
        cur.first = -cur.first;
        cur.second = a[i] - cur.second;
    }

    vector<vector<pair<ll, ll>>> sparse(20, vector<pair<ll, ll>>(n, {-1e18, 1e18}));
    sparse[0] = bord;
    for (int i = 1; i < sparse.size(); ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            auto p1 = sparse[i - 1][j];
            auto p2 = sparse[i - 1][j + (1 << (i - 1))];
            sparse[i][j] = {max(p1.first, p2.first), min(p1.second, p2.second)};
        }
    }
    vector<ll> p2(n + 1, 0);
    for (int i = 2; i <= n; ++i)
        p2[i] = p2[i / 2] + 1;

    auto get_bord = [&](int l, int r) {
        if (l > r) return mp((ll)-1e18, (ll)1e18);
        int p = p2[r - l + 1];
        auto p1 = sparse[p][l];
        auto p2 = sparse[p][r - (1 << p) + 1];
        return mp(max(p1.first, p2.first), min(p1.second, p2.second));
    };

    vector<int> tol(n), tor(n);
    iota(tol.begin(), tol.end(), 0);

    for (int i = 0; i < n; ++i) {
        if (i) tol[i] = tol[i - 1];
        while (tol[i] < i) {
            auto p = get_bord(tol[i], i);
            if (p.first <= p.second) break;
            ++tol[i];
        }
    }

    vector<int> prevsame(n, -1);
    {
        map<int, int> last;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 1) continue;
            ll m = (bord[i].first + bord[i].second) / 2;
            if (last.count(m)) {
                prevsame[i] = last[m];
            }
            last[m] = i;
        }
    }

    vector<int> bestback(n, -1e9);
    vector<int> ans(n, -1e9);
    set<pair<int, int>> backset_ans;
    set<pair<ll, int>> backset_death;
    
    segtree tree(n + 1);
    tree.set(0, 0);

    for (int i = 0; i < n; ++i) {
        {
            int best = -1e9;

            best = tree.ask(tol[i], i).mx - 1;

            ans[i] = max(ans[i], best);
        }

        if (a[i] % 2 == 0) {
            int best = -1e9;
            if (prevsame[i] != -1) {
                auto [l, r] = get_bord(prevsame[i], i);
                ll m = (bord[i].first + bord[i].second) / 2;
                if (l <= m && m <= r) {
                    best = max(best, bestback[prevsame[i]] + 1);
                }
            }

            int from;
            {
                ll mid = (bord[i].first + bord[i].second) / 2;
                int L = -1, R = i + 1;
                while (R - L > 1) {
                    int C = (L + R) / 2;
                    auto [l, r] = get_bord(C, i);
                    if (l <= mid && mid <= r) {
                        R = C;
                    } else {
                        L = C;
                    }
                }
                from = R;
            }
            best = max(best, tree.ask(max(prevsame[i] + 1, from), i).mx + 1);

            bestback[i] = best;
            backset_ans.emplace(bestback[i], i);
            backset_death.emplace((bord[i].first + bord[i].second) / 2, i);
            best -= 1;
            ans[i] = max(ans[i], best);
        }

        {
            int best = -1e9;

            auto check = [&](int j) {
                auto [L, R] = get_bord(j, i);
                ll mid = (bord[j].first + bord[j].second) / 2;
                return L <= mid && mid <= R;
            };

            while (!backset_death.empty() && !check(backset_death.begin()->second)) {
                int ind = backset_death.begin()->second;
                backset_ans.erase({bestback[ind], ind});
                backset_death.erase(backset_death.begin());
            }
            while (!backset_death.empty() && !check(backset_death.rbegin()->second)) {
                int ind = backset_death.rbegin()->second;
                backset_ans.erase({bestback[ind], ind});
                backset_death.erase(*backset_death.rbegin());
            }

            if (!backset_ans.empty()) {
                best = max(best, backset_ans.rbegin()->first);
            }

            best -= 1;
            ans[i] = max(ans[i], best);
        }

        tree.set(i + 1, ans[i]);
    }
    cout << n - ans.back() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}