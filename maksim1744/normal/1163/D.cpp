/*
    author:  Maksim1744
    created: 09.05.2019 19:10:07
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int inf = 10000;

int main() {
    string mask, s, t;
    cin >> mask >> s >> t;
    vector<vector<vector<int>>> dp(mask.size() + 3, vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, -inf)));
    dp[0][0][0] = 0;
    function<void(int, int, int)> go = [&](int i, int j, int k) {
        if (i >= mask.size())
            return;
        char c1 = 'a', c2 = 'z';
        if (mask[i] != '*')
            c1 = c2 = mask[i];
        for (char c = c1; c <= c2; ++c) {
            int u = 0;
            if (j + 1 == s.size() && c == s.back()) {
                ++u;
            }
            if (k + 1 == t.size() && c == t.back()) {
                --u;
            }
            int j1;
            for (j1 = min((int)s.size() - 1, j + 1); j1 >= 1; --j1) {
                if (c == s[j1 - 1]) {
                    bool ok = true;
                    for (int y = 0; y < j1 - 1; ++y) {
                        if (s[j - 1 - y] != s[j1 - 2 - y]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        break;
                }
            }
            int k1;
            for (k1 = min((int)t.size() - 1, k + 1); k1 >= 1; --k1) {
                if (c == t[k1 - 1]) {
                    bool ok = true;
                    for (int y = 0; y < k1 - 1; ++y) {
                        if (t[k - 1 - y] != t[k1 - 2 - y]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        break;
                }
            }
            // show(c, j1, k1);
            dp[i + 1][j1][k1] = max(dp[i][j][k] + u, dp[i + 1][j1][k1]);
        }
    };
    for (int i = 0; i < mask.size() + 1; ++i) {
        for (int j = 0; j < s.size() + 1; ++j) {
            for (int k = 0; k < t.size() + 1; ++k) {
                if (dp[i][j][k] != -inf)
                    go(i, j, k);
            }
        }
    }
    // for (int i = 0; i < mask.size() + 1; ++i) {
    //     printMatrix(dp[i]);
    //     shows;
    // }
    int ans = -inf;
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= t.size(); ++j) {
            ans = max(ans, dp[mask.size()][i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}