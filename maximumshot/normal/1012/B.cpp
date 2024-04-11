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

const int N = 2e5 + 5;

int n, m, q;
pii pt[N];
vec< int > xs[N], ys[N];
int ux[N], uy[N];
int used[N];
vec< int > g[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 1;i <= q;i++) {
        scanf("%d %d", &pt[i].first, &pt[i].second);
        xs[pt[i].first].push_back(i);
        ys[pt[i].second].push_back(i);
        ux[pt[i].first] = 1;
        uy[pt[i].second] = 1;
    }

    int res = count(ux + 1, ux + n + 1, 0) + count(uy + 1, uy + m + 1, 0);

    for(int x = 1;x <= n;x++) {
        for(int iter = 0;iter + 1 < (int)xs[x].size();iter++) {
            int u = xs[x][iter];
            int v = xs[x][iter + 1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    for(int y = 1;y <= m;y++) {
        for(int iter = 0;iter + 1 < (int)ys[y].size();iter++) {
            int u = ys[y][iter];
            int v = ys[y][iter + 1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    for(int i = 1;i <= q;i++) {
        if(used[i]) continue;
        res++;
        queue< int > que;
        que.push(i);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(int to : g[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    que.push(to);
                }
            }
        }
    }

    printf("%d\n", res - 1);

    return 0;
}