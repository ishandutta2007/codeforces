#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>G[100000],_G[100000];
int cat[100000];
int depth[100000];
void getDepth(int v=0,int p=-1,int d=0){
    depth[v]=d;
    for(int i=0;i<_G[v].size();i++){
        int to=_G[v][i];
        if(to==p)continue;
        getDepth(to,v,d+1);
    }
}
bool visited[100000];
void dfs(int v=0,int renzoku=0){
    if(cat[v])renzoku++;
    else renzoku=0;
    if(renzoku>m)return;
    visited[v]=true;

    for(int i=0;i<G[v].size();i++){
        dfs(G[v][i],renzoku);
    }

}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&cat[i]);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        _G[a].push_back(b);
        _G[b].push_back(a);
    }
    getDepth();

    for(int i=0;i<n;i++){
        for(int j=0;j<_G[i].size();j++){
            int to=_G[i][j];
            if(depth[i]<depth[to])G[i].push_back(to);
        }
    }

    dfs();


    int ans=0;
    for(int i=0;i<n;i++){
        if(G[i].size()||visited[i]==false)continue;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}