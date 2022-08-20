/*
    author:  Maksim1744
    created: 14.08.2020 01:12:06
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

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    cin >> v;
    map<int, int> who;
    set<int> ends;
    for (int i = 0; i < n; ++i) {
        who[v[i].first] = i;
        ends.insert(v[i].second);
    }
    int x = 0;
    vector<int> odd;
    while (true) {
        if (!who.count(x)) break;
        int ind = who[x];
        x = v[ind].second;
        odd.pb(x);
        who.erase(0);
    }
    x = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i].first != 0 && !ends.count(v[i].first)) {
            x = v[i].first;
            show(x);
            break;
        }
    }
    vector<int> even = {x};
    who.erase(0);
    while (true) {
        if (!who.count(x)) break;
        int ind = who[x];
        x = v[ind].second;
        even.pb(x);
    }
    show(odd, even);
    while (!even.empty() && even.back() == 0) even.pop_back();
    while (!odd.empty() && odd.back() == 0) odd.pop_back();
    reverse(odd.begin(), odd.end());
    reverse(even.begin(), even.end());
    int i = 0;
    while (!odd.empty() || !even.empty()) {
        if (i % 2 == 0) {
            cout << even.back() << ' ';
            even.pop_back();
        } else {
            cout << odd.back() << ' ';
            odd.pop_back();
        }
        ++i;
    }

    return 0;
}