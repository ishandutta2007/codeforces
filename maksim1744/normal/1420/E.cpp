/*
    author:  Maksim1744
    created: 24.09.2020 18:30:29
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

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int cnt = 0;
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++cnt;
        } else {
            c.pb(cnt);
            cnt = 0;
        }
    }
    c.pb(cnt);

    const int M = 82;
    const int inf = 1e9;
    vector<vector<vector<int>>> dp(c.size() + 1, vector<vector<int>>(n * (n - 1) / 2 + 1, vector<int>(M * 2 + 1, inf)));
    dp[0][0][M] = 0;
    for (int i = 0; i < c.size(); ++i) {
        for (int k = 0; k < dp[i].size(); ++k) {
            for (int d = -M; d <= M; ++d) {
                if (dp[i][k][M + d] == inf) continue;
                int last = c[i] - d;
                for (int d2 = -M; d2 <= M; ++d2) {
                    int x = last + d2;
                    if (x < 0) continue;
                    if (k + abs(d2) >= dp[i].size()) continue;
                    umin(dp[i + 1][k + abs(d2)][M + d2], dp[i][k][M + d] + x * (x - 1) / 2);
                }
            }
        }
    }
    int al = sum(c);
    al = al * (al - 1) / 2;
    int cur = 1e9;
    for (int i = 0; i < dp[0].size(); ++i) {
        cur = min(cur, dp.back()[i][M]);
        cout << al - cur << ' ';
    }
    cout << '\n';

    return 0;
}