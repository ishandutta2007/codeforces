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
vector<vector<int>> G;
vector<char> used;

void dfs(int v) {
    used[v] = 1;
    for (auto u : G[v])
        if (!used[u])
            dfs(u);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n + 26);
    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        for (auto el : cur) {
            G[i].pb(el - 'a' + n);
            G[el - 'a' + n].pb(i);
        }
    }
    int ans = 0;
    used.resize(n + 26);
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    cout << ans << '\n';
}