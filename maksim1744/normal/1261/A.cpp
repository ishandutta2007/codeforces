/*
    author:  Maksim1744
    created: 26.11.2019 21:25:56
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string t;
        for (int i = 0; i < (n - 2 * (k - 1)) / 2; ++i)
            t.pb('(');
        for (int i = 0; i < (n - 2 * (k - 1)) / 2; ++i)
            t.pb(')');
        for (int i = 0; i < k - 1; ++i) {
            t += "()";
        }
        int first_opened = 0, first_closed = 0;
        while (s[first_opened] != '(')
            ++first_opened;
        while (s[first_closed] != ')')
            ++first_closed;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) {
                if (first_opened == i) {
                    ++first_opened;
                    while (first_opened < n && s[first_opened] != '(')
                        ++first_opened;
                } else {
                    ++first_closed;
                    while (first_closed < n && s[first_closed] != ')')
                        ++first_closed;
                }
            } else {
                if (s[i] == '(') {
                    // here first_opened = i, so s[i..first_closed] = '((..(()'
                    swap(s[i], s[first_closed]);
                    ans.eb(i + 1, first_closed + 1);
                    ++first_opened;
                    while (first_closed < n && s[first_closed] != ')')
                        ++first_closed;
                } else {
                    // here first_closed = i
                    swap(s[i], s[first_opened]);
                    ans.eb(i + 1, first_opened + 1);
                    ++first_closed;
                    while (first_opened < n && s[first_opened] != '(')
                        ++first_opened;
                }
            }
        }
        assert(s == t);
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}