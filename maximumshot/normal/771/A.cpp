#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 150005;

int n, m;
vec< int > g[N];
bool used[N];

int cntVertex = 0;
int cntEdge = 0;

void dfs(int v) {
    used[v] = true;
    cntVertex++;
    cntEdge += (int)g[v].size();
    for(int to : g[v]) {
        if(!used[to]) {
            dfs(to);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        cntVertex = 0;
        cntEdge = 0;
        dfs(i);
        if(1ll * cntVertex * (cntVertex - 1) != cntEdge) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}