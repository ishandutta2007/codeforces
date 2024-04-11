#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const int K = 105;

int n, m, k, s;
int dist[N][K];
int a[N];
vec< int > g[N];
vec< int > ids[K];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d %d", &n, &m, &k, &s);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        a[i]--;
        ids[a[i]].push_back(i);
    }

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill((int*)dist, (int*)dist + N * K, inf);

    for(int x = 0;x < k;x++) {
        queue< int > q;
        for(int ss : ids[x]) {
            q.push(ss);
            dist[ss][x] = 0;
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(dist[to][x] > dist[v][x] + 1) {
                    dist[to][x] = dist[v][x] + 1;
                    q.push(to);
                }
            }
        }
    }

    for(int v = 1;v <= n;v++) {
        nth_element(dist[v], dist[v] + s, dist[v] + k);
        ll res = 0;
        for(int j = 0;j < s;j++) res += dist[v][j];
        printf("%lld ", res);
    }

    printf("\n");

    return 0;
}