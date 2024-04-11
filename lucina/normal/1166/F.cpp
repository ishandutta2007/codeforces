#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,q,pa[maxn],sz[maxn],c;
#define merge fkdsffsdfsdf
map<int,int> adj[maxn];
set<int> nei[maxn];
int fi(int h){
    return h==pa[h]?h:pa[h]=fi(pa[h]);
}
void merge(int x,int y){
    x=fi(x);y=fi(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    sz[x]+=sz[y];pa[y]=x;
    for(auto it=nei[y].begin();it!=nei[y].end();it++)
        nei[x].insert(*it);
    return;
}
void add_edge(){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    nei[fi(u)].insert(v);nei[fi(v)].insert(u);
    if(adj[u].find(w)!=adj[u].end())merge(v,adj[u][w]);
    else adj[u][w]=v;
    if(adj[v].find(w)!=adj[v].end())merge(u,adj[v][w]);
    else adj[v][w]=u;
    return;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&c,&q);
    for(int i=1;i<=n;i++){
        pa[i]=i;sz[i]=1;
    }
    while(m--){
        add_edge();
    }
    char s[2];
    while(q--){
        scanf("%s",s);
        if(s[0]=='+'){
            add_edge();
        }
        else{
            int x,y;scanf("%d%d",&x,&y);
            if(fi(x)==fi(y)) printf("Yes\n");
            else if(nei[fi(x)].find(y)!=nei[fi(x)].end())printf("Yes\n");
            else printf("No\n");
        }

    }

}