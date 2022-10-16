#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200010, M = N << 1;
int n, m, head[N], numE = 1, vis[N];
bool flag = true, st[N];
struct Edge{
    int from, next, to;
}e[M];
void addEdge(int from, int to){
    e[++numE].next = head[from];
    e[numE].to = to;
    e[numE].from = from;
    head[from] = numE;
}
bool inline check(int u, int edge){
    for(int i = head[u]; i; i = e[i].next){
        if((i >> 1) != edge && st[i >> 1] == u)
            return false;
    }
    return true;
}
bool inline check2(int u, int edge){
    for(int i = head[u]; i; i = e[i].next){
        if((i >> 1) != edge && st[i >> 1] == e[i].to)
            return false;
    }
    return true;
}
bool dfs(int u, int fa, int c){
    vis[u] = c;
    st[u] = true;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == fa) continue;
        if(!st[v]) {
            if(!dfs(v, u, c ^ 1)) return false;

        } else {
            if(vis[u] == vis[v]) return false;
        }
    }
    return true;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    if(!dfs(1, -1, 0)) puts("NO");
    else{ 
        puts("YES");
        for(int i = 1; i <= m; i++) {
           printf("%d", vis[e[i << 1].from]);
        }
    }
    return 0;
}