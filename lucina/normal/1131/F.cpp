#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a,b,pa[maxn],u,v,sz[maxn];
vector<int> c[maxn];
int getpa(int x){
    if(x!=pa[x]) pa[x]=getpa(pa[x]);
    return pa[x];
}

void dfs(int x){
    printf("%d ",x);
    for(auto i:c[x])
        dfs(i);
    return ;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        pa[i]=i;
        sz[i]=1;
    }
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        u=getpa(a);v=getpa(b);;
        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        pa[v]=u;
        c[u].push_back(v);
    }
    dfs(getpa(1));

}