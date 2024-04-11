#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
vector<int> a[maxn];
bool d[maxn],vis[maxn],ok;
void topsort(int nod){
    vis[nod]=true;
    d[nod]=true;
    for(int i:a[nod]){
        if(!vis[i]){
            topsort(i);
        }
        else if(d[i]){
            ok=false;
        }
    }
    d[nod]=false;
//    topo.push_back(nod);
}
vector<pair<int,int>> e;
int n,m,u,v,ans[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        e.push_back({u,v});
    }
    ok = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            topsort(i);
        }
    }
    if (ok){
        printf("1\n");
        for(int i=1;i<=m;i++){
            printf("%d ",1);
        }
        return 0;
    }
    else{
        /// if in cycle it's increasing
        /// then finally it's going down
        /// so just color them like min -> max
        printf("2\n");
        for(auto j:e){
            printf("%d ",j.first<j.second?1:2);
        }
    }
}