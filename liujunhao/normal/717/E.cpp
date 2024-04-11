#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000;
const int MAXM = 200000;
struct node{
    int v;
    node *next;
}Edges[MAXM*2+10], *ecnt=Edges, *adj[MAXN+10];
int sum[MAXN+10], col[MAXN+10];
void addedge(int u, int v){
    ++ecnt;
    ecnt->v = v;
    ecnt->next = adj[u];
    adj[u] = ecnt;
}
void dfs_pre(int u, int fa){
    sum[u] = int(col[u] == -1);
    for(node *p=adj[u];p;p=p->next){
        if(p->v == fa)
            continue;
        dfs_pre(p->v, u);
        sum[u] += sum[p->v];
    }
}
bool dfs(int u, int fa){
    int change = int(fa != 0);
    for(node *p=adj[u];p;p=p->next){
        if(!sum[p->v] || p->v == fa)
            continue;
        printf(" %d", p->v);
        change ^= dfs(p->v, u);
        printf(" %d", u);
    }
    if(change) col[u] = -col[u];
    if(col[u] == -1 && u != 1){
        printf(" %d %d", fa, u);
        return 0;
    }
    return 1;
}
int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &col[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    dfs_pre(1, 0);
    printf("%d", 1);
    dfs(1, 0);
    if(col[1] != 1){
        for(node *p=adj[1];p;p=p->next){
            if(col[p->v] == 1){
                printf(" %d %d %d", p->v, 1, p->v);
                return 0;
            }
        }
    }

    return 0;
}