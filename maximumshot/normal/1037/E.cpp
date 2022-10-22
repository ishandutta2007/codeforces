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

int n, m, k;
set< int > g[N];
set< pii > q;
int del[N];
pii edge[N];
int res[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &k);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].insert(v);
        g[v].insert(u);
        edge[i] = {u, v};
    }

    for(int v = 1;v <= n;v++) {
        q.insert({(int)g[v].size(), v});
    }

    for(int iter = m - 1;iter >= 0;iter--) {
        while(!q.empty() && q.begin()->first < k) {
            int v = q.begin()->second;
            q.erase(q.begin());
            del[v] = 1;
            for(int to : g[v]) {
                if(del[to]) continue;
                q.erase({(int)g[to].size(), to});
                g[to].erase(v);
                q.insert({(int)g[to].size(), to});
            }
        }
        res[iter] = (int)q.size();
        int u, v;
        tie(u, v) = edge[iter];
        if(!del[u] && !del[v]) {
            q.erase({(int)g[u].size(), u});
            q.erase({(int)g[v].size(), v});
            g[u].erase(v);
            g[v].erase(u);
            q.insert({(int)g[u].size(), u});
            q.insert({(int)g[v].size(), v});
        }
    }

    for(int i = 0;i < m;i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}