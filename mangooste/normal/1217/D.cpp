#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #define DEBUG

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

int n, m;
vector<vector<pair<int, int>>> G;
vector<int> used;
bool cycles = false;
vector<int> ans;

void dfs_cycles(int v) {
    used[v] = 1;
    for (auto i : G[v]) {
        int u = i.first;
        cycles |= (used[u] == 1);
        if (!used[u])
            dfs_cycles(u);
    }
    used[v] = 2;
}

void dfs_ans(int v) {
    used[v] = 1;
    for (auto i : G[v]) {
        int u = i.first, num = i.second;
        if (used[u] == 1)
            ans[num] = 1;
        else
            ans[num] = 0;
        if (!used[u])
            dfs_ans(u);
    }
    used[v] = 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].eb(u, i);
    }
    used.resize(n);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs_cycles(i);
    if (!cycles) {
        cout << "1\n";
        for (int i = 0; i < m; i++)
            cout << "1 ";
        cout << '\n';
        return 0;
    }
    fill(all(used), 0);
    ans.resize(m, -1);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs_ans(i);
    cout << "2\n";
    for (auto el : ans)
        cout << el + 1 << ' ';
    cout << '\n';
}