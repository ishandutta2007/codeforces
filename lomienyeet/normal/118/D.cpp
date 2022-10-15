#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e8;
signed main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int dp[2][a+1][b+1];
    for(int i=0;i<2;i++){
        for(int j=0;j<=a;j++){
            for(int k=0;k<=b;k++)dp[i][j][k]=0;
        }
    }
    dp[0][0][0]=dp[1][0][0]=1;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(!(i|j))continue;
            for(int k=max(i-c,0ll);k<i;k++)(dp[0][i][j]+=dp[1][k][j])%=mod;
            for(int k=max(j-d,0ll);k<j;k++)(dp[1][i][j]+=dp[0][i][k])%=mod;
        }
    }
    cout<<(dp[0][a][b]+dp[1][a][b])%mod<<"\n";
}