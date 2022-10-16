#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;

const int N = 300010, M = 300010;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, numE = 1, head[N], fa[N], faEdge[N];
bool vis[N];
vector<int> G[N], ans;
LL dis[N];
priority_queue<PLI, vector<PLI>, greater<PLI> > q;
queue<int> Q;
struct Edge{
    int next, to;
    LL dis;
}e[M << 1];
void addEdge(int from, int to, int dis){
    e[++numE].next = head[from];
    e[numE].to = to;
    e[numE].dis = dis;
    head[from] = numE;
}
void Dijkstra(){
    memset(dis, 0x3f, sizeof dis);
    
    q.push(make_pair(0, 1)); dis[1] = 0;
    while(!q.empty()){
        PLI u = q.top(); q.pop();
        if(vis[u.second]) continue;
        vis[u.second] = true;
        for(int i = head[u.second]; i; i = e[i].next){
            int v = e[i].to;
            if(dis[u.second] + e[i].dis < dis[v]){
                dis[v] = dis[u.second] + e[i].dis;
                fa[v] = u.second, faEdge[v] = i >> 1;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}
void Bfs(){
    
    Q.push(1);
    while((!Q.empty()) && k > 0){
        int u = Q.front(); Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i]; k--;
            ans.push_back(faEdge[v]);
            Q.push(v);
            if(!k) return; 
        }
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w); addEdge(v, u, w);
    }
    Dijkstra();
    for(int i = 1; i <= n; i++)  
        if(fa[i]) G[fa[i]].push_back(i);
    Bfs();
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}