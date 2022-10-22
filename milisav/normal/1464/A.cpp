#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n,m;
int ans;
vector<int> a[maxn];
bool vis[maxn];
bool ins[maxn];
void dfs(int u,int p) {
    vis[u]=true;
    ins[u]=true;
    for(auto v:a[u]) {
        if(v!=p) {
            if(ins[v]) ans++;
            if(!vis[v]) dfs(v,u);
        }
    }
    ins[u]=false;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        ans=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++) {
            int x,y;
            scanf("%d %d",&x,&y);
            x--;
            y--;
            if(x!=y) {
                ans++;
                a[i].push_back(m+x);
                a[m+x].push_back(i);
                a[i].push_back(m+y);
                a[m+y].push_back(i);
            }
        }
        for(int i=0;i<m;i++) {
            if(!vis[i]) dfs(i,-1);
        }
        printf("%d\n",ans);
        for(int i=0;i<n+m;i++) {
            vis[i]=false;
            a[i].clear();
        }
    }
    return 0;
}