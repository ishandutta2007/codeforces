#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const long long inf=1e18;
int n,w[maxn],u,v,b,up[maxn][21];
long long ans;
vector<vector<int>> a;
void dfs(int nod,int pa){
    up[nod][0]=pa;
    for(int i=1;i<20;i++)
        up[nod][i]=up[up[nod][i-1]][i-1];
        long long s=inf;
        int j;
    for(j=0;j<20&&up[nod][j];j++){
        if(up[nod][j]){
            s=min(s,1ll*(j+1)*w[up[nod][j]]+w[nod]);
        }
    }
    s=min(s,1ll*(j+1)*w[b]+w[nod]);
    if(nod!=b)
        ans+=s;
    for(int i:a[nod]){
        if(i!=pa)
            dfs(i,nod);
    }
    return;
}
int main(){
    scanf("%d",&n);
    a.resize(n+1);
    int mi=1e9+21;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]<mi){
            mi=w[i];
            b=i;
        }
        }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(b,0);
    printf("%lld\n",ans);
}