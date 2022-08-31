/*
    author:  Maksim1744
    created: 30.01.2021 23:12:44
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    cin >> v;
    int maxv = mine(v[0]);
    int ans = 1e9;
    vector<pair<string, pair<int, int>>> best;
    for (int v0 = 0; v0 <= maxv; ++v0) {
        vector<pair<string, pair<int, int>>> curpath;
        int cur = 0;
        auto u = v;
        bool ok = true;
        curpath.eb("row", mp(1, v0));
        cur += abs(v0);
        for (int i = 0; i < m; ++i) {
            u[0][i] -= v0;
        }
        for (int i = 0; i < m; ++i) {
            int k = u[0][i];
            if (k < 0) ok = false;
            curpath.eb("col", mp(i + 1, k));
            cur += abs(k);
            for (int j = 0; j < n; ++j) {
                u[j][i] -= k;
            }
        }
        if (v0 == 2) {
            printMatrix(u);
            show(curpath);
        }
        for (int i = 1; i < n; ++i) {
            int k = u[i][0];
            if (k < 0) ok = false;
            curpath.eb("row", mp(i + 1, k));
            cur += abs(k);
            for (int j = 0; j < m; ++j)
                u[i][j] -= k;
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (u[i][j] != 0)
                    ok = false;
        if (ok && ans > cur) {
            ans = min(ans, cur);
            best = curpath;
        }
    }

    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
    for (auto [s, uv] : best) {
        for (int i = 0; i < uv.second; ++i) {
            cout << s << ' ' << uv.first << '\n';
        }
    }

    return 0;
}