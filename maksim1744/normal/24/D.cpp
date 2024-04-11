/*
    author:  Maksim1744
    created: 18.08.2020 22:35:37
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

ld p13 = 1.0l / 3;
ld p14 = 1.0l / 4;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    if (m == 1) {
        cout << (n - x) * 2 << '\n';
        return 0;
    }
    vector<vector<ld>> e(n, vector<ld>(m, 0));
    for (int i = n - 2; i >= 0; --i) {
        ld b = -p13 * e[i + 1][0] - 1;
        ld c1 = -1.0l + p13;
        ld c2 = p13;
        vector<pair<pair<ld, ld>, ld>> koef(m);
        koef[0] = mp(mp(c1, c2), b);
        for (int j = 1; j < m - 1; ++j) {
            ld k = -p14 / c1;
            c1 *= k;
            c2 *= k;
            b *= k;
            ld c3 = 0;
            c1 += p14;
            c2 -= (1.0l - p14);
            c3 += p14;
            b += -p14 * e[i + 1][j] - 1;
            assert(abs(c1) < 1e-9);
            c1 = c2;
            c2 = c3;
            koef[j] = mp(mp(c1, c2), b);
            // show(koef[j]);
        }
        ld k = -p13 / c1;
        c1 *= k;
        c2 *= k;
        c1 += p13;
        assert(abs(c1) < 1e-9);
        b *= k;
        c2 -= (1.0l - p13);
        b += -p13 * e[i + 1][m - 1] - 1;
        // show(c1, c2, b);
        e[i][m - 1] = b / c2;
        for (int j = m - 2; j >= 0; --j) {
            e[i][j] = (koef[j].second - koef[j].first.second * e[i][j + 1]) / koef[j].first.first;
        }
        // for (int j = 0; j < m; ++j) {
        //     int neighs = 3;
        //     if (j == 0 || j + 1 == m) neighs = 2;
        //     ld sm = 0;
        //     sm += e[i + 1][j];
        //     if (j != 0) sm += e[i][j - 1];
        //     if (j + 1 != m) sm += e[i][j + 1];
        //     sm /= neighs;
        //     sm += 1;
        //     assert(abs(e[i][j] - sm) < 1e-9);
        // }
    }
    --x; --y;
    cout << fixed << setprecision(20) << e[x][y] << '\n';
    // printMatrix(e);

    return 0;
}