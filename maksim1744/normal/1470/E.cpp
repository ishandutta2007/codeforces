/*
    author:  Maksim1744
    created: 05.01.2021 18:54:57
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

    int find_first_at_least(ll s, int i, int l, int r) {
        if (l == r) {
            assert(tree[i].sm >= s);
            return l;
        }
        int m = (l + r) / 2;
        if (tree[i * 2 + 1].sm >= s) return find_first_at_least(s, i * 2 + 1, l, m);
        else return find_first_at_least(s - tree[i * 2 + 1].sm, i * 2 + 2, m + 1, r);
    }

    int find_first_at_least(ll s) {
        return find_first_at_least(s, 0, 0, n - 1);
    }
};

void test_case(int test) {
    int n, c, q;
    cin >> n >> c >> q;
    vector<vector<ll>> C0(n + 1, vector<ll>(5, 0));
    for (int i = 0; i < C0.size(); ++i) {
        for (int j = 0; j < C0[i].size(); ++j) {
            if (j == 0) {
                C0[i][j] = 1;
                continue;
            }
            if (i == 0) {
                C0[i][j] = 0;
                continue;
            }
            C0[i][j] = C0[i - 1][j - 1] + C0[i - 1][j];
        }
    }

    auto C = [&](int n, int k) {
        if (k < 0 || k > n) return 0ll;
        return C0[n][k];
    };
    auto sumC = [&](int n, int k) {
        ll res = 0;
        for (int u = 0; u <= k; ++u)
            res += C(n, u);
        if (res == 0) res = 1;
        return res;
    };

    vector<int> p(n);
    cin >> p;
    vector<vector<pair<pair<int, int>, ll>>> before(c + 1), after(c + 1);
    vector<segtree> before_tree(c + 1), after_tree(c + 1);
    for (int k = 0; k <= c; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int ln = 1; ln <= k; ++ln) {
                if (i + ln >= n) break;
                // vector<int> a(p.begin() + i, p.begin() + i + ln);
                // vector<int> b(p.begin() + i, p.begin() + i + ln);
                // reverse(b.begin(), b.begin() + ln);
                ll cnt = sumC(n - 1 - (i + ln) - 1, k - ln);
                if (p[i] < p[i + ln]) {
                    after[k].eb(mp(i, ln), cnt);
                } else if (p[i] > p[i + ln]) {
                    before[k].eb(mp(i, ln), cnt);
                } else {
                    assert(false);
                }
            }
        }
        sort(before[k].begin(), before[k].end(), [&](const pair<pair<int, int>, ll> &a, const pair<pair<int, int>, ll> &b) {
            if (a.first.first != b.first.first) return a.first.first < b.first.first;
            return p[a.first.first + a.first.second] < p[b.first.first + b.first.second];
        });
        sort(after[k].begin(), after[k].end(), [&](const pair<pair<int, int>, ll> &a, const pair<pair<int, int>, ll> &b) {
            if (a.first.first != b.first.first) return a.first.first > b.first.first;
            return p[a.first.first + a.first.second] < p[b.first.first + b.first.second];
        });
        before_tree[k] = segtree(max(1, (int)before[k].size()));
        for (int i = 0; i < before[k].size(); ++i)
            before_tree[k].set(i, before[k][i].second);
        after_tree[k] = segtree(max(1, (int)after[k].size()));
        for (int i = 0; i < after[k].size(); ++i)
            after_tree[k].set(i, after[k][i].second);
    }


    ll total = before_tree[c].ask(0, (int)before[c].size() - 1).sm + after_tree[c].ask(0, (int)after[c].size() - 1).sm + 1;

    while (q--) {
        ll i;
        int j;
        cin >> j >> i;
        --j;
        // if (test == 1) continue;

        // if (i != 14 || j != 2) continue;

        // show(before[c]);
        // show(after[c]);

        if (i > total) {
            cout << -1 << '\n';
            continue;
        }

        int k = c;
        int from_before = 0;
        int to_after = (int)after[k].size() - 1;


        while (true) {
            ll bef = before_tree[k].ask(from_before, (int)before[k].size() - 1).sm;
            if (i == bef + 1 || k == 0) {
                cout << p[j] << '\n';
                break;
            } else if (i <= bef) {
                ll has = before_tree[k].ask(0, from_before - 1).sm;
                // show(has);
                // for (int i = 0; i < before[k].size(); ++i) {
                //     cout << before_tree[k].ask(i, i).sm << ' ';
                // }
                // cout << endl;
                // show(i + has);
                int ind = before_tree[k].find_first_at_least(i + has);
                // show(ind);
                auto [imod, lmod] = before[k][ind].first;
                if (imod > j) {
                    cout << p[j] << '\n';
                    break;
                }
                if (j <= imod + lmod) {
                    reverse(p.begin() + imod, p.begin() + imod + lmod + 1);
                    int ans = p[j];
                    reverse(p.begin() + imod, p.begin() + imod + lmod + 1);
                    cout << ans << '\n';
                    break;
                }
                i -= before_tree[k].ask(from_before, ind - 1).sm;
                int left = imod + lmod + 1;
                k -= lmod;
                int i1 = lowb(before[k], mp(mp(left, -1), -1ll));
                int i2 = lowb(after[k], mp(mp(left + 1, -1), -1ll)) - 1;
                from_before = i1;
                to_after = i2;
            } else {
                i -= bef + 1;
                int ind = after_tree[k].find_first_at_least(i);
                auto [imod, lmod] = after[k][ind].first;
                if (imod > j) {
                    cout << p[j] << '\n';
                    break;
                }
                if (j <= imod + lmod) {
                    reverse(p.begin() + imod, p.begin() + imod + lmod + 1);
                    int ans = p[j];
                    reverse(p.begin() + imod, p.begin() + imod + lmod + 1);
                    cout << ans << '\n';
                    break;
                }
                i -= after_tree[k].ask(0, ind - 1).sm;
                int left = imod + lmod + 1;
                k -= lmod;
                int i1 = lowb(before[k], mp(mp(left, -1), -1ll));
                int i2 = lowb(after[k], mp(mp(left + 1, -1), -1ll)) - 1;
                from_before = i1;
                to_after = i2;
            }
        }
        // cout << 0 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}