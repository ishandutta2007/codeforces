#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,u,v,w,pa[maxn],sz[maxn],ans,c;
struct edge{
    int x,y,z;
    bool operator<(const edge d){
        return z<d.z;
    }
}e[maxn];
int findpa(int h){
    return h==pa[h]?h:pa[h]=findpa(pa[h]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    }
    for(int i=1;i<=n;i++)
        pa[i]=i,sz[i]=1;
    sort(e+1,e+m+1);
    int j;
    for(int i=1;i<=m;i++){
        j=i;
        while(e[j].z==e[i].z&&j<=m){
            j++;
        }
        j--;
        for(int k=i;k<=j;k++){
            if(findpa(e[k].x)!=findpa(e[k].y))
            ans++;
        }
        for(int k=i;k<=j;k++){
            u=findpa(e[k].x);
            v=findpa(e[k].y);
            if(u!=v){
                ans--;
                if(sz[u]<sz[v])swap(u,v);
                sz[u]+=sz[v];
                pa[v]=u;
            }
        }
        i=j;
    }
    printf("%d\n",ans);
}