#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 207;
const int M = 1507;
const int inf = INT_MAX;

int nx[M], to[M], head[N], cap[M], fl[M], who[N][N], vis[N], es = 2;
int a[N], b[N];
int n, m, s, t, turn = 1;

int dfs(int u, int mini) {
    vis[u] = turn;
    if(u == t) return mini;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(vis[v] != turn && cap[e]-fl[e]) {
            int k = dfs(v,min(mini,cap[e]-fl[e]));
            if(k != inf){
                fl[e] += k;
                fl[e^1] -= k;
                return k;
            }
        }
    }
    return inf;
}

int maxflow(){
    int mf = 0, k;
    while((k = dfs(s,inf)) != inf){
        turn++;
        mf += k;
    }
    return mf;
}

int addedge(int u, int v, int _cap){
    who[u][v] = es;
    to[es] = v; nx[es] = head[u]; head[u] = es; cap[es] = _cap; fl[es++] = 0;
    to[es] = u; nx[es] = head[v]; head[v] = es; cap[es] = 0; fl[es++] = 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    for(int i = 0; i < n; i++) scanf("%d",b+i);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u,&v); u--; v--;
        addedge(u,v+n,inf);
        addedge(v,u+n,inf);
    }
    s = 2*n;
    t = 2*n+1;
    int sa = 0, sb = 0;
    for(int i = 0; i < n; i++) {
        sa += a[i];
        sb += b[i];
        addedge(i,i+n,inf);
        addedge(s,i,a[i]);
        addedge(i+n,t,b[i]);
    }
    int res = maxflow();
    if(res == sa && res == sb) {
        printf("YES\n");
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                printf("%d%c",fl[who[i][j+n]]," \n"[j==n-1]);
    } else puts("NO");
}