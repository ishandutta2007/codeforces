/*
    author:  Maksim1744
    created: 26.06.2019 18:02:06
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

ll inf = 1e15;

int main() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    string s;
    cin >> s;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n + 1; ++k) {
            set<char> was;
            for (int j = k + 1; j <= n; ++j) {
                if (was.find(s[j - 1]) == was.end()) {
                    dp[i + 1][j] += dp[i][k];
                    dp[i + 1][j] = min(dp[i + 1][j], inf);
                    was.insert(s[j - 1]);
                }
            }
        }
    }
    vector<ll> cnt(n + 1, 0);
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cnt[i] += dp[i][j];
        }
        umin(cnt[i], inf);
    }
    ll sm = 0;
    int ind = n;
    while (k >= 0 && ind >= 0) {
        ll c = min(k, cnt[ind]);
        k -= c;
        sm += c * (n - ind);
        --ind;
    }
    if (k > 0)
        sm = -1;
    cout << sm << '\n';
    return 0;
}