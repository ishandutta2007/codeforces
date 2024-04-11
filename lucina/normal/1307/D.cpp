#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10 ;
int const inf = 1e9 ;
vector<int> a[nax];
int n, m, b[nax], k;
bool sp[nax];



void bfs (int start, int * dist) {
    /// sigh it's unweighted ...
    fill(dist + 1 , dist + 1 + n, inf);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int i : a[x]) {
            if (dist[i] > dist[x] + 1) {
                q.push(i);
                dist[i] = dist[x] + 1;
            }
        }
    }
}
int dist[2][nax];

int main () {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1 ; i <= k ; ++ i) {
        scanf("%d", b + i);
    }
    for (int i = 1 ; i <= m ; ++ i ) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    bfs(1, dist[0]);
    bfs(n, dist[1]);

    sort(b + 1 ,  b + 1 + k , [&](int u, int v) {
        return dist[1][u] - dist[0][u] > dist[1][v] - dist[0][v];
        });

    int ma = 0, ans = 0;
    for (int i = 1 ; i <= k ; i ++) {
        if (i == 1) {
            ma = max (ma, dist[0][b[i]]);
            continue;
        }
        ans = max(ans, ma + dist[1][b[i]] + 1);
        ma = max(ma, dist[0][b[i]]);
    }

    printf("%d\n", min(ans, dist[0][n]));
}
/*
    Good Luck
        -Lucina
*/