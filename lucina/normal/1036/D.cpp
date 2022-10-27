#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,a[maxn],b[maxn],ans;
long long sum1,sum2,dp[2][maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum1+=(a[i]);
        dp[0][i]=sum1;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]),sum2+=(b[i]);
        dp[1][i]=sum2;
    }
    dp[1][m+1]=1e9+7;
    dp[0][n+1]=1e9+12;
    if(sum1!=sum2){
        return printf("-1"),0;
    }
    int pt1=1,pt2=1;
    while(true){
        while(dp[0][pt1]<dp[1][pt2]&&pt1<n){
            pt1++;
        }
        if(dp[0][pt1]==dp[1][pt2]){
            ans++;
            pt1++;pt2++;
        }
        while(dp[1][pt2]<dp[0][pt1]&&pt2<m){
            pt2++;
        }
        if(dp[1][pt2]==dp[0][pt1]){
            ans++;
            pt1++,pt2++;
        }
        if(pt1>n&&pt2>m){
            printf("%d\n",ans);
            return 0;
        }
    }

}