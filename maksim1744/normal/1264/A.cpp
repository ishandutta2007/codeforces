/*
    author:  Maksim1744
    created: 05.12.2019 17:36:27
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        cin >> v;
        ll sm = 0;
        for (auto k : v) {
            sm += 1;
        }
        vector<pair<ll, int>> cnt;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || v[i] != v[i - 1]) {
                cnt.eb(v[i], 0);
            }
            cnt.back().second++;
        }
        show(cnt);
        sm /= 2;
        if (cnt.size() < 3) {
            cout << "0 0 0\n";
        } else {
            ll g = cnt[0].second;
            ll s = 0, b = 0;
            int ind = 1;
            while (ind < cnt.size() && s <= g) {
                s += cnt[ind].second;
                ++ind;
            }
            while (ind < cnt.size() && b <= g) {
                b += cnt[ind].second;
                ++ind;
            }
            if (g + s + b > sm || g >= s || g >= b) {
                cout << "0 0 0\n";
            } else {
                while (ind < cnt.size() && g + s + b + cnt[ind].second <= sm) {
                    b += cnt[ind].second;
                    ++ind;
                }
                cout << g << ' ' << s << ' ' << b << '\n';
            }
        }
    }
    return 0;
}