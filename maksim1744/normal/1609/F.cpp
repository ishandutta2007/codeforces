/*
    author:  Maksim1744
    created: 28.11.2021 18:10:29
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

const int N = 1e6 + 20;

template<typename T>
struct fenwick {
    #ifdef HOME
    vector<T> tree;
    #else
    array<T, N / 2> tree;
    #endif
    int n;

    fenwick() {}

    void reset(int n = 0) {
        this->n = n;
        #ifdef HOME
        tree.resize(n);
        #endif
        for (int i = 0; i < n; ++i)
            tree[i] = 0;
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }
};

array<fenwick<int>, 60> trees;
#define popc __builtin_popcountll

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

array<pair<pair<ll, int>, int>, N> mins;
array<pair<pair<ll, int>, int>, N> maxs;
array<int, N> ppc;

mt19937_64 rng(38297392);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    // n = 1e6;
    for (int i = 0; i < trees.size(); ++i) {
        trees[i].reset((n + 5) / 2);
    }

    vector<pair<ll, int>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        // b[i].first = rnd(1e18);
        b[i].second = i;
        ppc[i] = popc(b[i].first);
    }

    ll ans = 0;

    auto calc = y_combinator([&](auto calc, int l, int r) -> void {
        if (l > r) return;
        if (l == r) {
            ++ans;
            return;
        }

        int m = (l + r) / 2;
        {
            mins[m] = {b[m], ppc[m]};
            for (int i = m - 1; i >= l; --i) {
                if (b[i] < mins[i + 1].first) {
                    mins[i] = {b[i], ppc[i]};
                } else {
                    mins[i] = mins[i + 1];
                }
            }
            maxs[m] = {b[m], ppc[m]};
            for (int i = m - 1; i >= l; --i) {
                if (b[i] > maxs[i + 1].first) {
                    maxs[i] = {b[i], ppc[i]};
                } else {
                    maxs[i] = maxs[i + 1];
                }
            }
        }
        {
            mins[m + 1] = {b[m + 1], ppc[m + 1]};
            for (int i = m + 2; i <= r; ++i) {
                if (b[i] < mins[i - 1].first) {
                    mins[i] = {b[i], ppc[i]};
                } else {
                    mins[i] = mins[i - 1];
                }
            }
            maxs[m + 1] = {b[m + 1], ppc[m + 1]};
            for (int i = m + 2; i <= r; ++i) {
                if (b[i] > maxs[i - 1].first) {
                    maxs[i] = {b[i], ppc[i]};
                } else {
                    maxs[i] = maxs[i - 1];
                }
            }
        }

        show(l, r, m);

        // max on the right, min on the left
        {
            for (int i = l; i <= m; ++i)
                trees[mins[i].second].add(i - l, 1);

            int L = m, R = m;
            for (int i = m + 1; i <= r; ++i) {
                while (L - 1 >= l && maxs[L - 1].first < maxs[i].first)
                    --L;
                while (L <= R && mins[R].first > mins[i].first)
                    --R;
                if (L > R) continue;
                int bits = maxs[i].second;
                show(i, L, R, bits);
                ans += trees[bits].ask(L - l, R - l);
            }

            for (int i = l; i <= m; ++i)
                trees[mins[i].second].add(i - l, -1);
        }
        show(ans);
        // min on the right, max on the left
        {
            for (int i = l; i <= m; ++i)
                trees[maxs[i].second].add(i - l, 1);

            int L = m, R = m;
            for (int i = m + 1; i <= r; ++i) {
                while (L - 1 >= l && mins[L - 1].first > mins[i].first)
                    --L;
                while (L <= R && maxs[R].first < maxs[i].first)
                    --R;
                show(i, L, R);
                if (L > R) continue;
                int bits = mins[i].second;
                ans += trees[bits].ask(L - l, R - l);
            }

            for (int i = l; i <= m; ++i)
                trees[maxs[i].second].add(i - l, -1);
        }
        show(ans);
        // both on the right
        {
            int L = m;
            for (int i = m + 1; i <= r; ++i) {
                while (L >= l && mins[L].first > mins[i].first && maxs[L].first < maxs[i].first)
                    --L;
                if (maxs[i].second == mins[i].second)
                    ans += m - L;
            }
        }
        show(ans);
        // both on the left
        {
            int R = m + 1;
            for (int i = m; i >= l; --i) {
                while (R <= r && mins[R].first > mins[i].first && maxs[R].first < maxs[i].first)
                    ++R;
                if (maxs[i].second == mins[i].second)
                    ans += R - m - 1;
            }
        }
        show(ans);
        calc(l, m);
        calc(m + 1, r);
    });

    calc(0, n - 1);
    cout << ans << '\n';

    return 0;
}