#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,x,dp[maxn][maxn],a[maxn],b[maxn];

int main(){
    scanf("%d",&n);
    int pt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x!=a[pt]){
            a[++pt]=x;
        }
    }
    n=pt;
    for(int i=1;i<=n;i++){
        b[i]=a[n-i+1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
            else{
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
    }
  //  cout<<n<<'\n';
   // cout<<dp[n-1][n-1]<<'\n';
    printf("%d\n",n-(dp[n][n]+1)/2);
}