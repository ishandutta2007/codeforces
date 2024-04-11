#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int s[1010][1010],pa[maxn],u,v,n,m,ans[maxn],z;
char ds[maxn];
bool vis[maxn],e[maxn],ch;
vector<int> a[maxn];
int findpa(int x){
    return x==pa[x]?x:pa[x]=findpa(pa[x]);
}
void dfs(int nod){
    vis[nod]=true;
    e[nod]=true;
    for(auto i:a[nod]){
        if(e[i]){
            printf("No");
            exit(0);
        }
        if(!vis[i])
            dfs(i);
    }
    z=0;
    for(auto i:a[nod]){
        z=max(z,ans[i]);
    }
    ans[nod]=z+1;
    e[nod]=false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+m+2;i++){
        pa[i]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%s",ds+1);
        for(int j=1;j<=m;j++){
            if(ds[j]=='=')
                s[i][j]=3;
            else if(ds[j]=='>')
                s[i][j]=2;
            else if(ds[j]=='<')
                s[i][j]=1;
            if(ds[j]=='='){
                u=findpa(i);
                v=findpa(n+j);
                pa[v]=u;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==3)
            continue;
            u=findpa(i);
            v=findpa(n+j);
            if(s[i][j]==2)
                a[u].push_back(v);
            else
                a[v].push_back(u);
        }
    }
    for(int i=1;i<=n+m;i++){
        if(!vis[i]){
            dfs(findpa(i));
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++)
        printf("%d ",ans[findpa(i)]);
    printf("\n");
    for(int i=1;i<=m;i++)
        printf("%d ",ans[findpa(n+i)]);
    printf("\n");
}
/*
3 4

>>=>
>>>>
>=>>

*/