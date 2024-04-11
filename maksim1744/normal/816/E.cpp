/*
    author:  Maksim1744
    created: 30.01.2021 23:49:32
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int b;
    cin >> b;
    vector<vector<ll>> dp_no_coupon(n);
    vector<vector<ll>> dp_coupon(n);
    vector<vector<int>> g(n);
    vector<ll> cost(n), discount(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i] >> discount[i];
        if (i != 0) {
            int p;
            cin >> p;
            --p;
            g[p].pb(i);
        }
    }

    show(g);

    function<void(int)> dfs = [&](int v) {
        dp_no_coupon[v].assign(1, 0);
        dp_coupon[v].assign(1, 0);
        for (auto k : g[v]) {
            dfs(k);
            vector<ll> no_coupon(dp_no_coupon[v].size() + dp_no_coupon[k].size() - 1, 2e9);
            vector<ll> coupon(dp_coupon[v].size() + dp_coupon[k].size() - 1, 2e9);
            show(dp_coupon[v], dp_coupon[k], coupon);
            for (int i = 0; i < dp_no_coupon[v].size(); ++i) {
                for (int j = 0; j < dp_no_coupon[k].size(); ++j) {
                    show(i, j);
                    no_coupon[i + j] = min(no_coupon[i + j], dp_no_coupon[v][i] + dp_no_coupon[k][j]);
                    coupon[i + j] = min(coupon[i + j], dp_coupon[v][i] + dp_coupon[k][j]);
                }
            }
            swap(dp_no_coupon[v], no_coupon);
            swap(dp_coupon[v], coupon);
            // cerr << "ok" << endl;
        }
        // cerr << "ok " << v << endl;
        dp_coupon[v].insert(dp_coupon[v].begin() + 1, cost[v] - discount[v]);
        for (int i = 2; i < dp_coupon[v].size(); ++i)
            dp_coupon[v][i] += cost[v] - discount[v];
        dp_no_coupon[v].pb(2e9);
        // cerr << "ok " << v << endl;
        for (int i = (int)dp_no_coupon[v].size() - 1; i >= 1; --i)
            dp_no_coupon[v][i] = min(dp_no_coupon[v][i], dp_no_coupon[v][i - 1] + cost[v]);
        // cerr << "ok " << v << endl;
        show(v, dp_coupon[v], dp_no_coupon[v]);
        for (int i = 0; i < dp_coupon[v].size(); ++i)
            dp_coupon[v][i] = min(dp_coupon[v][i], dp_no_coupon[v][i]);
        show(v, dp_coupon[v], dp_no_coupon[v]);
    };
    dfs(0);
    int ans = 0;
    for (int i = 0; i < dp_coupon[0].size(); ++i) {
        if (dp_coupon[0][i] <= b)
            ans = i;
    }
    cout << ans << '\n';

    return 0;
}