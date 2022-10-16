#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<pair<int,int> >g[605];
int dist[605][605],pos[605],ban[605][605];
int main(){
    memset(dist,0,sizeof dist);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=n;i++)random_shuffle(g[i].begin(),g[i].end());
    cin>>q;
    while(q--){
        int x,y,l;cin>>x>>y>>l;
        if(x>y)swap(x,y);
        dist[x][y]=max(dist[x][y],l);
    }
    for(int i=1;i<=n;i++)pos[i]=i+1;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(dist[i][j]>dist[i][pos[i]])pos[i]=j;
    while(1){
        int x,y,best=-1;
        for(int i=1;i<=n;i++)if(pos[i]<=n){
            if(dist[i][pos[i]]>best){
                best=dist[i][pos[i]];
                x=i;y=pos[i];
            }
        }
        if(best==-1)break;
        pos[x]=n+1;ban[x][y]=1;
        for(int i=x+1;i<=n;i++)if(!ban[x][i]){
            if(dist[x][i]>dist[x][pos[x]])pos[x]=i;
        }
        for(auto p:g[x]){
            int i=p.first,cost=p.second;
            int nx,ny;
            //trans x
            nx=min(y,i);ny=max(y,i);
            if(dist[nx][ny]<dist[x][y]-cost){
                dist[nx][ny]=dist[x][y]-cost;
                if(dist[nx][ny]>dist[nx][pos[nx]])pos[nx]=ny;
            }
        }
        for(auto p:g[y]){
            int i=p.first,cost=p.second;
            int nx,ny;
            //trans x
            nx=min(x,i);ny=max(x,i);
            if(dist[nx][ny]<dist[x][y]-cost){
                dist[nx][ny]=dist[x][y]-cost;
                if(dist[nx][ny]>dist[nx][pos[nx]])pos[nx]=ny;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(auto p:g[i])if(p.first>i&&dist[i][p.first]>=p.second)ans++;
    cout<<ans<<endl;
    return 0;
}