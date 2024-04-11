#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,u,v,m,ans[maxn],c[maxn];
vector<int> a[maxn];
map<pair<int,int>,int> f;
bool vis[maxn];
void dfs(int nod){
    vis[nod]=true;
    for(auto i: a[nod]){
            if(c[nod]==1){
                if(c[i]==0){
                c[i]=2;
                if(!vis[i])
                dfs(i);
                }
                else if(c[i]==1){
                    printf("NO\n");
                    exit(0);
                }
            }
            else if(c[nod]==2){
                if(c[i]==2){
                    printf("NO\n");
                    exit(0);
                }
                else if(c[i]==0){
                    c[i]=1;
                    if(!vis[i])
                    dfs(i);
                }
            }
        }
    return ;
    }

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
        f[{u,v}]=i;
    }
     c[1]=1;
    dfs(1);
    for(auto i:f){
        auto g=i.first;
        if(c[g.first]==1){
            ans[i.second]=0;
        }
        else
            ans[i.second]=1;
    }
    printf("YES\n");
    for(int i=1;i<=m;i++){
        printf("%d",ans[i]);
    }
}