#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e5 + 10;
vector < pair < int, long long >  > g[maxN];
int a[maxN];
int pr[maxN];
bool used[maxN];
void dfs(int v, long long sum = 0, long long mn = 0) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].first;
        long long cost = g[v][i].second;
        if (used[to]) continue;
        long long sum1 = sum + cost;
        long long mn1 = min(mn, sum1);
        if (sum1 - a[to] > mn1) continue;
        else dfs(to, sum1, mn1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= (n - 1); i++) {
        int x;
        long long c;
        cin >> x;
        cin >> c;
        g[x].push_back(make_pair(i + 1, c));
        g[i + 1].push_back(make_pair(x, c));
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i]) ans++;
    }
    cout << n - ans;
    return 0;
}