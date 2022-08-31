/*
    author:  Maksim1744
    created: 20.06.2020 18:01:22
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
    string s, t;
    cin >> s >> t;
    string dif;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i])
            dif.pb(s[i]);
    }
    show(dif);
    if (count(dif.begin(), dif.end(), '0') != count(dif.begin(), dif.end(), '1')) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    set<int> s0, s1;
    for (int i = 0; i < dif.size(); ++i) {
        if (dif[i] == '0') s0.insert(i);
        else s1.insert(i);
    }
    while (true) {
        if (s0.empty() || s1.empty()) break;
        if (*s0.begin() > *s1.begin()) {
            swap(s0, s1);
        }
        int from = -20;
        while (true) {
            auto it = s0.lower_bound(from + 1);
            if (it == s0.end()) break;
            int ind = *it;
            it = s1.lower_bound(ind + 1);
            if (it == s1.end()) break;
            s0.erase(ind);
            from = *it;
            s1.erase(*it);
        }
        ++ans;
    }
    cout << ans << endl;

    return 0;
}