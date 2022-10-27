#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,dis[105][105],m;
vector<int> a[105],res;
int p[maxn];
bool adj[105][105];
void bfs(int nod){
    queue<int> q;
    q.push(nod);
    for(int i=1;i<=n;i++){
        dis[nod][i]=maxn;
    }
    dis[nod][nod]=0;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i:a[top]){
            if(dis[nod][i]==maxn){
                dis[nod][i]=dis[nod][top]+1;
                q.push(i);
            }
        }
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&adj[i][j]);
            if(adj[i][j]){
                a[i].push_back(j);
            }
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&p[i]);
    }
    res.push_back(p[1]);
    for(int i=1;i<=m;i++){
        if(i==m)
        break;
        int j=i+1;
        for(int k=1;k<=n&&i+k<=m;k++){
            if(dis[p[i]][p[i+k]]==k){
                j=max(j,i+k);
            }
        }
      //  cerr<<i<<' '<<j<<'\n';
        res.push_back(p[j]);
        i=j-1;
    }
    printf("%d\n",(int)res.size());
    for(int i:res){
        printf("%d ",i);
    }
}
/*
    Good Luck
        -Lucina
*/