#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10, inf = 1e9 + 7;

int n, a[nax], dis[nax];
vector<int> g[nax];
bool vis[nax];
vector<int> b[nax];
void bfs(){
    queue<int> q;
    for(int i = 1 ;i <= n; i ++){
        if(dis[i] != inf){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i: g[top]){
            if(dis[top] + 1 < dis[i]){
                dis[i] = dis[top] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n; i ++){
        scanf("%d", &a[i]);
        dis[i] = inf;
    }
    for(int i = 1 ;i <= n; i ++){
        int to = i + a[i];
        if(to <= n){
            if((a[to] ^ a[i]) & 1) dis[i] = 1;
            else g[to].push_back(i);
        }
        to = i - a[i];
        if(to >= 1){
            if((a[to] ^ a[i]) & 1) dis[i] = 1;
            else g[to].push_back(i);
        }
    }
    bfs();
    for(int i = 1 ;i <= n ;i ++){
        printf("%d ", dis[i] >= inf ? -1 : dis[i]);
    }
}