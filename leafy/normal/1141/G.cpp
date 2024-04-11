#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k;
vector<int> G[N],g[N];
int deg[N],num,ans[N];
void dfs(int u,int fa,int fc){
    int x=1;
    if(x==fc&&x<num) x++;
    for(int i=0;i<G[u].size();i++){
    	int v=G[u][i];
        if(v==fa) continue;
        ans[g[u][i]]=x;
        dfs(v,u,x);
        if(x<num) x++;
		if(x==fc&&x<num) x++;
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        g[u].push_back(i);
        G[v].push_back(u);
        g[v].push_back(i);
        deg[u]++,deg[v]++;
    }
    sort(deg+1,deg+n+1);
    num=deg[n-k]!=0?deg[n-k]:1;
    cout<<num<<endl;
    dfs(1,0,0);
    for(int i=1;i<n;i++) cout<<ans[i]<<' ';
    return 0;
}