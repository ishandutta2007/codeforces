#include<bits/stdc++.h>
#define maxn 2000
using namespace std;
int t;
int n,m;
long long a[maxn];
int c[maxn];
int orig[maxn];
vector<int> g[maxn];
vector<int> topo;
bool vis[maxn];
const long long mod=998244353;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<m;i++) {
            int x,y;
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            c[y]++;
            orig[y]++;
        }
        for(int i=1;i<=n;i++) {
            if(c[i]==0) topo.push_back(i);
        }
        for(int i=1;i<=n;i++) {
            int u=topo[i-1];
            for(auto v:g[u]) {
                c[v]--;
                if(c[v]==0) topo.push_back(v);
            }
            //cout<<u<<endl;
        }
        for(int i=1;i<=n;i++) {
            c[i]=orig[i];
        }
        long long ans=0;
        for(int iter=1;iter<=n;iter++) {
            bool ok=false;
            for(int i=n-1;i>=0;i--) {
                int u=topo[i];
                if(a[u]>0) {
                    ok=true;
                    a[u]--;
                    for(auto v:g[u]) {
                        a[v]++;
                    }
                }
            }
            if(ok) {
                ans++;
            }
            else break;
        }
        for(int i=1;i<=n;i++) {
            a[i]%=mod;
        }
        /*for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;*/
        int visc=0;
        for(;visc<n;) {
            long long cur=1e18;
            for(int i=1;i<=n;i++) {
                if(c[i]==0 && !vis[i]) cur=min(cur,a[i]);
            }
            ans+=cur;
            for(int i=0;i<n;i++) {
                int u=topo[i];
                if(vis[u]) continue;
                a[u]-=cur;
                if(a[u]<0) a[u]+=mod;
                for(auto v:g[u]) {
                    a[v]+=cur;
                    if(a[v]>=mod) a[v]-=mod;
                }
                if(c[u]==0 && a[u]==0 && !vis[u]) {
                    vis[u]=true;
                    visc++;
                    for(auto v:g[u]) {
                        c[v]--;
                    }
                }
            }
            ans%=mod;
        }
        printf("%lld\n",(ans%mod));
        for(int i=1;i<=n;i++) {
            g[i].clear();
            c[i]=0;
            orig[i]=0;
            vis[i]=false;
        }
        topo.clear();
    }
    return 0;
}