/*
    author:  Maksim1744
    created: 05.10.2020 14:10:14
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> where(m);
    cin >> v;
    vector<vector<pair<int, int>>> vs(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vs[i][j] = mp(v[i][j], j);
        }
    }
    vector<int> cnt_mx(n, 0);
    for (int i = 0; i < n; ++i) {
        sort(vs[i].begin(), vs[i].end());
        reverse(vs[i].begin(), vs[i].end());
        while (!vs[i].empty() && vs[i].back().first == -1) {
            where[vs[i].back().second].pb(i);
            vs[i].pop_back();
        }
        sort(vs[i].begin(), vs[i].end());
        if (vs[i].empty()) continue;
        int mx = vs[i].back().first;
        while (!vs[i].empty() && vs[i].back().first == mx) {
            where[vs[i].back().second].pb(i);
            vs[i].pop_back();
            cnt_mx[i]++;
        }
    }
    // vector<set<int>> canmax(n);
    set<int> cur_max;
    vector<bool> u(m, false);
    for (int i = 0; i < m; ++i) {
        if (where[i].size() == n) {
            cur_max.insert(i);
        }
    }

    vector<int> order;
    for (int i = 0; i < m; ++i) {
        show(cur_max, where);
        while (!cur_max.empty() && u[*cur_max.begin()]) {
            cur_max.erase(cur_max.begin());
        }
        if (cur_max.empty()) break;
        int col = *cur_max.begin();
        u[col] = true;
        for (auto row : where[col]) {
            if (v[row][col] == -1) continue;
            cnt_mx[row]--;
            if (cnt_mx[row] == 0 && !vs[row].empty()) {
                int mx = vs[row].back().first;
                while (!vs[row].empty() && vs[row].back().first == mx) {
                    where[vs[row].back().second].pb(row);
                    cnt_mx[row]++;
                    if (where[vs[row].back().second].size() == n) {
                        cur_max.insert(vs[row].back().second);
                    }
                    vs[row].pop_back();
                }
            }
        }
        order.pb(col);
    }

    if (order.size() != m) {
        cout << "-1\n";
        return 0;
    }
    reverse(order.begin(), order.end());
    ++order;
    cout << order << '\n';

    return 0;
}