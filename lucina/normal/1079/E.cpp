#include<bits/stdc++.h>
using namespace std;
int dp[105][20005],n,x,ans,sum,c[105];

int main(){
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        c[x]++;
        sum+=x;
        for(int j=i;j>0;j--){
            for(int k=sum;k>=x;k--){
                if(dp[j][k]==-1||dp[j-1][k-x]==0)
                    continue;
                dp[j][k]=((dp[j-1][k-x]==1)&&(j*x==k))?1:-1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++)
            if(dp[i][j]==1)
            ans=max(ans,i);
    }
    int ct=0;
    for(int i=1;i<=100;i++)
        ct+=(c[i]>0?1:0);
    if(ct<=2)return printf("%d\n",n),0;
    printf("%d\n",ans);
}