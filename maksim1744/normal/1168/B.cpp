/*
    author:  Maksim1744
    created: 26.06.2019 21:51:56
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

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    ll n = s.size();
    for (ll l = 0; l < n; ++l) {
        for (ll r = l; r < n; ++r) {
            bool ok = false;
            for (int x = l; x <= r; ++x) {
                for (int d = 1; x + 2 * d <= r; ++d) {
                    if (s[x] == s[x + d] && s[x + d] == s[x + d * 2]) {
                        ok = true;
                        break;
                    }
                }
                if (ok)
                    break;
            }
            if (ok) {
                ans += n - r;
                break;
            }
        }
    }
    cout << ans << '\n';
    // for (int i = 1; i <= 20; ++i) {
    //     bool ok = true;
    //     for (int k = 0; k < (1 << i); ++k) {
    //         string s;
    //         int x = k;
    //         for (int j = 0; j < i; ++j) {
    //             s.pb('0' + x % 2);
    //             x /= 2;
    //         }
    //         bool oks = false;
    //         for (int j = 0; j < i; ++j) {
    //             for (int d = 1; j + d * 2 < i; ++d) {
    //                 if (s[j] == s[j + d] && s[j] == s[j + d * 2]) {
    //                     oks = true;
    //                     break;
    //                 }
    //             }
    //         }
    //         if (!oks) {
    //             ok = false;
    //             showt(i, s);
    //             break;
    //         }
    //     }
    // }
    return 0;
}