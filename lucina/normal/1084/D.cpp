#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,w[maxn],e,f,g;
long long dp[maxn],ans;
vector<pair<int,int>> b[maxn];
void dfs(int nod,int pa){
    dp[nod]=w[nod];
    for(auto i:b[nod]){
        if(i.first!=pa){
            dfs(i.first,nod);
            ans=max(ans,dp[nod]+dp[i.first]-i.second);
            dp[nod]=max(dp[nod],dp[i.first]-i.second+w[nod]);
            }
        }
    ans=max(ans,dp[nod]);
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        }
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&e,&f,&g);
        b[e].push_back({f,g});
        b[f].push_back({e,g});
        }
        dfs(1,0);
        printf("%lld\n",ans);
    }