#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int s[500000];
vector<int> a[500000];
bool vis[500000];
int d[3][500000];
queue<int> q;
pair<pair<int,int>,int> st[500000];
void bfs(int id,int u) {
    for(int i=1;i<=n;i++) {
        vis[i]=false;
    }
    d[id][u]=0;
    vis[u]=true;
    q.push(u);
    while(!q.empty()) {
        u=q.front();
        q.pop();
        for(auto v:a[u]) {
            if(!vis[v]) {
                vis[v]=true;
                d[id][v]=d[id][u]+1;
                q.push(v);
            }
        }
    }
}
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++) {
        scanf("%d",&s[i]);
    }
    int x,y;
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(0,1);
    bfs(1,n);
    for(int i=1;i<=k;i++) {
        st[i]={{d[0][s[i]],d[1][s[i]]},s[i]};
    }
    sort(st+1,st+k+1);
    int mv=-1;
    int ans=-1;
    for(int i=k;i>=1;i--) {
        if(i!=k) {
            int bans=min(d[0][n],st[i].first.first+1+min(mv,st[i].first.second));
            if(ans==-1 || ans<bans) ans=bans;
            mv=max(mv,st[i].first.second);
        }
        else {
            mv=st[i].first.second;
        }
    }
    printf("%d",ans);
    return 0;
}