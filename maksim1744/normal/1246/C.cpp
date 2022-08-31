/*
    author:  Maksim1744
    created: 05.11.2019 21:49:32
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
const int N = 5;
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
const int N = 2005;
#endif

const ll mod = 1e9 + 7;

array<string, N> field;
array<array<int, N>, N> can_from_left, can_from_up;
array<array<ll, N>, N> from_left, from_up;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
    }
    for (int i = 0; i < n; ++i) {
        int sm = 0;
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'R')
                ++sm;
        }
        int last = -1;
        for (int j = 0; j < m; ++j) {
            while (sm > m - j - 1) {
                if (last + 1 < m && field[i][last + 1] == 'R')
                    --sm;
                ++last;
            }
            can_from_left[i][j] = last;
        }
    }
    for (int j = 0; j < m; ++j) {
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            if (field[i][j] == 'R')
                ++sm;
        }
        int last = -1;
        for (int i = 0; i < n; ++i) {
            while (sm > n - i - 1) {
                if (last + 1 < n && field[last + 1][j] == 'R')
                    --sm;
                ++last;
            }
            can_from_up[i][j] = last;
        }
    }
    from_up[0][0] = 1;
    from_left[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                from_up[i][j] = 0;
            } else {
                from_up[i][j] = from_up[i - 1][j] + (i == 1 && j == 0 ? 0 : from_left[i - 1][j]);
                for (int k = can_from_up[i - 1][j]; k < can_from_up[i][j]; ++k) {
                    if (k >= 0) {
                        from_up[i][j] -= from_left[k][j];
                    }
                }
                from_up[i][j] = (from_up[i][j] % mod + mod) % mod;
            }
            if (j == 0) {
                from_left[i][j] = 0;
            } else {
                from_left[i][j] = from_left[i][j - 1] + (i == 0 && j == 1 ? 0 : from_up[i][j - 1]);
                for (int k = can_from_left[i][j - 1]; k < can_from_left[i][j]; ++k) {
                    if (k >= 0) {
                        from_left[i][j] -= from_up[i][k];
                    }
                }
                from_left[i][j] = (from_left[i][j] % mod + mod) % mod;
            }
        }
    }
    // debug {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = 0; j < N; ++j) {
    //             cout << can_from_up[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    // debug {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = 0; j < N; ++j) {
    //             cout << can_from_left[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    // debug {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = 0; j < N; ++j) {
    //             cout << from_up[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    // debug {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = 0; j < N; ++j) {
    //             cout << from_left[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    cout << (from_left[n - 1][m - 1] + from_up[n - 1][m - 1]) % mod << '\n';
    return 0;
}