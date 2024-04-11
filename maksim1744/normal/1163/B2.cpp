/*
    author:  Maksim1744
    created: 09.05.2019 18:20:05
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
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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

const int nax = 100005;

int main() {
    vector<int> cnt(nax, 0);
    int n;
    cin >> n;
    vector<int> u(n);
    cin >> u;
    map<int, int> m;
    int x = 1;
    for (int i = 0; i < n; ++i) {
        if (cnt[u[i]] != 0) {
            --m[cnt[u[i]]];
            if (m[cnt[u[i]]] == 0)
                m.erase(cnt[u[i]]);
        }
        ++cnt[u[i]];
        ++m[cnt[u[i]]];
        show(m);
        if (m.size() == 2) {
            auto p1 = *m.begin(), p2 = *++m.begin();
            if (p1.first == 1 && p1.second == 1)
                x = i + 1;
            if (p2.second == 1 && p1.first + 1 == p2.first)
                x = i + 1;
        } else if (m.size() == 1 && (m.begin()->first == 1 || m.begin()->second == 1)) {
            x = i + 1;
        }
    }
    cout << x << '\n';
    return 0;
}