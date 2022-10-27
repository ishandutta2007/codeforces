#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 10 ;
set<int> a[maxn];
int n, m;
set<int> go;
bool vis[maxn];
void dfs(int i){
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        vector<int> todel;
        for(auto it:go){
            if(a[top].count(it) || vis[it]) continue;
            todel.push_back(it);
            q.push(it);
            vis[it] = true;
        }
        for(int i:todel){
            go.erase(go.find(i));
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int u, v;
    while(m -- ){
        scanf("%d %d", &u, &v);
        a[u].insert(v);
        a[v].insert(u);
    }
    for(int i = 1 ;i <=  n; i++)
        go.insert(i);
    int ans = 0;
    for(int i = 1 ;i <= n ;i ++){
        if(!vis[i]){
            ans ++;
            dfs(i);
        }
    }
    printf("%d\n", ans - 1);
}