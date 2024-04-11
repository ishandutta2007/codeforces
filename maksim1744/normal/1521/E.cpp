/*
    author:  Maksim1744
    created: 07.05.2021 18:31:25
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int m, k;
    cin >> m >> k;
    vector<int> a0(k);
    cin >> a0;
    int mx = maxe(a0);
    vector<pair<int, int>> a;
    for (int i = 0; i < k; ++i) {
        if (a0[i]) {
            a.eb(a0[i], i + 1);
        }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    show(a);
    ll L = 0, R = 1e6;
    while (R - L > 1) {
        ll C = (L + R) / 2;
        ll sim = C * ((C + 1) / 2);
        ll al = C * C - (C / 2) * (C / 2);
        if (sim >= mx && al >= m)
            R = C;
        else
            L = C;
    }
    int n = R;
    while (true) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        vector<pair<int, int>> cells;
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                res[i][j] = 0;
                cells.eb(i, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j += 2) {
                if (res[i][j] == -1) {
                    res[i][j] = 0;
                    cells.eb(i, j);
                }
            }
        }
        for (int i = 0; i < n; i += 2) {
            for (int j = 1; j < n; j += 2) {
                res[i][j] = 0;
                cells.eb(i, j);
            }
        }
        int ind = 0;
        assert(cells.size() >= m);
        for (auto [cnt, e] : a) {
            for (int i = 0; i < cnt; ++i) {
                auto [x, y] = cells[ind];
                ++ind;
                res[x][y] = e;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (res[i][j] == -1)
                    res[i][j] = 0;
            }
        }
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (res[i][j] == res[i + 1][j + 1] && res[i][j] != 0) ok = false;
                if (res[i][j + 1] == res[i + 1][j] && res[i + 1][j] != 0) ok = false;
            }
        }
        if (!ok) {
            ++n;
            continue;
        }
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << res[i] << '\n';
        }
        break;
    }
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