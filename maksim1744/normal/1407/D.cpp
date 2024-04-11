/*
    author:  Maksim1744
    created: 08.09.2020 18:50:40
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

    vector<int> stup = {0}, stdown = {0};
    int n;
    cin >> n;
    vector<int> h(n);
    cin >> h;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    vector<int> prevl(n, -1), prevb(n, -1);
    vector<int> preve(n, -1);
    map<int, int> last;
    for (int i = 0; i < n; ++i) {
        if (last.count(h[i])) preve[i] = last[h[i]];
        last[h[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        while (!stup.empty() && h[stup.back()] >= h[i]) {
            stup.pop_back();
        }
        while (!stdown.empty() && h[stdown.back()] <= h[i]) {
            stdown.pop_back();
        }
        if (!stup.empty()) prevl[i] = stup.back();
        if (!stdown.empty()) prevb[i] = stdown.back();
        stup.pb(i);
        stdown.pb(i);
    }
    // show(prevl);
    // show(prevb);
    for (int i = 1; i < n; ++i) {
        int indl = prevl[i];
        int indb = prevb[i];
        int ind = prevb[i];
        dp[i] = dp[i - 1] + 1;
        while (ind != -1 && ind >= indl && ind >= preve[i]) {
            dp[i] = min(dp[i], dp[ind] + 1);
            if (h[ind] <= h[i]) break;
            ind = prevl[ind];
        }
        ind = prevl[i];
        while (ind != -1 && ind >= indb && ind >= preve[i]) {
            dp[i] = min(dp[i], dp[ind] + 1);
            if (h[ind] >= h[i]) break;
            ind = prevb[ind];
        }
    }
    // show(dp);
    cout << dp.back() << '\n';

    return 0;
}