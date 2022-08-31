/*
    author:  Maksim1744
    created: 23.02.2020 19:32:53
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

    int n, k;
    cin >> n >> k;
    n = 1 << n;
    vector<int> a(k);
    cin >> a;
    --a;
    vector<bool> good(n, false);
    for (auto u : a) {
        good[u] = true;
    }
    vector<vector<vector<int>>> v(n, vector<vector<int>>(2, vector<int>(2, -1)));
    vector<vector<vector<int>>> v1(n, vector<vector<int>>(2, vector<int>(2, -1)));
    for (int i = 0; i < n / 2; ++i) {
        int i1 = good[i * 2];
        int i2 = good[i * 2 + 1];
        v[i][i1][i2] = 0;
        v[i][i2][i1] = 0;
        if (i1 == 0 && i2 == 0) continue;
        v[i][i1][i2] = 1;
        v[i][i2][i1] = 1;
    }
    int m = n / 2;
    bitset<4> b;
    bitset<3> b2;
    while (m != 1) {
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                v1[i][j / 2][j % 2] = -1;
            }
            auto r1 = v[i * 2];
            auto r2 = v[i * 2 + 1];
            for (int j = 0; j < 16; ++j) {
                b = j;
                if (v[i * 2][b[0]][b[2]] == -1 || v[i * 2 + 1][b[1]][b[3]] == -1)
                    continue;
                for (int k = 0; k < 8; ++k) {
                    b2 = k;
                    int delta = 0;
                    if (b[0] || b[1])
                        ++delta;
                    int w1 = b[b2[0]];
                    int to2 = b[1 - (int)b2[0]];
                    if (b[2] || b[3])
                        ++delta;
                    int down_win = b[2 + b2[1]];
                    if (to2 || down_win)
                        ++delta;
                    int w2;
                    if (b2[2])
                        w2 = to2;
                    else
                        w2 = down_win;
                    v1[i][w1][w2] = max(v1[i][w1][w2], v[i * 2][b[0]][b[2]] + v[i * 2 + 1][b[1]][b[3]] + delta);
                }
            }
        }
        swap(v, v1);
        m /= 2;
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (v[0][i][j] == -1)
                continue;
            ans = max(ans, v[0][i][j] + (i || j));
        }
    }
    cout << ans << endl;

    return 0;
}