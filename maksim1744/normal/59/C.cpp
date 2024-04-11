/*
    author:  Maksim1744
    created: 20.08.2020 15:15:01
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

    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> with(n);
    for (int i = 0; i < n; ++i) {
        with[i] = n - i - 1;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[with[i]]) {
            if (s[i] == '?') {
                s[i] = s[with[i]];
            } else if (s[with[i]] == '?') {
                s[with[i]] = s[i];
            } else {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    set<char> need;
    for (int i = 0; i < k; ++i) {
        need.insert('a' + i);
    }
    vector<int> left;
    for (int i = 0; i <= with[i]; ++i) {
        if (s[i] == '?') {
            left.pb(i);
        } else {
            need.erase(s[i]);
        }
    }
    if (left.size() < need.size()) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    while (!need.empty()) {
        char c = *--need.end();
        need.erase(--need.end());
        int i = left.back();
        left.pop_back();
        s[i] = c;
        s[with[i]] = c;
    }
    while (!left.empty()) {
        int i = left.back();
        left.pop_back();
        s[i] = 'a';
        s[with[i]] = 'a';
    }
    cout << s << endl;

    return 0;
}