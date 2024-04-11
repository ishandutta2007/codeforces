#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 200005;
const int MaxDim = 200005;

int N;
vector<int> adj[MaxN];
vector<pair<int,int>> pointsX[MaxDim], pointsY[MaxDim];

void input(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        pointsX[x].emplace_back(y, i);
        pointsY[y].emplace_back(x, i);
    }
}

void add_edge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}


bool vis[MaxN];
bool color[MaxN];

void dfs(int v){
    vis[v] = true;
    for(int s : adj[v]){
        if(vis[s]) continue;
        color[s] = !color[v];
        dfs(s);
    }
}

int main(){
    input();
    for(int i = 0; i < MaxDim; i++){
        sort(pointsX[i].begin(), pointsX[i].end());
        for(int j = 0; j < (int)pointsX[i].size()-1; j += 2){
            add_edge(pointsX[i][j].second, pointsX[i][j+1].second);
        }

        sort(pointsY[i].begin(), pointsY[i].end());
        for(int j = 0; j < (int)pointsY[i].size()-1; j += 2){
            add_edge(pointsY[i][j].second, pointsY[i][j+1].second);
        }
    }

    for(int i = 0; i < N; i++){
        if(!vis[i]) dfs(i);
    }

    for(int i = 0; i < N; i++){
        if(color[i]) printf("b"); else printf("r");
    }
    printf("\n");
}