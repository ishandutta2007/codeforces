#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+100;
int n,u,v,vis[maxn],m,q;
vector<int> a[maxn];
void dfs(int nod){
    vis[nod]=true;
    for(auto i:a[nod]){
        if(!vis[i]){
            dfs(i);
        }
    }
    return;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&u,&v);
        v+=(n);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans=-1;
    for(int i=1;i<=m+n;i++){
        if(!vis[i]){
                dfs(i);
        ans++;
        }
    }
    printf("%d\n",ans);
}