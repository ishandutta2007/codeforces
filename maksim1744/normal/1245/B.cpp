/*
    author:  Maksim1744
    created: 01.11.2019 17:38:20
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
#endif

int main() {
    int T;
    cin >> T;
    string chr = "RPS";
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(3);
        cin >> a;
        string s;
        cin >> s;
        vector<int> b(3);
        for (auto c : s) {
            if (c == 'R')
                b[0]++;
            else if (c == 'P')
                b[1]++;
            else
                b[2]++;
        }
        show(a, b);
        int can = min(a[1], b[0]) + min(a[2], b[1]) + min(a[0], b[2]);
        if (can < (n + 1) / 2) {
            cout << "NO\n";
            continue;
        }
        string ans(n, ' ');
        for (int i = 0; i < n; ++i) {
            int ind = 0;
            if (s[i] == 'P')
                ind = 1;
            else if (s[i] == 'S')
                ind = 2;
            if (a[(ind + 1) % 3] == 0)
                continue;
            a[(ind + 1) % 3]--;
            ans[i] = chr[(ind + 1) % 3];
        }
        string left = "";
        for (int i = 0; i < 3; ++i) {
            left += string(a[i], chr[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] == ' ') {
                ans[i] = left.back();
                left.pop_back();
            }
        }
        cout << "YES\n";
        cout << ans << '\n';
    }
    return 0;
}