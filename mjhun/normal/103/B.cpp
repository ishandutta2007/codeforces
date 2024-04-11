#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[128];
bool vis[128];
int n,m;

void dfs(int x){
    if(vis[x])return;
    vis[x]=true;
    int i;
    for(i=0;i<graph[x].size();++i){
        dfs(graph[x][i]);
    }
}

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;++i){
        int a,b;
        scanf("%d %d",&a,&b);a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0);

    bool r=true;
    for(i=0;i<n;++i){
        r=r&&vis[i];
    }

    if(r&&n==m){
        puts("FHTAGN!");
    }

    else{
        puts("NO");
    }

    return 0;
}