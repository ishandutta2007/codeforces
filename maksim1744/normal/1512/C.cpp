/*
    author:  Maksim1744
    created: 10.04.2021 17:39:30
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

void test_case(int test) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> prs;
    if (s.size() % 2 == 1) {
        if (a % 2 == b % 2) {
            cout << -1 << '\n';
            return;
        }
        if (a % 2) {
            if (s[n / 2] == '1') {
                cout << -1 << '\n';
                return;
            }
            s[n / 2] = '0';
        } else {
            if (s[n / 2] == '0') {
                cout << -1 << '\n';
                return;
            }
            s[n / 2] = '1';
        }
    } else {
        if (a % 2 || b % 2) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; n - i - 1 > i; ++i) {
        if (s[i] == '?') {
            s[i] = s[n - i - 1];
        } else if (s[n - i - 1] == '?') {
            s[n - i - 1] = s[i];
        } else {
            if (s[i] != s[n - i - 1]) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    show(s, a, b);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') --a;
        else if (s[i] == '1') --b;
        else if (i < n - i - 1) prs.eb(i, n - i - 1);
    }
    if (a < 0 || b < 0) {
        cout << -1 << '\n';
        return;
    }
    if (a + b != prs.size() * 2) {
        cout << -1 << '\n';
        return;
    }
    a /= 2;
    for (int i = 0; i < a; ++i) {
        s[prs[i].first] = '0';
        s[prs[i].second] = '0';
    }
    for (int i = a; i < prs.size(); ++i) {
        s[prs[i].first] = '1';
        s[prs[i].second] = '1';
    }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}