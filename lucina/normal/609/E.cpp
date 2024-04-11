/*
Minimum spanning tree for each edge

List of my favorite MST problem so far

Make it connected
Maximum distance
MST unification
Minimum spanning tree for each edge

They are all from CF.
In fact, I solve only 4 MST problems so far.
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,LOG=18;
struct edge{
int u;
int v;
int w;
int pos;
bool operator<(const edge &Man_iCuL)const{
    return w<Man_iCuL.w;
}
};
vector<edge> e;
int n,m,x,y,z,pa[maxn],sz[maxn],tin[maxn],tout[maxn],timer,up[19][maxn],f[19][maxn];
bool c[maxn];
long long sum,ans[maxn];
vector<pair<int,int>> a[maxn];
int findpa(int s){
    return s==pa[s]?s:pa[s]=findpa(pa[s]);
}
void dfs(int nod,int pa,int sent){
    ++timer;
    tin[nod]=timer;
    up[0][nod]=pa;
    f[0][nod]=sent;
    for(int i=1;i<=LOG;i++){
    up[i][nod]=up[i-1][up[i-1][nod]];
    f[i][nod]=max(f[i-1][nod],f[i-1][up[i-1][nod]]);
    }
    for(auto i:a[nod]){
        if(i.first!=pa)
            dfs(i.first,nod,i.second);
    }
    ++timer;
    tout[nod]=timer;
    return ;
}
bool ancestor(int u,int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int lca(int u,int v){
    if(ancestor(u,v))
        return u;
    if(ancestor(v,u))
        return v;
    for(int i=LOG;i>=0;i--){
        if(!ancestor(up[i][u],v))
            u=up[i][u];
    }
    return up[0][u];
}
int jump(int u,int v){
    int ma=0;
    for(int i=LOG;i>=0;i--){
        if(ancestor(v,up[i][u])){
            ma=max(ma,f[i][u]);
            u=up[i][u];
            }
    }
    return ma;
}

int main(){
    tin[0]=0;
    tout[0]=1e9;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        pa[i]=i;sz[i]=1;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        e.push_back(edge{x,y,z,i});
    }
    sort(e.begin(),e.end());
    for(int j=0;j<m;j++){
        auto i=e[j];
        x=findpa(i.u);y=findpa(i.v);
        if(x==y){
            continue;
        }
        else{
            if(sz[x]>sz[y]){
                sz[x]+=sz[y];
                pa[y]=x;
            }
            else{
                sz[y]+=sz[x];
                pa[x]=y;
            }
            a[i.u].push_back(make_pair(i.v,i.w));
            a[i.v].push_back(make_pair(i.u,i.w));
            sum+=(i.w);
            c[j]=true;
        }
        }
    dfs(1,0,0);
    for(int i=0;i<m;i++){
        if(c[i]){
            ans[e[i].pos]=sum;
            continue;
        }
        else{
            x=lca(e[i].u,e[i].v);
            y=max(jump(e[i].u,x),jump(e[i].v,x));
            ans[e[i].pos]=sum-y+e[i].w;
        }
    }
    for(int i=0;i<m;i++){
        printf("%lld\n",ans[i]);
    }
}