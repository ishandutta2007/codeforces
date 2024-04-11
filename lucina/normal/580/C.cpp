#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn],x,y,t;
long long ans;
vector<int> f[maxn];

void dfs(int v,int s,int k){
    if(k>m)
        return;
        t=1;
    for(int i=0;i<f[v].size();i++){
        if(f[v][i]!=s){
            dfs(f[v][i],v,k*a[f[v][i]]+a[f[v][i]]);
        t=0;
        }
    }
    ans+=t;
}



int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        f[x].push_back(y);
        f[y].push_back(x);
    }
    dfs(0,-1,a[0]);
    printf("%lld\n",ans);
}