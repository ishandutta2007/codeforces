#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n,m;
long long w[maxn];
long long d[maxn];
bool vis[maxn];
vector<int> a[maxn];
int cnt[maxn];
int s;
int par[maxn];
void dfs(int u) {
    int v;
    vis[u]=true;
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i];
        if(!vis[v]) {
            d[v]=d[u]+w[v];
            dfs(v);
        }
    }
}
vector<int> ch;
stack<int> rev;
long long toposort(bool ins) {
    ch.clear();
    for(int i=0;i<n;i++) {
        cnt[i]=a[i].size();
        par[i]=-1;
        d[i]=0;
        vis[i]=false;
        if(a[i].size()==1) ch.push_back(i);
    }
    int ind=0;
    int u,v;
    while(ind<ch.size()) {
        u=ch[ind];
        vis[u]=true;
        rev.push(u);
        for(int i=0;i<a[u].size();i++) {
            cnt[a[u][i]]--;
            if(!vis[a[u][i]]) {
                par[u]=a[u][i];
            }
            if(cnt[a[u][i]]==1) {
                ch.push_back(a[u][i]);
            }
        }
        ind++;
    }
    long long ans=0;
    while(rev.size()>0) {
        u=rev.top();
        rev.pop();
        d[u]=w[u]+d[par[u]];
    }
    if(!ins) {
        u=0;
        for(int i=0;i<n;i++) {
            if(d[i]>d[u]) u=i;
        }
    }
    else u=s;
    ans=d[u];
    while(par[u]!=-1) {
        w[u]=0;
        u=par[u];
    }
    return ans;
}
int main() {
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=0;i<n;i++) scanf("%lld",&w[i]);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    scanf("%d",&s);
    s--;
    if(m==n-1) { //tree
        for(int i=0;i<n;i++) vis[i]=d[i]=0;
        d[s]=w[s];
        dfs(s);
        v=0;
        for(int i=0;i<n;i++) {
            if(d[i]>d[v]) v=i;
        }
        printf("%lld\n",d[v]);
        return 0;
    }
    for(int i=0;i<n;i++) vis[i]=d[i]=0;
    long long ans=toposort(true);
    for(int i=0;i<n;i++) if(par[i]==-1) ans+=w[i];
    ans+=toposort(false);
    printf("%lld",ans);
    return 0;
}