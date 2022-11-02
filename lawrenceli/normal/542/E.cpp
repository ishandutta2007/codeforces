#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 100100;

int n, m, vis[MAXN], cmp[MAXN], cnt, ma[MAXN];
int que[MAXM], l, r;
vector<int> adj[MAXN];

void dfs(int cur, int c) {
    cmp[cur] = cnt;
    if (vis[cur] && vis[cur] != c) {
        cout << -1;
        exit(0);
    }
    if (vis[cur]) return;
    vis[cur] = c;

    for (int i : adj[cur])
        dfs(i, c==1?2:1);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<n; i++)
        if (!vis[i])
            dfs(i, 1), cnt++;

    for (int i=0; i<n; i++) {
        memset(vis, 0, sizeof(vis));
        l = r = 0;
        que[r++] = i;
        int t = 0;
        for (; l != r; t++) {
            int sze = r-l;
            for (int j=0; j<sze; j++) {
                int x = que[l++];
                if (vis[x]) continue;
                vis[x] = 1;
                for (int k : adj[x]) if (!vis[k])
                    que[r++] = k;
            }
        }
        ma[cmp[i]] = max(ma[cmp[i]], t-1);
    }

    int ans = 0;
    for (int i=0; i<cnt; i++) ans += ma[i];
    cout << ans;
}