#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, m;
int f[N];
int dist[N][3];
vec< int > g[N];
vec< int > rg[N];

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &f[i]);
    }

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for(int t = 1;t <= 2;t++) {
        queue< int > q;
        for(int i = 1;i <= n;i++) {
            if(f[i] == t) {
                dist[i][t] = 0;
                q.push(i);
            }else {
                dist[i][t] = inf;
            }
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(dist[to][t] > dist[v][t] + 1) {
                    dist[to][t] = dist[v][t] + 1;
                    if(f[to] != 1) {
                        q.push(to);
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            g[i] = rg[i];
        }
    }

    for(int i = 1;i <= n;i++) {
        if(dist[i][1] != inf && dist[i][2] != inf) {
            puts("1");
        }else {
            puts("0");
        }
    }

    return 0;
}