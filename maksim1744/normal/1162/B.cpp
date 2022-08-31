/*
    author:  Maksim1744
    created: 06.05.2019 15:57:16
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
    vector<vector<int>> a(n, vector<int>(m)), b = a;
    cin >> a >> b;
    auto no = []() {
        cout << "Impossible\n";
        exit(0);
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int mx = -1;
            if (i != 0)
                mx = max(mx, a[i - 1][j]);
            if (j != 0)
                mx = max(mx, a[i][j - 1]);
            if (a[i][j] <= mx && b[i][j] <= mx) {
                no();
            } else if (a[i][j] > b[i][j] && b[i][j] > mx) {
                swap(a[i][j], b[i][j]);
            }
        }
    }
    printMatrix(a);
    printMatrix(b);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m - 1; ++j)
            if (a[i][j] >= a[i][j + 1] || b[i][j] >= b[i][j + 1])
                no();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] >= a[i + 1][j] || b[i][j] >= b[i + 1][j])
                no();
    cout << "Possible\n";
    return 0;
}