#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int dp[maxn][2],n,u,v,w;
long long ans;
vector<pair<int,int>> a[maxn];
/*
dp[i][j] maximum number of path of weight j we can access through i
*/
void dfs(int nod,int pa){
    for(auto i:a[nod]){
     if(i.first!=pa){
        dfs(i.first,nod);
        if(i.second==0){
            dp[nod][0]+=(dp[i.first][0]+1);
        }
        if(i.second==1){
            dp[nod][1]+=(dp[i.first][1]+1);
        }
     }
    }
    return;
}
void dfs1(int nod,int pa){
    ans+=(1ll*dp[nod][1]*dp[nod][0]);
    ans+=(dp[nod][0]+dp[nod][1]);
    for(auto i:a[nod]){
        if(i.first!=pa){
           dp[i.first][i.second]=dp[nod][i.second];
           dfs1(i.first,nod);
        }
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
    dfs(1,0);
    dfs1(1,0);
    //cout<<dp[2][1]<<endl;
    printf("%lld\n",ans);
}