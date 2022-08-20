/*
    author:  Maksim1744
    created: 16.06.2020 17:53:14
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

void test_case() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> t(m);
    cin >> t;
    set<int> done;
    vector<vector<int>> lvl;
    while (done.size() < m) {
        lvl.eb();
        for (int i = 0; i < m; ++i) {
            if (t[i] == 0 && !done.count(i)) {
                done.insert(i);
                lvl.back().pb(i);
            }
        }
        for (auto u : lvl.back()) {
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] > 0) t[i] -= abs(u - i);
            }
        }
    }
    map<char, int> cnt;
    for (auto c : s) {
        cnt[c]++;
    }
    vector<pair<char, int>> cnts;
    for (auto [a, b] : cnt) {
        cnts.eb(a, b);
    }
    sort(cnts.begin(), cnts.end());
    string code;
    for (int i = 0; i < lvl.size(); ++i) {
        while (cnts.back().second < lvl[i].size()) cnts.pop_back();
        code.pb(cnts.back().first);
        cnts.pop_back();
    }
    string ans(m, '*');
    for (int i = 0; i < lvl.size(); ++i) {
        for (auto u : lvl[i]) {
            ans[u] = code[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}