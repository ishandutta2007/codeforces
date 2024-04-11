#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,m,deg[10],vis[10][10];
vector<pair<int,int>> e;
vector<int> a[maxn];
int ans,v[10];
void test(){
    int ct = 0;
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            vis[i][j] = false;
    vector<bool> cc(m,false);
    while(true){
    int pt = 0;
    int bef =ct;
    for(auto i:e){
        if(cc[pt]){
            pt ++;
            continue;
        }
        if(!vis[v[i.first]][v[i.second]] && v[i.first] <=v[i.second]){
            vis[v[i.first]][v[i.second]] = true;
            ct ++;
            cc[pt] = true;
        }
        else if(!vis[v[i.second]][v[i.first]] && v[i.second] <= v[i.first]){
            vis[v[i.second]][v[i.first]] = true;
            ct ++;
            cc[pt] = true;
        }
        pt ++ ;
    }
    if(bef == ct)break;
    }
   /* if(ct == 21){
        for(int i=1;i<=n;i++)
            printf("%d " ,v[i]);
        printf("\n");
    }*/
    ans = max(ans,ct);
}
void shit(int x){
    if(x == n+1){
        test();
        return;
    }
    for(int j=1;j<=6;j++){
        v[x] = j;
        shit(x+1);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e.emplace_back(u,v);
    }
    shit(1);
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/