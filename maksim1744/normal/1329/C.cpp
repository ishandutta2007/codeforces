/*
    author:  Maksim1744
    created: 03.04.2020 18:02:42
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
const int N = 20;
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
const int N = (1 << 20) + 20;
#endif

array<int, N> a;
array<int, N> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    a.fill(0);
    while (T--) {
        int h, g;
        cin >> h >> g;
        int n = (1 << h) - 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i + 1];
        }
        auto get_dpt = [&](int i, int lvl) {
            while (true) {
                if (i * 2 + 1 >= a.size()) return lvl;
                if (a[i * 2] == 0 && a[i * 2 + 1] == 0) return lvl;
                if (a[i * 2] > a[i * 2 + 1]) {
                    i *= 2;
                    lvl++;
                }
                else {
                    i = i * 2 + 1;
                    lvl++;
                }
            }
        };
        auto dl = [&](int i) {
            while (true) {
                if (i * 2 + 1 >= a.size()) {
                    a[i] = 0;
                    return;
                }
                if (a[i * 2] == 0 && a[i * 2 + 1] == 0) {
                    a[i] = 0;
                    return;
                }
                if (a[i * 2] > a[i * 2 + 1]) {
                    a[i] = a[i * 2];
                    i *= 2;
                }
                else {
                    a[i] = a[i * 2 + 1];
                    i = i * 2 + 1;
                }
            }
        };
        int lvl = -1;
        int ind = 0;
        for (int i = 1; i <= n; ++i) {
            if (__builtin_popcount(i) == 1)
                ++lvl;
            while (a[i] != 0 && get_dpt(i, lvl) > g - 1) {
                ans[ind++] = i;
                dl(i);
            }
        }
        ll sm = 0;
        for (int i = 1; i <= ((1 << g) - 1); ++i)
            sm += a[i];
        cout << sm << '\n';
        for (int i = 0; i < ind; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';

        for (int i = 0; i < n; ++i) {
            a[i + 1] = 0;
        }
    }

    return 0;
}