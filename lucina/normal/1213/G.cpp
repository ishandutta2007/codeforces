#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,pa[maxn],sz[maxn];
int fi(int x){
    return x==pa[x]?x:pa[x]=fi(pa[x]);
}
struct edge{
    int u,v,w;
    bool operator <(const edge &x)const{
        return w<x.w;
    }
    void read(){
        scanf("%d%d%d",&u,&v,&w);
    }
};
edge e[maxn];
vector<pair<int,int>> q;
long long ans[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        e[i].read();
    }
    for(int i=1;i<=n;i++)
        sz[i]=1,pa[i]=i;
    int x;
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        q.push_back({x,i});
    }
    sort(q.begin(),q.end());
    int pt=0;
    long long cur=0;
    sort(e+1,e+n);
   /* for(int i=1;i<n;i++){
        printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
    }*/
    for(int i=1;i<n;i++){
        while(pt<m&&q[pt].first<e[i].w){
            ans[q[pt].second]=cur;
            pt++;
        }
        if(pt==m)break;
        auto z=e[i];
        int u=fi(z.u),v=fi(z.v);
        cur+=(1LL*sz[u]*sz[v]);
        if(sz[u]<sz[v])swap(u,v);
        pa[v]=u;
        sz[u]+=sz[v];
    }
    for(int i=pt;i<m;i++){
        ans[q[i].second]=cur;
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }

}
/*
    RIP Edelgard
*/