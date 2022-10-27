#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,u,v,dis,sz[maxn],d[maxn],root=1,p[maxn],cur_sz;
bool ban[maxn];
vector<int> a[maxn];
void answer(int x){
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
void dfs_dis(int nod,int pa){
    p[nod]=pa;
    for(int i:a[nod]){
        if(i!=pa){
            d[i]=d[nod]+1;
            dfs_dis(i,nod);
        }
    }
    return;
}
bool ancestor(int centroid){
    printf("d %d\n",centroid);
    fflush(stdout);
    int x;scanf("%d",&x);
    if(x==0)answer(centroid);
    if(d[centroid]+x==dis&&x==1){
        printf("s %d\n",centroid);
        fflush(stdout);
        int cute; scanf("%d",&cute);
        answer(cute);
    }
    return d[centroid]+x==dis;
}
void dfs_sz(int nod){
    sz[nod]=1;
    for(int i:a[nod]){
        if(!ban[i]&&i!=p[nod]){
            dfs_sz(i);
            sz[nod]+=sz[i];
            }
    }
    return;
}
int fcentroid(int nod){
    for(int i:a[nod]){
        if(!ban[i]&&i!=p[nod]){
            if(sz[i]>cur_sz/2){
                return fcentroid(i);
            }
        }
    }
    return nod;
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    printf("d 1\n");
    fflush(stdout);
    scanf("%d",&dis);
    dfs_dis(1,0);
    cur_sz=n;
    while(true){
        dfs_sz(root);
        int centroid=fcentroid(root);
        if(ancestor(centroid)){
            printf("s %d\n",centroid);
            fflush(stdout);
            scanf("%d",&root);
            cur_sz=sz[root];
        }
        else{
            ban[centroid]=true;
            cur_sz-=(sz[centroid]);
        }
    }
}