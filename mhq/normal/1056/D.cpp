#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int leaf[maxN];
int n;
vector < int > g[maxN];
void dfs(int v) {
    if (g[v].size() == 0) leaf[v] = 1;
    for (int to : g[v]) {
        dfs(to);
        leaf[v] += leaf[to];
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1);
    sort(leaf + 1, leaf + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << leaf[i] << " ";
    }
    return 0;
}