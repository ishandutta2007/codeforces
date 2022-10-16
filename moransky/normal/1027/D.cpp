#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;
const int N = 200010;
int n, c[N], a[N], ans;
bool st[N], vis[N];
vector<int> G[N], edge, val;

void dfs(int u){
    if(vis[u]){
        val.push_back(u);
        while(edge.size() && edge.back() != u)
            val.push_back(edge.back()), edge.pop_back();
        return ;
    }
    vis[u] = true, edge.push_back(u), dfs(a[u]);
}
void mark(int u){
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!st[v]) st[v] = true, mark(v);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        G[i].push_back(a[i]);
        G[a[i]].push_back(i);
    } 
    for(int i = 1 ; i <= n; i++){
        if(!st[i]){
            val.clear(); edge.clear();
            dfs(i);
            int res = INT_MAX;
            for(int i = 0; i < val.size(); i++)
                res = min(res, c[val[i]]);
            ans += res;
            st[i] = true, mark(i);
        }
    }
    printf("%d", ans);
    return 0;
}