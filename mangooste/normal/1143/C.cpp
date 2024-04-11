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
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

int n;
vector<int> c;
vector<vector<int>> G;
vector<int> ans;

void dfs(int v) {
    bool chk = (c[v] == 1);
    for (auto u : G[v]) {
        dfs(u);
        chk &= (c[u] == 1);
    }
    if (chk)
        ans.pb(v);
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int root = -1;
    cin >> n;
    G.resize(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
        int par;
        cin >> par >> c[i];
        if (par == -1)
            root = i;
        else 
            G[par - 1].pb(i);
    }
    dfs(root);
    if (ans.size() == 0)
        return cout << "-1\n", 0;
    sort(all(ans));
    for (auto el : ans)
        cout << el + 1 << ' ';
    cout << '\n';
}