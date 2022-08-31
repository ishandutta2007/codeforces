/*
    author:  Maksim1744
    created: 08.03.2022 17:59:07
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
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

array<array<ll, 101>, 100001> dp;
array<array<int, 101>, 100001> fr;

const ll inf = 1e18;

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<vector<pair<pair<int, int>, int>>> v(n);
    vector<int> lens;
    for (int i = 0; i < m; ++i) {
        int e, t, p;
        cin >> e >> t >> p;
        --e;
        v[e].eb(mp(t, p), i);
        lens.pb(t);
    }

    show(v);

    vector<int> ans;
    ll T = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= v[i].size(); ++j) {
            for (int u = 0; u <= 100; ++u) {
                dp[j][u] = inf;
                fr[j][u] = -1;
            }
        }
        dp[0][0] = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            auto [t, p] = v[i][j].first;
            dp[j + 1] = dp[j];
            for (int x = 0; x <= 100; ++x) {
                int to = min(100, x + p);
                if (dp[j + 1][to] > dp[j][x] + t) {
                    dp[j + 1][to] = dp[j][x] + t;
                    fr[j + 1][to] = x;
                }
            }
        }
        if (dp[v[i].size()][100] == inf) {
            cout << -1 << '\n';
            return;
        }
        vector<int> inds;
        int x = v[i].size(), y = 100;
        for (int u = 0; u < v[i].size(); ++u) {
            if (fr[x][y] == -1) {
                --x;
            } else {
                y = fr[x][y];
                --x;
                inds.pb(v[i][x].second);
            }
        }
        for (int u : inds) {
            ans.pb(u);
            T += lens[u];
        }
        if (T > a[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    ++ans;
    cout << ans.size() << '\n';
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