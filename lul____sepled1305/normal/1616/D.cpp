#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n+2];
        for(int i=0;i<n;i++) cin>>a[i+2];
        int x; cin>>x;
        for(int i=2;i<n+2;i++)
            a[i] -= x;
        a[0] = 0, a[1] = 0;
        int dp[n+2][4];
        for(int i=0;i<n+2;i++)
            for(int j=0;j<4;j++)
                dp[i][j] = -1e9;

        for(int i=0;i<2;i++)
            for(int j=0;j<4;j++)
                dp[i][j] = 0;

        for(int i=2;i<n+2;i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + 1;
            dp[i][2] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][3] = -1e9;

            if(a[i]+a[i-1] >= 0)
                dp[i][3] = max(dp[i][3],dp[i-1][1]+1);

            if(a[i]+a[i-1]+a[i-2] >= 0 && a[i]+a[i-1] >= 0)
                dp[i][3] = max(dp[i][3],dp[i-1][3]+1);
        }
        cout<<max(max(dp[n+1][0],dp[n+1][1]),max(dp[n+1][2],dp[n+1][3]))<<endl;
    }
    return 0;
}