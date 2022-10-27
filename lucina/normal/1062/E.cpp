#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,LOG=20;
int n,q,x,tin[maxn],tout[maxn],timer,d[maxn],up[maxn][LOG+1],id[maxn];
int sprase[maxn][22],sprase2[maxn][22],logg[maxn];
vector<int> a[maxn];
void dfs(int nod,int pa){
    timer++;
    tin[nod]=timer;
    id[timer]=nod;
    up[nod][0]=pa;
    for(int i=1;i<=LOG;i++)
        up[nod][i]=up[up[nod][i-1]][i-1];
    for(auto i:a[nod]){
        d[i]=d[nod]+1;
        dfs(i,nod);
    }
    timer++;
    tout[nod]=timer;
    return;
}
bool ancestor(int u,int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int lca(int u,int v){
    if(ancestor(u,v))return u;
    if(ancestor(v,u))return v;
    for(int i=LOG;i>=0;i--){
        if(!ancestor(up[u][i],v))
            u=up[u][i];
    }
    return up[u][0];
}
void sprase_table(){
    for(int i=1;i<=n;i++)
        sprase[i][0]=tin[i],sprase2[i][0]=tin[i];
    for(int j=1;j<=LOG;j++){
        for(int i=1;i+(1<<(j-1))<=n;i++){
            sprase[i][j]=min(sprase[i][j-1],sprase[i+(1<<(j-1))][j-1]);
            sprase2[i][j]=max(sprase2[i][j-1],sprase2[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=2;i<=n;i++)
        logg[i]=logg[i>>1]+1;
    return;
}
int getmin(int l,int r){
    int d=logg[r-l+1];
    return min(sprase[l][d],sprase[r-(1<<d)+1][d]);
}
int getmax(int l,int r){
    int d=logg[r-l+1];
    return max(sprase2[l][d],sprase2[r-(1<<d)+1][d]);
}
int compute(int nod,int l,int r){
    int it,it2;
    if(nod==l) it=getmin(l+1,r),it2=getmax(l+1,r);
    else if(nod==r) it=getmin(l,r-1),it2=getmax(l,r-1);
    else it=min(getmin(l,nod-1),getmin(nod+1,r)),it2=max(getmax(l,nod-1),getmax(nod+1,r));
    return lca(id[it],id[it2]);
}

int main(){
    scanf("%d%d",&n,&q);
    tout[0]=1e9;
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        a[x].push_back(i);
    }
    dfs(1,0);
    sprase_table();
    int l,r,y,tt;
    int u,v;
    while(q--){
        scanf("%d%d",&l,&r);
        x=getmin(l,r);y=getmax(l,r);
        u=compute(id[x],l,r);v=compute(id[y],l,r);
        if(d[u]>=d[v])printf("%d %d\n",id[x],d[u]);
        else printf("%d %d\n",id[y],d[v]);
    }
}