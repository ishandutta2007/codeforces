#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

/*
    author:  Maksim1744
    created: 23.04.2020 18:39:01
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
const int N = 32;
const int M = N / 2;
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
const int N = 2048;
const int M = N / 2;
#endif

const int inf = 1e9;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    cin >> d;
    int g, r;
    cin >> g >> r;
    sort(d.begin(), d.end());
    vector<vector<int>> gr(m);
    for (int i = 0; i < m; ++i) {
        gr[i].reserve(g + 5);
    }
    auto calc = [&](int i) {
        bitset<N> mask = 0;
        int ind = i;
        while (ind >= 0) {
            if (d[i] - d[ind] <= g)
                mask[M - (d[i] - d[ind])] = 1;
            else
                break;
            --ind;
        }
        ind = i;
        while (ind < m) {
            if (d[ind] - d[i] <= g)
                mask[M + (d[ind] - d[i])] = 1;
            else
                break;
            ++ind;
        }
        bitset<N> gol = 0, gor = 0;
        gol[M] = 1;
        gor[M] = 1;
        for (int i = 0; i < g; ++i) {
            gor <<= 1;
            gol >>= 1;
            gor |= (gol & mask);
            gol |= (gor & mask);
        }
        mask &= (gol | gor);
        ind = i + 1;
        while (ind < m) {
            if (d[ind] - d[i] <= g) {
                if ((mask[M + (d[ind] - d[i])]))
                    gr[i].pb(ind);
            } else {
                break;
            }
            ++ind;
        }
    };
    // show(gr);
    // vector<vector<bitset<N>>> dp(g + 1, vector<bitset<N>>(m, 0));
    // for (int i = 0; i < m; ++i) {
    //     dp[0][i][M] = 1;
    // }
    // for (int i = 0; i <= g; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (j != 0) {
    //             int dl = d[j] - d[j - 1];
    //             if (i >= dl) {
    //                 dp[i][j] |= dp[i - dl][j - 1] >> dl;
    //             }
    //         }
    //         if (j + 1 != m) {
    //             int dr = d[j + 1] - d[j];
    //             if (i >= dr) {
    //                 dp[i][j] |= dp[i - dr][j + 1] << dr;
    //             }
    //         }
    //     }
    //     // if (i >= 2) {
    //         // dp[i - 2].clear();
    //         // dp[i - 2].shrink_to_fit();
    //     // }
    // }
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j <= g; ++j) {
    //         for (int k = 0; k < N; ++k) {
    //             if (dp[i][j][k])
    //                 cout << i << ' ' << j << ' ' << k - M << endl;
    //         }
    //     }
    // }
    // for (int i = 0; i < m; ++i) {
    //     int j = i + 1;
    //     while (j < m && d[i] + g >= d[j]) {
    //         if (dp[g][i][M + d[j] - d[i]])
    //             gr[i].pb(j);
    //         ++j;
    //     }
    // }
    // show(gr);
    vector<int> dist(m, inf);
    dist[0] = 0;
    for (int i = 0; i < m; ++i) {
        if (dist[i] != inf) {
            calc(i);
            for (auto k : gr[i]) {
                dist[k] = min(dist[k], dist[i] + 1);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < m; ++i) {
        if (dist[i] == inf) continue;
        if (d[i] + g >= n) {
            if (ans == -1 || ans > dist[i] * (r + g) + (n - d[i]))
                ans = dist[i] * (r + g) + (n - d[i]);
        }
    }
    cout << ans << endl;

    return 0;
}