/*
    author:  Maksim1744
    created: 08.04.2020 17:52:35
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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cur = 0;
    int cr = 0;
    for (auto c : s) {
        if (c == 'R') ++cr;
        else cur += cr;
    }
    deque<vector<int>> change(n + 1);
    vector<vector<int>> ans(k);
    for (int i = 0; i < change.size(); ++i) {
        int j = 0;
        while (j + 1 < s.size()) {
            if (s.substr(j, 2) == "RL") {
                change[i].pb(j + 1);
                swap(s[j], s[j + 1]);
                ++j;
            }
            ++j;
        }
    }
    if (cur < k) {
        cout << -1 << endl;
        return 0;
    }
    while (!change.empty() && change.back().size() == 0)
        change.pop_back();
    if (change.size() > k) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < k; ++i) {
        if (change.size() == k - i) {
            ans[i] = change[0];
            change[0].clear();
        } else {
            ans[i].pb(change[0].back());
            change[0].pop_back();
        }
        if (change[0].empty()) {
            change.erase(change.begin());
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i].size() << ' ' << ans[i] << '\n';
    }

    return 0;
}