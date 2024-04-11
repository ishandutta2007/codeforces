#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 200010, M = N << 1;
typedef long long LL;
int n, head[N], numE = 0;
LL f[N][2], size[N];
struct Edge{
    int next, to;
}e[M];
void addEdge(int from, int to){
    e[++numE].next = head[from];
    e[numE].to = to;
    head[from] = numE;
}
void dfs_(int u, int fa){
    size[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == fa) continue;
        dfs_(v, u);
        size[u] += size[v];
        f[u][0] += f[v][0];
    }
    f[u][0] += size[u]; 
}
void dfs(int u, int fa){
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == fa) continue;
        f[v][1] = (n - size[v]) + f[u][1] + (f[u][0] - size[u] - f[v][0]);
        dfs(v, u);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs_(1, 0);
    dfs(1, 0);
    LL ans = -1;
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[i][0] + f[i][1] + (n - size[i]));
    printf("%lld\n", ans);
    return 0;
}