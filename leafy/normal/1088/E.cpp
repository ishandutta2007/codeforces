#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int n;
int a[N];
vector<int> G[N];
ll f[N];
ll t,num;
void dfs(int u,int fa){
    f[u]=a[u];
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
        if(f[v]>0) f[u]+=f[v];
    }
}
void dfs2(int u,int fa){
    f[u]=a[u];
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        dfs2(v,u);
        if(f[v]>0) f[u]+=f[v];
    }
    if(t==f[u]) f[u]=0,num++;
}
int main(){
    scanf("%d",&n);
    int flag=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i]>=0) flag=1;
    }
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    if(flag){
        dfs(1,0);
        t=(*max_element(f+1,f+n+1)),num=0;
        dfs2(1,0);
        cout<<num*t<<' '<<num;
        return 0;
    }
    t=*max_element(a+1,a+n+1),num=0;
    for(int i=1;i<=n;i++) if(a[i]==t) num++;
    cout<<(ll)t*num<<' '<<num;
    return 0;
}