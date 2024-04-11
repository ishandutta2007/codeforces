#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

vector<vector<int>> GA, GB;
vector<char> usedA, usedB;
vector<int> checkA, checkB;
int curA, curB;

void dfs1(int v) {
    usedA[v] = 1;
    checkA[v] = curA;
    for (auto u : GA[v])
        if (!usedA[u])
            dfs1(u);
}

void dfs2(int v) {
    usedB[v] = 1;
    checkB[v] = curB;
    for (auto u : GB[v])
        if (!usedB[u])
            dfs2(u);
}

void solve() {
    GA.clear();
    GB.clear();
    checkA.clear();
    checkB.clear();
    usedA.clear();
    usedB.clear();
    curA = curB = 0;
    int n, m, a, b;
    cin >> n >> m >> a >> b, a--, b--;
    GA.resize(n);
    GB.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        if (v != a && u != a) {
            GA[v].push_back(u);
            GA[u].push_back(v);
        }
        if (v != b && u != b) {
            GB[v].push_back(u);
            GB[u].push_back(v);
        }
    }
    usedA.resize(n);
    usedB.resize(n);
    checkA.resize(n, -1);
    checkB.resize(n, -1);
    for (int i = 0; i < n; i++) {
        if (i == a || i == b)
            continue;
        if (!usedA[i]) {
            dfs1(i);
            curA++;
        }
        if (!usedB[i]) {
            dfs2(i);
            curB++;
        }
    }
    ll ans = 1LL * (n - 2) * (n - 3) / 2;
    vector<ll> szA(curA, 0), szB(curB, 0);
    for (int i = 0; i < n; i++)
        if (i != a && i != b)
            szA[checkA[i]]++;
    for (int i = 0; i < n; i++)
        if (i != a && i != b)
            szB[checkB[i]]++;
    ll bad = 0;
    for (int i = 0; i < curA; i++)
        bad += szA[i] * (szA[i] - 1) / 2LL;
    for (int i = 0; i < curB; i++)
        bad += szB[i] * (szB[i] - 1) / 2LL;
    vector<vector<int>> cmpA(curA);
    for (int i = 0; i < n; i++)
        if (i != a && i != b)
            cmpA[checkA[i]].push_back(i);
    for (int i = 0; i < curA; i++) {
        map<int, ll> mapa;
        for (auto j : cmpA[i])
            mapa[checkB[j]]++;
        for (auto j : mapa)
            bad -= j.second * (j.second - 1) / 2LL;
    }
    //bad >>= 1LL;
    ans -= bad;
    //ans = max(0LL, ans);
    cerr << "ans: ";
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}