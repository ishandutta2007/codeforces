/*
    author:  Maksim1744
    created: 22.04.2019 23:09:39
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
const int N = 10;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int N = 5005;
#endif

vector<int> u(N * 2, -1);
vector<int> from(N * 2, -1);
int step = 0;

bool matching_dfs(int v, vector<vector<int>>& g) {
    u[v] = step;
    for (auto k : g[v]) {
        if (from[k] == -1 || (u[from[k]] < step && matching_dfs(from[k], g))) {
            from[k] = v;
            return true;
        }
    }
    return false;
}

int find_matching(vector<vector<int>>& g, int left, int start) {
    ++step;
    // vector<bool> u(g.size(), false);
    // vector<int> from(g.size(), -1);
    // from.assign(from.size(), -1);
    for (int v = start; v < left; ++v) {
        if (matching_dfs(v, g)) {
            ++step;
            // u.assign(g.size(), false);
        } else {
            return v;
        }
    }
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(N * 2);
    vector<int> p(n), c(n);
    cin >> p >> c;
    for (int i = 0; i < n; ++i) {
        g[p[i]].pb(c[i] + N);
        g[c[i] + N].pb(p[i]);
    }
    int d;
    cin >> d;
    int last = 0;
    vector<int> que(d);
    cin >> que;
    reverse(que.begin(), que.end());
    for (int k : que) {
        --k;
        int a = p[k], b = c[k] + N;
        g[a].erase(find(g[a].begin(), g[a].end(), b));
        g[b].erase(find(g[b].begin(), g[b].end(), a));
    }
    vector<int> ans;
    for (auto k : que) {
        --k;
        int a = p[k], b = c[k] + N;
        // if (a < last)
        last = find_matching(g, N, last);
        show(g, last);
        // cout << last << '\n';
        ans.pb(last);
        g[a].pb(b);
        g[b].pb(a);
    }
    reverse(ans.begin(), ans.end());
    for (auto k : ans) {
        cout << k << '\n';
    }
    return 0;
}