#include <bits/stdc++.h>
using namespace std;
const int mxN=2e5+5;
struct edge{
    int u,v,w;
}edges[mxN];
int p[mxN],sz[mxN];
int set_of(int x){
    return x==p[x]?x:p[x]=set_of(p[x]);
}
void union_(int u,int v){
    int x=set_of(u),y=set_of(v);
    if(x==y)return;
    if(sz[x]>sz[y])swap(x,y);
    p[x]=y;
    sz[y]+=sz[x];
}
void eat(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>edges[i].u>>edges[i].v>>edges[i].w;
    int ans=(1<<30)-1;
    for(int i=29;i>=0;i--){
        ans^=(1<<i);
        for(int j=1;j<=n;j++){
            sz[j]=1;
            p[j]=j;
        }
        for(int j=1;j<=m;j++){
            if((edges[j].w&ans)==edges[j].w)union_(edges[j].u,edges[j].v);
        }
        if(sz[set_of(1)]!=n)ans^=(1<<i);
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}