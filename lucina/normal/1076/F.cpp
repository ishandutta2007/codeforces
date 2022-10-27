/*
Summer practice report
Lucina
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mm=1e9;
int n,k,dp[maxn][2],a[maxn],b[maxn];
int block,fp,d,ans,ct;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    //0->a  1->b
    for(int i=1;i<=n;i++){
        dp[i][0]=mm;dp[i][1]=mm;
        if(dp[i-1][0]<=k){
            fp=a[i]+dp[i-1][0];
            block=fp/k-(fp%k==0);
            if(block==b[i]){
                dp[i][0]=min(dp[i][0],fp-block*k);
            }
            else if(b[i]>block&&b[i]<=1ll*a[i]*k){
                dp[i][0]=min(dp[i][0],1);
            }
        }
        if(dp[i-1][1]<=k){
            fp=a[i];
            block=fp/k-(fp%k==0);
            if(block==b[i]){
                dp[i][0]=min(dp[i][0],fp-block*k);
            }
            else if(b[i]>block&&b[i]<=(1ll*k*(a[i]-1))+k-dp[i-1][1]){
                dp[i][0]=min(dp[i][0],1);
            }
        }
        //another bash
        if(dp[i-1][1]<=k){
            fp=b[i]+dp[i-1][1];
            block=fp/k-(fp%k==0?1:0);
            if(block==a[i]){
                dp[i][1]=min(dp[i][1],fp-block*k);
            }
            else if(a[i]>block&&a[i]<=(1ll*(b[i])*k)){
                dp[i][1]=min(dp[i][1],1);
            }
        }
        if(dp[i-1][0]<=k){
            fp=b[i];
            block=fp/k-(fp%k==0);
            if(block==a[i]){
                dp[i][1]=min(dp[i][1],fp-block*k);
            }
            else if(a[i]>block&&a[i]<=(1ll*(k)*(b[i]-1))+k-dp[i-1][0]){
                dp[i][1]=min(dp[i][1],1);
            }
        }
       // cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
        if(dp[i][0]>k&&dp[i][1]>k){
            printf("NO");
            return 0;
        }
    }
        printf("YES");
}