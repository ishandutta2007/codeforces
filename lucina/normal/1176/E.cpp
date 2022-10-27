#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,n,m,u,v;
vector<int> a[maxn],b[maxn];
bool vis[maxn];
set<int> Lucinaisbestgirl;
void clean(){
    Lucinaisbestgirl.clear();
    for(int i=1;i<=n;i++)
        a[i].clear(),b[i].clear(),vis[i]=false;
    return;
}
void dfs(int nod,int pa,int dep){
    if(dep&1)Lucinaisbestgirl.insert(nod);
    for(int i:b[nod]){
        if(i!=pa){
            dfs(i,nod,dep+1);
            }

    }
    return;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int s=q.front();
            vis[s]=true;
            for(int i:a[s]){
                if(!vis[i]){
                b[s].push_back(i);
                b[i].push_back(s);
                q.push(i);
                vis[i]=true;
                }
            }
            q.pop();
        }
        dfs(1,0,0);
        if((int)Lucinaisbestgirl.size()<=n/2){
            printf("%d\n",(int)Lucinaisbestgirl.size());
            for(int i:Lucinaisbestgirl)printf("%d ",i);
            printf("\n");
        }
        else{
            printf("%d\n",n-(int)Lucinaisbestgirl.size());
            for(int i=1;i<=n;i++)
                if(Lucinaisbestgirl.find(i)==Lucinaisbestgirl.end())
                printf("%d ",i);
            printf("\n");
        }
        clean();
    }
}