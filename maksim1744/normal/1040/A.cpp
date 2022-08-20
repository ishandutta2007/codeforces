/*
    author:  Maksim1744
    created: 07.05.2019 17:53:01
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

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    cin >> v;
    int s = 0;
    if (n % 2 == 1)
        if (v[n / 2] == 2)
            s += min(a, b);
    for (int i = 0; i < n - 1 - i; ++i) {
        vector<int> p = {v[i], v[n - i - 1]};
        sort(p.begin(), p.end());
        if (p == vector<int>{0, 0} || p == vector<int>{1, 1})
            continue;
        else if (p == vector<int>{0, 1}) {
            cout << -1 << '\n';
            return 0;
        }
        else if (p == vector<int>{0, 2})
            s += a;
        else if (p == vector<int>{1, 2})
            s += b;
        else if (p == vector<int>{2, 2})
            s += min(a, b) * 2;
        else
            assert(false);
    }
    cout << s << '\n';
    return 0;
}