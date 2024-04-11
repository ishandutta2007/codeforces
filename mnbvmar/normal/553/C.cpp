#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N, M;
const int MaxN = 100005;

vector<int> adj[MaxN];
vector<bool> adjGood[MaxN];

void input(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjGood[a].push_back(c==1);
        adjGood[b].push_back(c==1);
    }
}

bool vis[MaxN];
bool color[MaxN];

bool dfs(int v){
    vis[v] = true;
    for(int i = 0; i < (int)adj[v].size(); i++){
        int s = adj[v][i];
        bool good = adjGood[v][i];

        if(vis[s]){
            if((color[s] ^ (!good)) != color[v]) return false;
        } else {
            color[s] = (color[v] ^ (!good));
            if(!dfs(s)) return false;  // argh.
        }
    }
    return true;
}

int main(){
    input();
    int result = 1;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            if(i != 1)
                result = (result * 2) % 1000000007;
            if(!dfs(i)){ printf("0\n"); return 0; }
        }
    }

    printf("%d\n", result);
}