#pragma pack(1)

#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
int n;
const int maxN = (1 << 17) + 10;
vector<pair<int,int>> g[maxN];
int id[maxN];
int h[maxN];
void dfs(int v, int p) {
    for (auto to : g[v]) {
        if (to.first == p) continue;
        h[to.first] = h[v] ^ 1;
        id[to.second] = to.first;
        dfs(to.first, v);
    }
}
int ans[maxN];
int ansE[maxN];
int main()
{
    int tst;
    cin >> tst;
    while (tst--) {
        int p;
        cin >> p;
        int n = (1 << p);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v, i);
            g[v].emplace_back(u, i);
        }
        dfs(1, -1);
        cout << 1 << '\n';
        ans[1] = (1 << p);
        for (int i = 1; i < n; i++) {
            ansE[i] = (1 << p) + i;
            ans[id[i]] = i;
            if (!(h[id[i]] & 1)) {
                swap(ansE[i], ans[id[i]]);
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << '\n';
        for (int i = 1; i < n; i++) cout << ansE[i] << " ";
        cout << '\n';
        
    }
}