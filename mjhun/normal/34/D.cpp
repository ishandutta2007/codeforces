#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[50005];
int n,r1,r2;
int prev[50005];

void dfs(int v){
    int i;
    for(i=0;i<graph[v].size();++i){
        int s=graph[v][i];
        if(prev[s]==-1){
            prev[s]=v;
            dfs(s);
        }
    }
}

int main(){
    int i;
    scanf("%d %d %d",&n,&r1,&r2);r1--;r2--;
    for(i=0;i<n;++i){
        if(i==r1)continue;
        int p;
        scanf("%d",&p);p--;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
    memset(prev,-1,sizeof(prev));
    prev[r2]=0;
    dfs(r2);
    for(i=0;i<n;++i){
        if(i==r2)continue;
        printf("%d ",prev[i]+1);
    }
    putchar('\n');
    return 0;
}