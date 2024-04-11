// binlift?
// idk am i overcomplicating this?

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=4e5+5,lg=18;
vector<int> adj[mxN];
int dep[mxN],ans[mxN],st[lg][mxN];
void dfs(int u,int v){
    dep[u]=v;
    for(auto i:adj[u])dfs(i,v+1);
}
signed main(){
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    for(int i=0,x;i<n;i++){
        cin>>x;
        mp[i]=x;
    }
    memset(st,-1,sizeof st);
    int idx[m+1];
    for(int i=1;i<=m;i++)idx[i]=i;
    for(int i=1,u,v;i<m;i++){
        cin>>u>>v;
        int x=m+i;
        adj[x].push_back(idx[u]);
        adj[x].push_back(idx[v]);
        st[0][idx[u]]=st[0][idx[v]]=x;
        idx[u]=x;
    }
    dfs(m*2-1,0);
    for(int i=1;i<lg;i++){
        for(int j=1;j<2*m;j++){
            if(st[i-1][j]!=-1)st[i][j]=st[i-1][st[i-1][j]];
        }
    }
    for(int i=0;i<n-1;i++){
        int u=mp[i],v=mp[i+1];
        if(u==v)continue;
        if(dep[u]<dep[v])swap(u,v);
        for(int j=0;j<lg;j++){
            if((dep[u]-dep[v])&(1<<j))u=st[j][u];
        }
        if(u!=v){
            for(int j=lg-1;j>=0;j--){
                if(st[j][u]!=-1&&st[j][u]!=st[j][v]){
                    u=st[j][u];
                    v=st[j][v];
                }
            }
        }
        int z=u;
        if(u!=v)z=st[0][u];
        ans[z-m]++;
    }
    for(int i=m-2;i>=0;i--)ans[i]+=ans[i+1];
    for(int i=1;i<m;i++)cout<<ans[i]<<"\n";
    cout<<"0\n";
}