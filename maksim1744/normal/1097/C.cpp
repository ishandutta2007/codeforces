/*
    author:  Maksim1744
    created: 01.05.2019 21:45:26
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n;
    cin >> n;
    map<int, int> vo, vc, v0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int b = 0;
        for (auto c : s) {
            if (c == '(') {
                ++b;
            } else {
                --b;
                if (b < 0)
                    b = -1000000;
            }
        }
        if (b == 0) {
            ++v0[b];
        } else if (b > 0) {
            ++vo[b];
        } else {
            reverse(s.begin(), s.end());
            for (auto& c : s) {
                if (c == '(') c = ')';
                else c = '(';
            }
            b = 0;
            for (auto c : s) {
                if (c == '(') {
                    ++b;
                } else {
                    --b;
                    if (b < 0)
                        b = -1000000;
                }
            }
            if (b > 0) {
                ++vc[b];
            }
        }
    }
    show(vo, vc, v0);
    int ans = v0[0] / 2;
    for (auto p : vo) {
        ans += min(p.second, vc[p.first]);
    }
    cout << ans << '\n';
    return 0;
}