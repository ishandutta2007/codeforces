#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int pa[maxn],sz[maxn],n,m,t,b,u,v,x;
int findpa(int h){
    return h==pa[h]?h:pa[h]=findpa(pa[h]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        pa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        if(t==0)continue;
        scanf("%d",&b);
        int par=findpa(b);
        for(int i=1;i<t;i++){
            scanf("%d",&x);
            v=findpa(x);
            if(v!=par){
            if(sz[par]<sz[v])
                swap(par,v);
            pa[v]=par;
            sz[par]+=sz[v];
        }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",sz[findpa(i)]);
    }
}