#include<bits/stdc++.h>
#define maxn 2000
using namespace std;
int t;
int n;
int d[maxn];
vector<int> a[maxn];
bool vis[maxn];
int c[maxn];
priority_queue<pair<int,int> > pq;
void dfs(int u,int cl) {
    vis[u]=true;
    c[u]=cl;
    for(auto v:a[u]) {
        if(!vis[v]) dfs(v,cl);
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&d[i]);
            pq.push({d[i],i});
            c[i]=0;
            vis[i]=false;
            a[i].clear();
        }
        while(!pq.empty()) {
            int u=pq.top().second;
            pq.pop();
            if(!vis[u]) {
                vis[u]=true;
                int j=0;
                bool ok=true;
                while(j<d[u] && ok) {
                    printf("? %d\n",u);
                    fflush(stdout);
                    int v;
                    scanf("%d",&v);
                    a[u].push_back(v);
                    a[v].push_back(u);
                    if(vis[v]) break;
                    vis[v]=true;
                    j++;
                }
            }
        }
        for(int i=1;i<=n;i++) vis[i]=false;
        int cl=1;
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                dfs(i,cl);
                cl++;
            }
        }
        printf("! ");
        for(int i=1;i<=n;i++) {
            printf("%d",c[i]);
            if(i!=n) printf(" ");
            else printf("\n");
        }
        fflush(stdout);
    }
    return 0;
}