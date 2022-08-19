/*
    author:  Maksim1744
    created: 12.12.2021 18:51:09
*/

#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
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

void test_case(int test) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<int> cur_cnt(n + 5, 0);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        g[p - 1].pb(i + 1);
    }
    vector<int> ans(q, -2);
    vector<vector<pair<pair<int, int>, int>>> que(n);
    for (int i = 0; i < q; ++i) {
        int v, l, k;
        cin >> v >> l >> k;
        --v;
        que[v].eb(mp(l, k), i);
    }

    ordered_set<pair<int, int>> st;

    fenwick<int> tree(n + 5);
    y_combinator([&](auto dfs, int v) -> void {
        {
            if (cur_cnt[a[v]] != 0) {
                tree.add(cur_cnt[a[v]], -1);
                st.erase({cur_cnt[a[v]], a[v]});
            }
            cur_cnt[a[v]]++;
            tree.add(cur_cnt[a[v]], +1);
            st.insert({cur_cnt[a[v]], a[v]});
        }

        for (auto [lk, i] : que[v]) {
            auto [l, k] = lk;
            int extra = tree.ask(l - 1);
            show(l, k, i, extra);
            k += extra;
            if (k > st.size()) {
                ans[i] = -1;
            } else {
                ans[i] = st.find_by_order(k - 1)->second;
            }
        }

        for (int k : g[v]) {
            dfs(k);
        }
        {
            tree.add(cur_cnt[a[v]], -1);
            st.erase({cur_cnt[a[v]], a[v]});
            cur_cnt[a[v]]--;
            if (cur_cnt[a[v]] != 0) {
                tree.add(cur_cnt[a[v]], +1);
                st.insert({cur_cnt[a[v]], a[v]});
            }
        }
    })(0);
    cout << ans << '\n';
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