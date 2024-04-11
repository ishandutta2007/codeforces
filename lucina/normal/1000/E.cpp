#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
#define find jflkdsjf
#define merge fsjkdfjlsf
int n,m,u,v,w,dp[maxn],ans,timer,tin[maxn],pa[maxn],sz[maxn],d[maxn];
bool vis[maxn];
vector<int> a[maxn],b[maxn];
vector<pair<int,int>> bridge;
int find(int x){
    return x==pa[x]?x:pa[x]=find(pa[x]);
}
void merge(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    pa[y]=x;
    sz[x]+=sz[y];
    return;
}
int dfs(int nod,int pa){
    tin[nod]=++timer;
    int f=tin[nod];
    for(int i:a[nod]){
        if(i!=pa){
            if(tin[i]>0){
                f=min(f,tin[i]);
            }
            else{
                int t=dfs(i,nod);
                f=min(f,t);
                if(t>tin[nod]){
                    bridge.push_back(make_pair(nod,i));
                }
                else{
                    merge(nod,i);
                }
            }
        }
    }
    timer++;
    return f;
}
void build(){
    int x,y;
    for(auto z:bridge){
        x=find(z.first);y=find(z.second);
        u=x;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    return;
}
pair<int,int> bfs(int nod){
    queue<int> q;
    for(int i=1;i<=n;i++)
        d[i]=n+5;
    d[nod]=0;
    q.push(nod);
    memset(vis,false,sizeof(vis));
    pair<int,int> best=make_pair(0,0);
    vis[nod]=true;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i:b[s]){
            d[i]=min(d[i],d[s]+1);
            if(d[i]>best.first){
                best.first=d[i];
                best.second=i;
            }
            if(!vis[i])
                q.push(i);
            vis[i]=true;
            }
        }
    return best;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        pa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    build();
    auto p1=bfs(u);
    auto z=bfs(p1.second);
    printf("%d\n",z.first);
}