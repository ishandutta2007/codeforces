#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int>bits[61],mp[N];
int ans,dis[N];
void dfs(int u,int d,int f,int e){
    dis[u]=d;
    if(u==e){ans=min(ans,d+1);return;}
    for(int i=0;i<mp[u].size();i++){
        int v=mp[u][i];
        if(v==f||dis[v]<dis[u]+1)continue;
        dfs(v,d+1,u,e);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    long long v;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&v);
        for(int j=0;j<60;++j){
            if(v&(1ll<<j)){
                bits[j].push_back(i);
                if(bits[j].size()>2)return printf("3\n"),0;
            }
        }
    }
    for(int i=0;i<60;i++)if(bits[i].size()==2){
        mp[bits[i][0]].push_back(bits[i][1]);
        mp[bits[i][1]].push_back(bits[i][0]);
    }
    ans=1e9;
    for(int i=0;i<60;i++)if(bits[i].size()==2){
        memset(dis,0x3f,sizeof(dis));
        dis[bits[i][0]]=0;
        dfs(bits[i][0],0,bits[i][1],bits[i][1]);
    }
    if(ans==1e9)printf("-1\n");
    else printf("%d\n",ans);
}