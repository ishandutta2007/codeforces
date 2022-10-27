#include<bits/stdc++.h>
using namespace std;
int dp[705][705][2],n,a[705];
bool can[705][705];
void solve(int l,int r,int t){
    if(dp[l][r][t]!=-1){
        return;
    }
    if(l==r){
        dp[l][r][t]=true;
        return;
    }
    if(t==0){
    for(int i=l+1;i<=r;i++){
        if(dp[l+1][i][1]==-1)solve(l+1,i,1);
        if(dp[i][r][0]==-1)solve(i,r,0);
        if(dp[l+1][i][1]==1&&dp[i][r][0]==1&&can[l][i]){
            dp[l][r][0]=1;
            return;
        }
    }
    dp[l][r][0]=0;
    return;
    }
    else{
        for(int i=l;i<=r-1;i++){
            if(dp[l][i][1]==-1)solve(l,i,1);
            if(dp[i][r-1][0]==-1)solve(i,r-1,0);
            if(dp[l][i][1]==1&&dp[i][r-1][0]==1&&can[i][r]){
                dp[l][r][1]=1;
                return;
            }
        }
        dp[l][r][1]=0;
        return;
    }

}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            can[i][j]=(__gcd(a[i],a[j])>1)?1:0;
        }
    }
    solve(1,n,0);
    printf(dp[1][n][0]?"Yes":"No");
}