/*
    author:  Maksim1744
    created: 13.02.2020 17:51:47
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

    int n, m, k;
    cin >> n >> m >> k;
    if (k > n * m * 4 - n * 2 - m * 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<string, int>> v;
    v.eb("R", m - 1);
    v.eb("L", m - 1);
    for (int i = 0; i < n - 1; ++i) {
        v.eb("D", 1);
        v.eb("RUD", m - 1);
        v.eb("L", m - 1);
    }
    v.eb("U", n - 1);
    vector<pair<string, int>> ans;
    for (auto [s, c] : v) {
        if (c == 0)
            continue;
        if (k == 0)
            break;
        if (k >= s.size() * c) {
            ans.eb(s, c);
            k -= s.size() * c;
        } else {
            if (k / s.size() != 0) {
                ans.eb(s, k / s.size());
                k %= s.size();
            }
            if (k != 0)
                ans.eb(s.substr(0, k), 1);
            k = 0;
        }
    }
    assert(ans.size() <= 3000);
    cout << ans.size() << '\n';
    for (auto [s, c] : ans) {
        cout << c << ' ' << s << '\n';
    }

    return 0;
}