/*
    author:  Maksim1744
    created: 11.06.2019 16:13:47
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
    set<char> gl = {'a', 'o', 'u', 'i', 'e'};
    map<int, vector<pair<char, string>>> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int cnt = 0;
        char l = 'q';
        for (auto c : s) {
            if (gl.find(c) != gl.end()) {
                ++cnt;
                l = c;
            }
        }
        if (cnt == 0)
            continue;
        mp[cnt].eb(l, s);
    }
    // for (auto& p : mp) {
    //     sort(p.second.begin(), p.second.end());
    // }
    vector<pair<string, string>> good, bad;
    for (auto& p : mp) {
        auto& v = p.second;
        map<char, vector<string>> let;
        for (auto pr : v) {
            let[pr.first].pb(pr.second);
        }
        vector<string> left;
        for (auto& pr : let) {
            for (int i = 0; i + 1 < pr.second.size(); i += 2) {
                good.eb(pr.second[i], pr.second[i + 1]);
            }
            if (pr.second.size() % 2 == 1)
                left.pb(pr.second.back());
        }
        for (int i = 0; i + 1 < left.size(); i += 2) {
            bad.eb(left[i], left[i + 1]);
        }
    }
    while (good.size() > bad.size()) {
        bad.pb(good.back());
        good.pop_back();
    }
    cout << min(good.size(), bad.size()) << '\n';
    for (int i = 0; i < min(good.size(), bad.size()); ++i) {
        cout << bad[i].first << ' ' << good[i].first << '\n';
        cout << bad[i].second << ' ' << good[i].second << '\n';
    }
    return 0;
}