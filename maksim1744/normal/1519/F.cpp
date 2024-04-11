/*
    author:  Maksim1744
    created: 11.05.2021 20:03:41
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

// const int N = 100;
const int N = 1 << 11;

mt19937_64 rng(1328759);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

struct B {
    array<uint64_t, N / 64> a;
 
    B(int e = 0) {a.fill(0);}
 
    int operator[](int i) {
        return (a[i >> 6] >> (i & 63)) & 1;
    }
 
    void operator |= (const B &other) {
        for (int i = 0; i < a.size(); ++i)
            a[i] |= other.a[i];
    }
    B operator & (const B &other) const {
        B res;
        for (int i = 0; i < a.size(); ++i)
            res.a[i] = (a[i] & other.a[i]);
        return res;
    }
    B operator | (const B &other) const {
        B res;
        for (int i = 0; i < a.size(); ++i)
            res.a[i] = (a[i] | other.a[i]);
        return res;
    }

    void set(int i) {
        a[i >> 6] |= (uint64_t(1) << (i & 63));
    }
 
    bool operator == (const B &other) const {
        return a == other.a;
    }
    bool operator != (const B &other) const {
        return a != other.a;
    }

    int count() const {
        int res = 0;
        for (auto x : a)
            res += __builtin_popcountll(x);
        return res;
    }
};
ostream &operator << (ostream &o, const B &b) {
    vector<uint64_t> v(b.a.begin(), b.a.end());
    return o << v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    cin >> a >> b;

    vector<int> c(n * m);
    cin >> c;

    vector<vector<int>> sets;

    for (int i = 0; i < (1 << n); ++i) {
        int s1 = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1)
                s1 += a[j];
        }
        for (int j = 0; j < (1 << m); ++j) {
            int s2 = 0;
            for (int k = 0; k < m; ++k) {
                if ((j >> k) & 1)
                    s2 += b[k];
            }
            if (s1 > s2) {
                vector<int> cur;
                for (int k = 0; k < n; ++k) {
                    if ((i >> k) & 1) {
                        for (int u = 0; u < m; ++u) {
                            if (((j >> u) & 1) == 0) {
                                cur.pb(k * m + u);
                            }
                        }
                    }
                }
                if (cur.empty()) {
                    cout << -1 << '\n';
                    return 0;
                }
                sets.pb(cur);
            }
        }
    }

    show(sets.size());

    vector<B> covers(n * m, 0);
    for (int i = 0; i < sets.size(); ++i) {
        for (int k : sets[i])
            covers[k].set(i);
    }

    for (int i = 0; i < covers.size(); ++i) {
        int ind = rnd(i, covers.size() - 1);
        swap(c[i], c[ind]);
        swap(covers[i], covers[ind]);
    }

    int ans = 2e9;

    auto filter_useless = [&](vector<pair<int, B>> &v, int S = 3) {
        static vector<pair<int, B>> next;
        next = v;
        static vector<bool> useless;
        useless.assign(v.size(), false);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i].first >= ans) {
                useless[i] = true;
                continue;
            }
            for (int j = 0; j < S; ++j) {
                int ind = rnd(i);
                if ((v[ind].second & v[i].second) == v[i].second) {
                    useless[i] = true;
                    break;
                }
            }
        }
        v.clear();
        for (int i = 0; i < next.size(); ++i)
            if (!useless[i])
                v.pb(next[i]);
    };

    vector<pair<int, B>> cur1;

    auto calc = y_combinator([&](auto calc, const vector<int> &c, const vector<B> &covers, int ii) -> vector<pair<int, B>> {
        // if (c.size() == 18 && false) {
        //     vector<int> c1, c2;
        //     vector<B> covers1, covers2;
        //     for (int i = 0; i < c.size(); ++i) {
        //         if (i < 11) {
        //             c1.pb(c[i]);
        //             covers1.pb(covers[i]);
        //         } else {
        //             c2.pb(c[i]);
        //             covers2.pb(covers[i]);
        //         }
        //     }

        //     auto cur1 = calc(c1, covers1);
        //     auto cur2 = calc(c2, covers2);
        //     vector<pair<int, B>> cur;
        //     for (int i = 0; i < cur1.size(); ++i) {
        //         for (int j = 0; j < cur2.size(); ++j) {
        //             cur.eb(cur1[i].first + cur2[j].first, cur1[i].second | cur2[j].second);
        //         }
        //     }
        //     mclock;
        //     sort(cur.begin(), cur.end(), [&](const auto &a, const auto &b) {
        //         return a.first < b.first;
        //     });
        //     mclock;
        //     int mx = 0;
        //     for (auto& [a, b] : cur) {
        //         if (b.count() == sets.size()) {
        //             ans = min(ans, a);
        //         }
        //         mx = max(mx, (int)b.count());
        //     }
        //     show(mx, sets.size());
        //     filter_useless(cur);
        //     return cur;
        // }

        vector<pair<int, B>> cur;
        cur.eb(0, 0);
        for (int i = 0; i < c.size(); ++i) {
            show(i, cur.size());
            mclock;
            if (!covers[i].count()) continue;
            int s = cur.size();
            for (int j = 0; j < s; ++j) {
                auto b = cur[j].second | covers[i];
                if (b == cur[j].second) continue;
                if (cur[j].first + c[i] >= ans) continue;
                cur.eb(cur[j].first + c[i], b);
            }
            vector<pair<int, B>> next;
            // next.reserve(cur.size());
            // sort(next.begin(), next.end(), [&](const auto &a, const auto &b) {
            //     return mp(a.first, a.second.count()) < mp(b.first, b.second.count());
            // });
            next.resize(cur.size());
            merge(cur.begin(), cur.begin() + s, cur.begin() + s, cur.end(), next.begin(), [&](const auto &a, const auto &b) {
                return a.first < b.first;
                // return mp(a.first, a.second.count()) < mp(b.first, b.second.count());
            });

            swap(next, cur);

            // cur.clear();
            // for (int i = 0; i < next.size(); ++i) {
            //     if (!useless[i])
            //         cur.pb(next[i]);
            // }

            if (ii == 2) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        auto &[cc, bb] = cur[rnd(cur.size())];
                        auto &[c, b] = cur1[rnd(cur1.size())];
                        if ((b & bb).count() == sets.size()) {
                            ans = min(ans, c + cc);
                        }
                    }
                }
                // filter_useless(cur1);
            }

            int mx = 0;
            for (auto& [a, b] : cur) {
                if (b.count() == sets.size()) {
                    ans = min(ans, a);
                }
                mx = max(mx, (int)b.count());
            }
            show(i, mx, sets.size());
            filter_useless(cur);
        }
        return cur;
    });

    vector<int> c1, c2;
    vector<B> covers1, covers2;
    for (int i = 0; i < c.size(); ++i) {
        if (i < c.size() / 2) {
            c1.pb(c[i]);
            covers1.pb(covers[i]);
        } else {
            c2.pb(c[i]);
            covers2.pb(covers[i]);
        }
    }
    cur1 = calc(c1, covers1, 1);
    auto cur2 = calc(c2, covers2, 2);

    show(cur1.size(), cur2.size());

    const int S = 30;
    const int MS = (1ll << S) - 1;
    auto split_by_f = [&](const vector<pair<int, B>> &v) {
        map<int, vector<pair<int, B>>> res;
        for (auto& [c, b] : v) {
            int x = (b.a[0] & MS);
            res[x].eb(c, b);
        }
        return res;
    };

    auto res1 = split_by_f(cur1);
    mclock;
    // show(cur1);
    // show(res1);
    auto res2 = split_by_f(cur2);
    mclock;
    // debug {
    //     for (int i = 0; i < res1.size(); ++i) {
    //         if (res1[i].size())
    //             cerr << res1[i].size() << ' ';
    //     }
    //     cerr << endl;
    //     for (int i = 0; i < res2.size(); ++i) {
    //         if (res2[i].size())
    //             cerr << res2[i].size() << ' ';
    //     }
    //     cerr << endl;
    // }


    if (sets.size() < S) {
        for (int i = 0; i < cur1.size(); ++i) {
            for (int j = 0; j < cur2.size(); ++j) {
                if (cur1[i].first + cur2[j].first >= ans) break;
                if ((cur1[i].second | cur2[j].second).count() == sets.size()) {
                    ans = cur1[i].first + cur2[j].first;
                    break;
                }
            }
        }
    } else {
        // vector<int> nz1, nz2;
        // for (int i = 0; i < res1.size(); ++i) {
        //     if (!res1[i].empty())
        //         nz1.pb(i);
        // }
        // for (int i = 0; i < res2.size(); ++i) {
        //     if (!res2[i].empty())
        //         nz2.pb(i);
        // }
        for (auto &[i, r1] : res1) {
            for (auto &[j, r2] : res2) {
                if ((i | j) != MS) continue;
                for (auto &[c1, b1] : r1) {
                    // if ((clock() - start_time) * 1.0 / CLOCKS_PER_SEC > 2.8) {
                    //     cout << ans << endl;
                    //     return 0;
                    // }
                    for (auto &[c2, b2] : r2) {
                        if (c1 + c2 >= ans) break;
                        if ((b1 | b2).count() == sets.size()) {
                            ans = c1 + c2;
                            break;
                        }
                    }
                }
            }
        }
    }

    mclock;

    cout << ans << '\n';

    return 0;
}