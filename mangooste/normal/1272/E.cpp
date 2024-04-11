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
    #define DEBUG

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

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

int n;
vector<int> a, ans, type;
vector<vector<int>> G, rev_G;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &i : a)
        cin >> i;
    G.resize(n);
    rev_G.resize(n);
    type.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            G[i].push_back(i - a[i]);
            rev_G[i - a[i]].push_back(i);
        }
        if (i + a[i] < n) {
            G[i].push_back(i + a[i]);
            rev_G[i + a[i]].push_back(i);
        }
        type[i] = a[i] % 2;
    }
    ans.resize(n, -1);
    for (int i = 0; i < n; i++)
        for (auto j : G[i])
            if (type[i] != type[j])
                ans[i] = 1;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (ans[i] != -1)
            q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : rev_G[v]) {
            if (type[u] == type[v] && (ans[u] > ans[v] + 1 || ans[u] == -1)) {
                ans[u] = ans[v] + 1;
                q.push(u);
            }
        }
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}