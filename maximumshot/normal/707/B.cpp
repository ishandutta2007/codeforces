#include <bits/stdc++.h>

#include <time.h>
#include <random>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    vec< vec< pii > > g(n + 1);

    for(int u, v, l, i = 0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &l);
        g[u].push_back({v, l});
        g[v].push_back({u, l});
    }

    vec< ll > dist(n + 1, inf64);

    for(int x, i = 0;i < k;i++) {
        scanf("%d", &x);
        dist[x] = 0;
    }

    set< pair< ll, int > > q;

    for(int i = 1;i <= n;i++) q.insert({dist[i], i});

    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto iter : g[v]) {
            int to, w;
            tie(to, w) = iter;
            if(dist[to] > dist[v] + w) {
                q.erase({dist[to], to});
                dist[to] = dist[v] + w;
                q.insert({dist[to], to});
            }
        }
    }

    ll res = inf64;

    for(int i = 1;i <= n;i++) {
        if(dist[i] > 0)
            res = min(res, dist[i]);
    }

    if(res == inf64)
        printf("-1\n");
    else
        cout << res << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}