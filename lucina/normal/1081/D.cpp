#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,k,sz[maxn],w,r[maxn],u,v,pa[maxn],ans;
struct edge{
int x;
int y;
int a;
    bool operator <(const edge d){
    return a<d.a;
    }
};
vector<edge> b;
int findpa(int x){
    return x==pa[x]?x:pa[x]=findpa(pa[x]);
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=k;i++){
        scanf("%d",&u);
        r[u]=1;
        sz[u]=1;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        b.push_back({u,v,w});
    }
    sort(b.begin(),b.end());
    int t=k,pt=0;
    while(t){
        u=findpa(b[pt].x);
        v=findpa(b[pt].y);
        if(u==v){
            pt++;
            continue;
        }
        if(sz[u]+sz[v]==k){
            for(int i=1;i<=k;i++){
                printf("%d ",b[pt].a);
            }
            return 0;
        }
        pa[v]=u;
        sz[u]+=sz[v];
        pt++;
    }
}