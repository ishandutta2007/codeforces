/*input
2
1048575 1048575
0 0
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

// vertex start from 0
struct EulerCycle {
// tested on Kattis-Eulerian Path
#define data data__
    struct data {
        int u, rev;
    };
    int n, m = 0;
    vector<vector<data>> a;
    vector<int> path; vector<bool> seen;

    void dfs(int u) {
        while (!a[u].empty()) {
            auto [v, rev] = a[u].back(); a[u].pop_back();
            if (seen[rev]) continue;
            seen[rev] = true;
            dfs(v);
        }
        path.push_back(u);
    }

    // void addEdge(int u, int v) {
    //     a[u].push_front({v, 0});
    //     out[u]++; in[v]++;
    // }
    // bool haveEuler() {
    //     int sta = -1; int total = 0;
    //     loop(i, 0, n - 1) {
    //         if (out[i] - in[i] == 1) sta = i;
    //         if (out[i] != in[i]) total++;
    //     }
    //     if (total != 0) return false; // if path then add total!=2
    //     if (sta == -1) loop(i, 0, n - 1) if (in[i]) sta = i;
    //     if (sta == -1) sta = 0;
    //     dfs(sta);
    //     loop(i, 0, n - 1) if (!a[i].empty()) return false;
    //     reverse(path.begin(), path.end());
    //     return (path.front() == path.back()); // only for cycle. if path, return true
    // }

    void addEdge(int u, int v) {
        a[u].push_back({v, m});
        a[v].push_back({u, m});
        m++;
    }

    bool haveEuler() {
        seen.assign(m, 0);
        int sta = -1; int total = 0;
        loop(i, 0, n - 1) if (a[i].size() % 2) total++, sta = i;
        if (total != 0) return false; // if path then add total!=2
        if (sta == -1) loop(i, 0, n - 1) if (a[i].size()) sta = i;
        if (sta == -1) sta = 0;
        dfs(sta);
        loop(i, 0, n - 1) if (!a[i].empty()) return false;
        reverse(path.begin(), path.end());
        return (path.front() == path.back()); // only for cycle. if path, return true
    }

    EulerCycle() {};
    EulerCycle(int _n): n(_n), a(n, vector<data>()) {};
} euler;

int n;
vector<pair<int, int> > a;
vector<int> path;
bool check(int mid) {
    int mask = (1 << mid) - 1;
    euler = EulerCycle(1 + mask + 2 * n);
    loop(i, 0, a.size() - 1) {
        euler.addEdge(i * 2, i * 2 + 1);
        euler.addEdge(i * 2, 2 * n + (mask & a[i].fi));
        euler.addEdge(i * 2 + 1, 2 * n + (mask & a[i].se));
    }
    if (euler.haveEuler()) {
        path = euler.path;
        return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    int l = 0, r = 20;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    check(l);
    cout << l << endl;
    for (auto it : path) {
        if (it < 2 * n) cout << it + 1 << sp;
    }
    cout << endl;
}