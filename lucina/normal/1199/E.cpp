#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,T,m;
vector<pair<int,int>> a[maxn];
void cl(){
    for(int i=1;i<=n;++i){
        a[i].clear();
    }
    return;
}
bool vis[maxn];

int main(){
    scanf("%d",&T);
    while(T--){
            for(int i=1;i<=3*n;i++){
                vis[i]=false;
            }
        scanf("%d%d",&n,&m);
        int u,v;
        vector<int> mat;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            if(!vis[u]&&!vis[v]){
                vis[u]=1;vis[v]=1;
                mat.push_back(i);
            }
        }
        if((int)mat.size()>=n){
            printf("Matching\n");
            for(int i=0;i<n;i++){
                printf("%d ",mat[i]);
            }
            printf("\n");
        }
        else{
            printf("IndSet\n");
            int cnt=0;
            for(int i=1;i<=3*n;i++){
                if(!vis[i]){
                    printf("%d ",i);
                    cnt++;
                    if(cnt==n)break;
                }
            }
            printf("\n");
        }
    }
}
/*
    Good Luck
        -Lysithea
*/