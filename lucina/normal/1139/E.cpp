#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int n,m,d,k[maxn],p[maxn],c[maxn],match[maxn],ans[maxn],mex;
bool de[maxn],vis[maxn];
vector<int> a[maxn];
bool dfs(int nod){
    for(auto i:a[nod]){
        if(vis[i])continue;
        vis[i]=true;
        if(match[i]==-1||dfs(match[i])){
            match[i]=nod;
            return true;
        }
        vis[i]=false;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    scanf("%d",&d);
    for(int i=1;i<=d;i++){
        scanf("%d",&k[i]);
        de[k[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(!de[i]){
            a[p[i]].push_back(c[i]);
        }
    }
    memset(match,-1,sizeof(match));
    for(int i=d;i>=1;i--){
        while(true){
            memset(vis,false,sizeof(vis));
            if(dfs(mex))mex++;
            else break;
        }
        ans[i]=mex;
        a[p[k[i]]].push_back(c[k[i]]);
    }
    for(int i=1;i<=d;i++){
        printf("%d\n",ans[i]);
    }
}