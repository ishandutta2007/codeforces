#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int const nax = 2e5 + 10;
int const inf = 1e9;
vector<int> a[nax];
int n, m;

ll p[nax];

void bfs (int start, int * dist) {
    static int q[nax];
    int topQ = 0;
    q[topQ ++] = start;

    fill(dist + 1, dist + 1 + n, inf);
    dist[start] = 0;

    for (int i = 0 ; i < topQ ; ++ i) {
        int u = q[i];

        for (int x : a[u]) {
            if (dist[u] + 1 < dist[x]) {
                dist[x] = dist[u] + 1;
                q[topQ ++] = x;
            }
        }
    }
}

int dist[3][nax];

ll solve () {

    int x, y, z;

    scanf("%d %d %d %d %d", &n, &m, &x, &y, &z);

    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%lld", p + i);
    }


    for (int i = 1 ; i <= m ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }


    sort(p + 1, p + 1 + m);

    for (int i = 2 ; i <= m ; ++ i)
        p[i] += p[i - 1];

    bfs(x, dist[0]);
    bfs(y, dist[1]);
    bfs(z, dist[2]);

    ll ans = LLONG_MAX;

    for (int t = 1 ; t <= n ; ++ t) {
        int d = dist[0][t] + dist[2][t];
        int ret = dist[1][t];

        ll res = 0;
        res += 2LL * p[ret];
        res += p[ret + d] - p[ret];

        if (ret + d <= min(n, m))
        ans = min(ans, res);

    }

    return ans;
}

int main () {
    int T;

    for (scanf("%d", &T); T -- ; ) {
        printf("%lld\n", solve());

        for (int i = 1 ; i <= n ; ++ i)
            a[i].clear();
    }
}