/*
    author:  Maksim1744
    created: 13.02.2020 18:26:10
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
const int N = 20;
const int LG = 5;
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
const int N = 505;
const int LG = 11;
#endif

array<array<array<array<int, LG>, LG>, N>, N> sparse;

mt19937_64 rng(9384729);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<string> v(n);
    cin >> v;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 1));
    auto col = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 'X';
        return v[i][j];
    };
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            while (true) {
                bool ok = true;
                for (int k = 0; k < f[i][j]; ++k) {
                    if (col(i - f[i][j], j - 1 - k) != 'R') { ok = false; break; }
                    if (col(i - 1 - k, j - f[i][j]) != 'R') { ok = false; break; }

                    if (col(i - f[i][j], j + k) != 'G') { ok = false; break; }
                    if (col(i - 1 - k, j - 1 + f[i][j]) != 'G') { ok = false; break; }

                    if (col(i - 1 + f[i][j], j - 1 - k) != 'Y') { ok = false; break; }
                    if (col(i + k, j - f[i][j]) != 'Y') { ok = false; break; }

                    if (col(i - 1 + f[i][j], j + k) != 'B') { ok = false; break; }
                    if (col(i + k, j - 1 + f[i][j]) != 'B') { ok = false; break; }
                }
                if (!ok)
                    break;
                ++f[i][j];
            }
            --f[i][j];
        }
    }

    // for (int i = 0; i < n + 1; ++i) {
    //     for (int j = 0; j < m + 1; ++j) {
    //         f[i][j] = rnd(100);
    //     }
    // }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < LG; ++k) {
                for (int u = 0; u < LG; ++u) {
                    sparse[i][j][k][u] = 0;
                    if (k != 0) {
                        sparse[i][j][k][u] = sparse[i][j][k - 1][u];
                        if (i >= (1 << (k - 1)))
                            sparse[i][j][k][u] = max(sparse[i][j][k - 1][u], sparse[i - (1 << (k - 1))][j][k - 1][u]);
                    } else if (u != 0) {
                        sparse[i][j][k][u] = sparse[i][j][k][u - 1];
                        if (j >= (1 << (u - 1)))
                            sparse[i][j][k][u] = max(sparse[i][j][k][u - 1], sparse[i][j - (1 << (u - 1))][k][u - 1]);
                    } else {
                        sparse[i][j][k][u] = f[i][j];
                    }
                }
            }
        }
    }

    auto mx = [&](int i1, int j1, int i2, int j2) {
        if (i1 > i2 || j1 > j2)
            return 0;
        int pi = 0;
        int pj = 0;
        while ((1 << pi) <= (i2 - i1 + 1))
            ++pi;
        while ((1 << pj) <= (j2 - j1 + 1))
            ++pj;
        --pi; --pj;
        return max({
            sparse[i2][j2][pi][pj],
            sparse[i1 + (1 << pi) - 1][j2][pi][pj],
            sparse[i2][j1 + (1 << pj) - 1][pi][pj],
            sparse[i1 + (1 << pi) - 1][j1 + (1 << pj) - 1][pi][pj]
        });
    };

    // for (int i = 0; i < 1000; ++i) {
    //     int i1 = rnd(n + 1), i2 = rnd(n + 1), j1 = rnd(m + 1), j2 = rnd(m + 1);
    //     if (i1 > i2)
    //         swap(i1, i2);
    //     if (j1 > j2)
    //         swap(j1, j2);
    //     int m1 = -1;
    //     for (int x = i1; x <= i2; ++x)
    //         for (int y = j1; y <= j2; ++y)
    //             m1 = max(m1, f[x][y]);

    //     int m2 = mx(i1, j1, i2, j2);
    //     if (m1 != m2) {
    //         show(i);
    //         printMatrix(f);
    //         show(i1, j1, i2, j2);
    //         show(m1, m2);
    //         break;
    //     }
    // }
    // return 0;


    for (int i = 0; i < q; ++i) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        --i1; --i2; --j1; --j2;
        ++i2; ++j2;
        show(i1,j1,i2,j2);
        int l = 0, r = N;
        while (r - l > 1) {
            int c = (l + r) / 2;
            int m = mx(i1 + c, j1 + c, i2 - c, j2 - c);
            show(i1+c, j1+c, i2-c, j2-c, m, c);
            if (m >= c)
                l = c;
            else
                r = c;
        }
        cout << l * l * 4 << '\n';
    }

    return 0;
}