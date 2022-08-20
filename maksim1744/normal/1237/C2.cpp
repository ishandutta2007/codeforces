/*
    author:  Maksim1744
    created: 16.10.2019 17:47:56
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> v(n);
    // cin >> v;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second.first;
        v[i].second.second = i + 1;
    }
    sort(v.begin(), v.end());
    vector<bool> leave(n, true);
    int ind = 1;
    while (ind < n) {
        if (v[ind].first == v[ind - 1].first) {
            leave[ind] = false;
            leave[ind - 1] = false;
            cout << v[ind - 1].second.second << ' ' << v[ind].second.second << '\n';
            ind += 2;
        } else {
            ++ind;
        }
    }
    vector<pair<pair<int, int>, int>> v2;
    for (int i = 0; i < n; ++i) {
        if (leave[i]) {
            v2.eb(v[i].first, v[i].second.second);
        }
    }
    show(v2);
    n = v2.size();
    sort(v2.begin(), v2.end());
    leave.assign(n, true);
    ind = 1;
    while (ind < n) {
        if (v2[ind].first.first == v2[ind - 1].first.first) {
            leave[ind] = false;
            leave[ind - 1] = false;
            cout << v2[ind - 1].second << ' ' << v2[ind].second << '\n';
            ind += 2;
        } else {
            ++ind;
        }
    }
    vector<pair<int, int>> v3;
    for (int i = 0; i < n; ++i) {
        if (leave[i]) {
            v3.eb(v2[i].first.first, v2[i].second);
        }
    }
    sort(v3.begin(), v3.end());
    for (int i = 1; i < v3.size(); i += 2) {
        cout << v3[i - 1].second << ' ' << v3[i].second << '\n';
    }
    return 0;
}