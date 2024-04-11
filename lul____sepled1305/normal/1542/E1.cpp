#include<bits/stdc++.h>
using namespace std;
int n, mod;

int add(int a, int b) {
    long long g = (0LL+a+b)%mod;
    return (int) g;
}

int mul(int a, int b) {
    long long g = (1LL*a*b)%mod;
    return (int) g;
}

int dp[50][1500];
int s[1500];

int main() {
    cin>>n>>mod;
    dp[0][0] = 1;
    int ans = 0;
    for(int i=1;i<n;i++) {
        ans = mul((i+1),ans);
        for(int k=0;k<=i;k++) {
            int sum = 0;
            for(int j=1400;j>=0;j--) {
                sum = add(sum, dp[i][j]);
                s[j] = sum;
            }
            for(int j=0;j<1400;j++) {
                dp[i][j+k] = add(dp[i][j+k],dp[i-1][j]);
                ans = add(ans,mul(s[j+k+1],dp[i-1][j]));
            }
        }
    }
    cout<<ans;
    return 0;
}