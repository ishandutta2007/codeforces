/*
    author:  Maksim1744
    created: 02.05.2019 16:49:08
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
    vector<set<pair<int, int>>> ans(n);
    int ind = 1;
    vector<pair<int, int>> e(m);
    vector<vector<int>> ad(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        ad[i][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> e[i];
        --e[i].first;
        --e[i].second;
        if (e[i].first > e[i].second)
            swap(e[i].first, e[i].second);
        ad[e[i].first][e[i].second] = 1;
        ad[e[i].second][e[i].first] = 1;
    }
    sort(e.begin(), e.end());
    set<int> now;
    for (auto p : e) {
        bool ok = true;
        for (auto u : now) {
            if (!ad[u][p.first] || !ad[u][p.second]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            ++ind;
            now.clear();
        }
        ans[p.first].insert({p.first + 1, ind});
        ans[p.second].insert({p.second + 1, ind});
        now.insert(p.first);
        now.insert(p.second);
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i].size() == 0)
            ans[i].insert({i + 1, ++ind});
        cout << ans[i].size() << '\n';
        for (auto p : ans[i]) {
            cout << p << '\n';
        }
    }
    return 0;
}