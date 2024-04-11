/*
    author:  Maksim1744
    created: 25.05.2021 21:57:04
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")

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

namespace fwht {

// H is initial matrix, G is inverse, div if 1/det(H)^2
// string c1c2c3c4 in comment means that f(0, 0) = c1, f(0, 1) = c2, f(1, 0) = c3, f(1, 1) = c4
// max value sum(a) * sum(b) * div^log_2(len(a)), use int128 if necessary

struct fwhd_info {
    array<array<int, 2>, 2> H;
    array<array<int, 2>, 2> G;
    const int div;
};

// this amount of brackets is not a joke: https://stackoverflow.com/a/12844625
const fwhd_info F0110 = {{{{{ 1,  1}}, {{ 1, -1}}}}, {{{{ 1,  1}}, {{ 1, -1}}}}, 2};  // 0110, xor
const fwhd_info F1001 = {{{{{-1,  1}}, {{ 1,  1}}}}, {{{{-1,  1}}, {{ 1,  1}}}}, 2};  // 1001, !xor
const fwhd_info F0001 = {{{{{ 0,  1}}, {{ 1,  1}}}}, {{{{-1,  1}}, {{ 1,  0}}}}, 1};  // 0001, and
const fwhd_info F0111 = {{{{{ 1,  1}}, {{ 1,  0}}}}, {{{{ 0,  1}}, {{ 1, -1}}}}, 1};  // 0111, or

const auto [H, G, div] = F0111;

template<typename T>
void fwht(vector<T> &v, bool inv = false) {
    assert((v.size() & (v.size() - 1)) == 0);
    if (inv) {
        for (int step = 1; step < v.size(); step <<= 1) {
            for (int i = 0; i < v.size(); i += step * 2) {
                for (int j = 0; j < step; ++j) {
                    T a = v[i + j], b = v[i + j + step];
                    v[i + j] = b;
                    v[i + j + step] = a - b;
                }
            }
        }
    } else {
        for (int step = 1; step < v.size(); step <<= 1) {
            for (int i = 0; i < v.size(); i += step * 2) {
                for (int j = 0; j < step; ++j) {
                    T a = v[i + j], b = v[i + j + step];
                    v[i + j] = a + b;
                    v[i + j + step] = a;
                }
            }
        }
    }
}

template<typename T>
vector<T> fwht(vector<T> a, const vector<T> &b) {
    // fwht(a, false);
    // fwht(b, false);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= b[i];
    // fwht(a, true);
    return a;
}

};

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> partitions;
    {
        vector<vector<vector<vector<int>>>> partitions_dp(n + 1, vector<vector<vector<int>>>(n + 1));
        partitions_dp[0][0].push_back({});
        for (int n = 1; n < partitions_dp.size(); ++n) {
            for (int last = 1; last <= n; ++last) {
                for (int x = 0; x <= last; ++x) {
                    for (auto v : partitions_dp[n - last][x]) {
                        v.pb(last);
                        partitions_dp[n][last].pb(v);
                    }
                }
            }
        }
        for (auto &x : partitions_dp.back())
            for (auto v : x)
                partitions.pb(v);
    }

    vector<vector<int>> mt(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            mt[i][j] = (s[j] == '1');
        }
    }

    vector<ll> paths(1 << n);
    {
        vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = 1;
        }
        for (int msk = 1; msk + 1 < dp.size(); ++msk) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((msk >> j) & 1) continue;
                    if (mt[i][j] == 0) continue;
                    dp[msk | (1 << j)][j] += dp[msk][i];
                }
            }
        }
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                paths[i] += dp[i][j];
            }
        }
    }

    mclock;

    vector<vector<ll>> with_len(n + 1, vector<ll>(1 << n));
    vector<vector<ll>> with_lent(n + 1, vector<ll>(1 << n));
    for (int i = 0; i < paths.size(); ++i) {
        with_len[__builtin_popcount(i)][i] = paths[i];
    }
    mclock;
    for (int i = 0; i < n + 1; ++i) {
        with_lent[i] = with_len[i];
        fwht::fwht(with_lent[i], false);
    }
    mclock;

    map<vector<int>, ll> by_part;

    vector<map<int, int>> g(1);
    vector<vector<int>> who(1);
    for (auto v : partitions) {
        int x = 0;
        for (int k : v) {
            if (!g[x].count(k)) {
                g[x][k] = g.size();
                g.eb();
                who.eb();
            }
            x = g[x][k];
        }
        who[x] = v;
    }
    mclock;

    show(g.size());

    auto mult_by = [&](const vector<ll> &cur, int k) {
        return fwht::fwht(with_lent[k], cur);
    };

    vector<ll> cur(1 << n, 0); cur[0] = 1;
    fwht::fwht(cur, false);
    vector<ll> tmp;
    y_combinator([&](auto dfs, int v, const vector<ll> &cur) -> void {
        if (v != 0) {
            tmp = cur;
            for (int step = 1; step < tmp.size(); step <<= 1) {
                for (int i = 0; i < tmp.size(); i += step * 2) {
                    int j = step - 1;
                    ll a = tmp[i + j], b = tmp[i + j + step];
                    tmp[i + j] = b;
                    tmp[i + j + step] = a - b;
                }
            }
            by_part[who[v]] = tmp.back();
        }
        for (auto [k, to] : g[v]) {
            dfs(to, (v == 0 ? with_lent[k] : mult_by(cur, k)));
        }
    })(0, cur);
    mclock;

    vector<ll> ans(1 << (n - 1));
    for (int i = 0; i < ans.size(); ++i) {
        vector<int> x;
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (((i >> j) & 1) == 0) {
                x.pb(cur + 1);
                cur = 0;
            } else {
                ++cur;
            }
        }
        sort(x.begin(), x.end());
        ans[i] = by_part[x];
    }
    mclock;

    auto ch_bits = [&](vector<ll> &v) {
        vector<ll> u(v.size(), 0);
        for (int i = 0; i < v.size(); ++i) {
            u[i ^ (v.size() - 1)] = v[i];
        }
        swap(u, v);
    };

    ch_bits(ans);
    for (int b = 0; b < n - 1; ++b) {
        for (int i = 0; i < ans.size(); ++i) {
            if (((i >> b) & 1) == 0) {
                ans[i | (1 << b)] -= ans[i];
            }
        }
    }
    ch_bits(ans);
    mclock;

    stringstream ss;
    ss << ans << '\n';
    cout << ss.str();

    return 0;
}