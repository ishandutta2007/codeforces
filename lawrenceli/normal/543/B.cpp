#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int n, m, s1, t1, l1, s2, t2, l2, d[MAXN][MAXN];
vector<int> adj[MAXN];

void bfs(int s) {
    queue<int> que;
    que.push(s); d[s][s] = 0;
    for (int t=0; que.size(); t++) {
        int sze = que.size();
        for (int i=0; i<sze; i++) {
            int x = que.front(); que.pop();
            for (int y : adj[x])
                if (d[s][y] == -1)
                    d[s][y] = t+1, que.push(y);
        }
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--, t1--, s2--, t2--;
    memset(d, -1, sizeof(d));
    for (int i=0; i<n; i++) bfs(i);

    int ans = -1;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            int x = min(d[s1][i]+d[i][j]+d[j][t1], d[s1][j]+d[j][i]+d[i][t1]);
            int y = min(d[s2][i]+d[i][j]+d[j][t2], d[s2][j]+d[j][i]+d[i][t2]);
            if (x<=l1 && y<=l2) ans = max(ans, m-x-y+d[i][j]);
        }

    if (d[s1][t1] <= l1 && d[s2][t2] <= l2)
        ans = max(ans, m-d[s1][t1]-d[s2][t2]);

    cout << ans;
}