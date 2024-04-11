#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=600005;
int n;
ll w[N],f[N],a[N];
struct edge{int to,w;};
vector<edge> G[N];
ll ans=0;
void dfs(int u,int fa){
    f[u]=w[u];
    for(int i=0;i<G[u].size();i++){
        edge e=G[u][i];
        if(e.to==fa) continue;
        dfs(e.to,u);
        f[u]=max(f[u],f[e.to]+w[u]-(ll)e.w);
    }
    int num=0;
    for(int i=0;i<G[u].size();i++){
        edge e=G[u][i];
        if(e.to==fa) continue;
        a[++num]=f[e.to]-e.w;
    }
    ans=max(ans,f[u]);
    if(num>1){
        sort(a+1,a+num+1);
        ans=max(ans,a[num]+a[num-1]+w[u]);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    int a,b,c;
    for(int i=1;i<n;i++) {
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}