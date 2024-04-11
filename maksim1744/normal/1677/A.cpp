/*
    author:  Maksim1744
    created: 08.05.2022 17:35:52
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    --p;
    vector<vector<int>> pref(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        pref[i][p[i]] = 1;
    }
    show(pref);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i) pref[i][j] += pref[i - 1][j];
            if (j) pref[i][j] += pref[i][j - 1];
            if (i && j) pref[i][j] -= pref[i - 1][j - 1];
        }
    }
    show(pref);
    auto getss = [&](int i1, int j1, int i2, int j2) {
        if (i1 > j1 || i2 > j2) return 0;
        int ans = pref[j1][j2];
        if (i1) ans -= pref[i1 - 1][j2];
        if (i2) ans -= pref[j1][i2 - 1];
        if (i1 && i2) ans += pref[i1 - 1][i2 - 1];
        show(i1, j1, i2, j2, ans);
        return ans;
    };

    ll ans = 0;
    for (int b = 0; b < n; ++b) {
        for (int c = b + 1; c < n; ++c) {
            int cur = getss(0, b - 1, 0, p[c] - 1) * getss(c + 1, n - 1, 0, p[b] - 1);
            ans += cur;
        }
    }
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