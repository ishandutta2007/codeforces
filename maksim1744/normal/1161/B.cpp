/*
    author:  Maksim1744
    created: 05.05.2019 23:02:11
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ln(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ln[a - 1].pb((b - a + n) % n);
        ln[b - 1].pb((a - b + n) % n);
    }
    for (int i = 0; i < n; ++i) {
        sort(ln[i].begin(), ln[i].end());
    }
    for (int i = 0; i < n; ++i) {
        ln.pb(ln[i]);
    }
    show(ln);
    vector<int> z(n * 2, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n * 2; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n * 2 && ln[z[i]] == ln[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    show(z);
    for (int i = 1; i < n; ++i) {
        if (z[i] >= n) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}