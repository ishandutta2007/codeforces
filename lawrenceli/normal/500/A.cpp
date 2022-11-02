#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300100;

int n, t, a[MAXN], vis[MAXN];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    dfs(cur+a[cur]);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n >> t;
    for (int i=1; i<=n-1; i++) cin >> a[i];
    dfs(1);
    if (vis[t]) cout << "YES\n";
    else cout << "NO\n";
}