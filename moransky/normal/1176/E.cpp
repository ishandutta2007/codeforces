#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200010;
int n, m, head[N], numE = 0, color[N], cnt;
struct Edge{
    int next, to;
}e[N << 1];
void addEdge(int from, int to){
    e[++numE].next = head[from];
    e[numE].to = to;
    head[from] = numE;
}
void dfs(int u, int c){
    color[u] = c;
    if(c == 0) cnt++;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(color[v] == -1) dfs(v, c ^ 1);
    }
}
int main(){
    memset(color, -1, sizeof color);
    int T; scanf("%d", &T);
    while(T--){
        cnt = numE = 0;
        scanf("%d%d", &n, &m);
        
        for(int i = 1; i <= m; i++){
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v); addEdge(v, u);
        }
        dfs(1, 0);
        int v = 0;
        if(cnt > n - cnt) v = 1;
        printf("%d\n", min(cnt, n - cnt));
        for(int i = 1; i <= n; i++) 
            if(color[i] == v) printf("%d ", i);
        puts("");
        
        for(int i = 1; i <= n; i++) color[i] = -1, head[i] = 0;
    }
    return 0;
}