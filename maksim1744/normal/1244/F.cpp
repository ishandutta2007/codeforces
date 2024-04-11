/*
    author:  Maksim1744
    created: 13.10.2019 12:51:06
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> v;
    vector<char> c;
    int last = 0;
    // n *= 3;
    s = s + s + s;
    s.pb(s.back() + 1);
    ++n;
    for (int i = 1; i < n * 3; ++i) {
        if (s[i] == s[last])
            continue;
        else {
            if (i == last + 1) {
                last = i;
            } else {
                v.eb(last, i - 1);
                c.pb(s[last]);
                last = i;
            }
        }
    }
    s.pop_back();
    --n;
    if (v.empty()) {
        if (k % 2 == 0) {
            cout << s.substr(0, n) << '\n';
        } else {
            s = s.substr(0, n);
            for (auto c : s) {
                cout << (char)((int)'W' + (int)'B' - c);
            }
            cout << '\n';
        }
        return 0;
    }
    // v.eb(v[0].first + n, v[0].second + n);
    // c.pb(c[0]);
    show(v);
    for (int i = 0; i + 1 < v.size(); ++i) {
        if (v[i].second + k < v[i + 1].first - k) {
            v[i].second += k;
            v[i + 1].first -= k;
        } else {
            int m = (v[i + 1].first + v[i].second) / 2;
            v[i].second = m;
            v[i + 1].first = m + 1;
        }
    }
    v[0].first = max(0, v.back().first - n * 3);
    if (k % 2 == 1) {
        for (int i = 0; i < n * 3; ++i) {
            s[i] = (int)'W' + (int)'B' - s[i];
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = v[i].first; j <= min(n * 3 - 1, v[i].second); ++j) {
            s[j] = c[i];
        }
    }
    // cout << s << '\n';
    for (int i = n; i < n * 2; ++i) 
        cout << s[i];
    cout << '\n';
    return 0;
}