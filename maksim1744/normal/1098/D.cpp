/*
    author:  Maksim1744
    created: 10.05.2019 23:29:53
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
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

const int B = 35;

int main() {
    int n;
    cin >> n;
    vector<multiset<int>> boxes(B);
    vector<ll> sms(B, 0);
    vector<ll> p2(B);
    for (int i = 0; i < B; ++i)
        p2[i] = (1ll << (i + 1)) - 1;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        int x;
        cin >> c >> x;
        int u = lowb(p2, x);
        if (c == '+') {
            boxes[u].insert(x);
            sms[u] += x;
            ++m;
        } else {
            boxes[u].erase(boxes[u].find(x));
            --m;
            sms[u] -= x;
        }
        int cnt = 0;
        // show(boxes);
        ll s = 0;
        for (int j = 0; j < B; ++j) {
            if (!boxes[j].empty() && s != 0 && s * 2 < *boxes[j].begin())
                ++cnt;
            s += sms[j];
        }
        cout << (m == 0 ? 0 : m - 1 - cnt) << '\n';
    }
    return 0;
}