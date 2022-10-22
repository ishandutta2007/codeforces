#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2005;

int n;
int g[N][N];
int MN = inf;
int mn[N];
ll dist[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j++) {
            scanf("%d", &g[i][j]);
            g[j][i] = g[i][j];
            MN = min(MN, g[i][j]);
        }
    }

    for(int i = 1;i <= n;i++) {
        mn[i] = inf;
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            mn[i] = min(mn[i], g[i][j]);
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            g[i][j] -= MN;
        }
    }

    set< pair< ll, ll > > H;

    for(int i = 1;i <= n;i++) {
        if(mn[i] == MN) {
            dist[i] = 0;
        }else {
            dist[i] = inf64;
        }
        dist[i] = min(dist[i], 2ll * (mn[i] - MN));
        H.insert({dist[i], i});
    }

    while(!H.empty()) {
        int v = H.begin()->second;
        H.erase(H.begin());
        for(int to = 1;to <= n;to++) {
            if(dist[to] > dist[v] + g[v][to]) {
                H.erase({dist[to], to});
                dist[to] = dist[v] + g[v][to];
                H.insert({dist[to], to});
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        cout << 1ll * (n - 1) *  MN + dist[i] << "\n";
    }

    return 0;
}