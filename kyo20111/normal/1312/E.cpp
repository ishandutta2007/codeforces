#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[505], dp[505][505], val[505][505];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) dp[i][i] = 1;
    for(int i=1;i<=n;i++) val[i][i] = a[i];

    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = i + l - 1;

            dp[i][j] = 1e9;
            for(int k=i+1;k<=j;k++) dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
            for(int k=i+1;k<=j;k++) if(dp[i][k-1] == 1 && dp[k][j] == 1 && val[i][k-1] == val[k][j]) dp[i][j] = 1, val[i][j] = val[i][k-1] + 1;
        }
    }

    printf("%d",dp[1][n]);
}