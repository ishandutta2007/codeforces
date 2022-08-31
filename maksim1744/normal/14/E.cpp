/*
    author:  Maksim1744
    created: 22.08.2020 20:32:52
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    int N = n + 5;
    ll dp[N][N][N][5][3];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                for (int o = 0; o < 5; ++o) {
                    for (int u = 0; u < 3; ++u) {
                        dp[i][j][k][o][u] = 0;
                    }
                }
            }
        }
    }
    for (int a = 1; a <= 4; ++a) {
        for (int b = 1; b <= 4; ++b) {
            int d = 0;
            if (a < b) d = 2;
            else if (a > b) d = 1;
            if (d != 0) dp[2][0][0][b][d]++;
        }
    }
    for (int k = 2; k + 1 < N; ++k) {
        for (int cup = 0; cup < N; ++cup) {
            for (int cdown = 0; cdown < N; ++cdown) {
                for (int last = 1; last <= 4; ++last) {
                    for (int b = 0; b < 3; ++b) {
                        for (int next = 1; next <= 4; ++next) {
                            int hasup = 0, hasdown = 0;
                            int d = 0;
                            if (last < next) d = 2;
                            else if (last > next) d = 1;
                            if (d == 1 && b == 2) hasup = 1;
                            if (d == 2 && b == 1) hasdown = 1;
                            if (d == 0) continue;
                            // if (k == 2 && cup == 0 && cdown == 0) show(last, next, b, hasup, hasdown);
                            if (cup + hasup < N && cdown + hasdown < N)
                                dp[k + 1][cup + hasup][cdown + hasdown][next][d] += dp[k][cup][cdown][last][b];
                        }
                    }
                }
            }
        }
    }
    ll total = 0;
    for (int last = 1; last <= 4; ++last) {
        for (int b = 0; b < 3; ++b) {
            total += dp[n][t][t - 1][last][b];
        }
    }
    cout << total << endl;

    return 0;
}