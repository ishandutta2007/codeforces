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

int n, d, k, pos;
vector<pair<int, int>> edges;
vector<char> used;
vector<int> deg, dst;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> d >> k;
    if (d >= n || (d > 1 && k < 2))
        return cout << "NO\n", 0;
    for (int i = 0; i < d; i++)
        edges.emplace_back(i, i + 1);
    used.resize(n);
    for (int i = 0; i < d; i++)
        used[i] = used[i + 1] = 1;
    deg.resize(n);
    deg[0] = deg[d] = 1;
    for (int i = 1; i < d; i++)
        deg[i] = 2;
    dst.resize(n, n + 1);
    pos = d + 1;
    for (int i = 1, already = 1; i <= d && pos < n; i++, already = max(already, i)) {
        int mx = max(already, d - i);
        queue<int> q;
        q.push(i);
        dst[i] = 0;
        while (!q.empty() && pos < n) {
            int v = q.front();
            q.pop();
            if (mx + dst[v] == d || dst[v] + dst[v] + 1 > d)
                break;
            while (pos < n && deg[v] < k) {
                deg[v]++;
                edges.emplace_back(v, pos);
                dst[pos] = dst[v] + 1;
                deg[pos] = 1;
                q.push(pos++);
            }
        }
    }
    if (pos != n)
        return cout << "NO\n", 0;
    cout << "YES\n";
    for (auto i : edges)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}