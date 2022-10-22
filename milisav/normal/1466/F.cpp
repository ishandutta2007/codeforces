#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n,m;
int p[maxn];
int c[maxn];
int sz[maxn];
long long deg[maxn];
long long mod=1e9+7;
void unite(int u,int v) {
    p[v]=u;
    c[u]=min(c[u],c[v]);
    sz[u]=sz[u]+sz[v];
}
int par(int u) {
    if(p[u]==u) return u;
    p[u]=par(p[u]);
    return p[u];
}
vector<int> s;
int main() {
    scanf("%d %d",&n,&m);
    deg[0]=1;
    for(int i=1;i<=m;i++) {
        p[i]=i;
        c[i]=n+1;
        sz[i]=1;
        deg[i]=(deg[i-1]*2)%mod;
    }
    for(int i=1;i<=n;i++) {
        int k;
        scanf("%d",&k);
        if(k==1) {
            int u;
            scanf("%d",&u);
            int x=par(u);
            if(c[x]==n+1) {
                s.push_back(i);
            }
            c[x]=min(c[x],i);
        }
        else {
            int u,v;
            scanf("%d %d",&u,&v);
            int x=par(u);
            int y=par(v);
            if(x!=y) {
                if(c[x]==n+1 || c[y]==n+1) s.push_back(i);
                unite(x,y);
            }
        }
    }
    long long ans=1;
    for(int i=1;i<=m;i++) {
        if(p[i]==i) {
            if(c[i]<=n) {
                ans=(ans*deg[sz[i]])%mod;
            }
            else {
                ans=(ans*deg[sz[i]-1])%mod;
            }
        }
    }
    printf("%lld %d\n",ans,s.size());
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++) printf("%d ",s[i]);
    return 0;
}