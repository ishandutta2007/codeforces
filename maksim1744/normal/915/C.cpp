/*
    author:  Maksim1744
    created: 20.01.2021 18:51:44
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

    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (a.size() < b.size()) {
        cout << a << '\n';
        return 0;
    }
    assert(a.size() == b.size());
    auto can = [&](string s, string t) {
        assert(s.size() == t.size());
        sort(s.begin(), s.end());
        return s <= t;
    };
    for (int i = 0; i + 1 < a.size(); ++i) {
        sort(a.begin() + i, a.end());
        reverse(a.begin() + i, a.end());
        int j = i;
        // while (!can(a.substr(i + 1, a.size()), b.substr(i + 1, b.size()))) {
        cerr << a << ' ' << b << ' ' << i << ' ' << j << endl;
        while (a[i] > b[i]) {
            swap(a[i], a[j]);
            ++j;
            swap(a[i], a[j]);
        }
        cerr << a << ' ' << b << ' ' << i << ' ' << j << endl;
        while (a[i] == b[i] && !can(a.substr(i + 1, a.size()), b.substr(i + 1, b.size()))) {
            swap(a[i], a[j]);
            ++j;
            swap(a[i], a[j]);
        }
        sort(a.begin() + i + 1, a.end());
        reverse(a.begin() + i + 1, a.end());
        if (a[i] < b[i]) break;
    }
    cout << a << '\n';

    return 0;
}