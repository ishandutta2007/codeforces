/*
    author:  Maksim1744
    created: 12.08.2020 18:28:06
*/

#include <bits/stdc++.h>

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

const int N = 100;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    // vector<vector<int>> gi(n);
    vector<map<pair<int, int>, int>> vars(n);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].eb(w, b);
        // if (b == 4) show(a, w);
        // gi[b].pb(a);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            vars[g[i][j].second][{g[i].size(), j + 1}]++;
        }
    }
    // show(vars[4]);
    vector<vector<bitset<N>>> bad(k + 1, vector<bitset<N>>(k + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (auto it1 = vars[i].begin(); it1 != vars[i].end(); ++it1) {
            auto [p1, c1] = *it1;
            auto it2 = it1;
            for (; it2 != vars[i].end(); ++it2) {
                auto [p2, c2] = *it2;
                if (p1 != p2 || c1 > 1) {
                    bad[p1.first][p1.second][p2.first * 10 + p2.second] = 1;
                }
            }
        }
        // for (int j = 0; j < vars[i].size(); ++j) {
        //     for (int k = 0; k < vars[i].size(); ++k) {
        //         if (k != j)
        //             bad[vars[i][j].first][vars[i][j].second].insert(vars[i][k]);
        //     }
        // }
    }
    // show(bad);
    int ans = 0;
    for (int i = 1; i <= k; ++i)
        show(i, bad[i]);
    vector<int> tmp;
    function<void(int, bitset<N>)> calc = [&](int from, bitset<N> bd) {
        if (from == k + 1) {
            show(tmp);
             ++ans;
             return;
        }
        for (int nxt = 1; nxt <= from; ++nxt) {
            if (!bd[from * 10 + nxt] && !bad[from][nxt][from * 10 + nxt]) {
                auto bbd = bd;
                bbd |= bad[from][nxt];
                tmp.pb(nxt);
                calc(from + 1, bbd);
                tmp.pop_back();
            }
        }
    };
    calc(1, 0);
    cout << ans << '\n';

    return 0;
}