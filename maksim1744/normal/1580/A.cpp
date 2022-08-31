/*
    author:  Maksim1744
    created: 30.09.2021 13:18:41
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i].pb(s[j] == '1');
        }
    }
    int ans = 1e9;

    vector<vector<int>> p(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i) p[i][j] += p[i - 1][j];
            if (j) p[i][j] += p[i][j - 1];
            if (i && j) p[i][j] -= p[i - 1][j - 1];
            p[i][j] += v[i][j];
        }
    }

    auto ones = [&](int i1, int i2, int j1, int j2) {
        int res = p[i2][j2];
        if (i1) res -= p[i1 - 1][j2];
        if (j1) res -= p[i2][j1 - 1];
        if (i1 && j1) res += p[i1 - 1][j1 - 1];
        return res;
    };
    auto zeros = [&](int i1, int i2, int j1, int j2) {
        int ar = (i2 - i1 + 1) * (j2 - j1 + 1);
        return ar - ones(i1, i2, j1, j2);
    };

    for (int c1 = 0; c1 < m; ++c1) {
        for (int c2 = c1 + 3; c2 < m; ++c2) {
            int curmn = 1e9;
            for (int i = 0; i < n; ++i) {
                if (i - 4 >= 0) {
                    curmn = min(curmn, ones(i - 3, i - 1, c1 + 1, c2 - 1) +
                                       zeros(i - 3, i - 1, c1, c1) +
                                       zeros(i - 3, i - 1, c2, c2) +
                                       zeros(i - 4, i - 4, c1 + 1, c2 - 1));
                }
                ans = min(ans, curmn + zeros(i, i, c1 + 1, c2 - 1));
                if (curmn == 4) {
                    show(c1, c2, i);
                }
                curmn += ones(i, i, c1 + 1, c2 - 1);
                curmn += (v[i][c1] == 0);
                curmn += (v[i][c2] == 0);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}