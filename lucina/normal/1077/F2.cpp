#include<bits/stdc++.h>
using namespace std;
const long long big=-1e18;
long long dp[5004][5004];
int n,k,x,a[5004],c;
deque<int> f[5004];

int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(k*(x+1)<=n){
        cout<<"-1\n";
        return 0;
        }
        	memset(dp,-1,sizeof(dp));
        	dp[0][0]=0,f[0].push_back(0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            while(!f[j-1].empty()&&i-f[j-1].front()>k)
                f[j-1].pop_front();
            if(!f[j-1].empty())
                dp[i][j]=max(dp[i][j],dp[f[j-1].front()][j-1]+a[i]);
            }
        for(int j=1;j<=x;j++){
            if(dp[i][j]!=-1){
                while(!f[j].empty()&&dp[f[j].back()][j]<=dp[i][j])
                    f[j].pop_back();
                f[j].push_back(i);
                }
    }
    }
    long long ans=-1e18;
    for(int i=n-k+1;i<=n;i++){
        ans=max(ans,dp[i][x]);
    }
        printf("%lld",ans);


}