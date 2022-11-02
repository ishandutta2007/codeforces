#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M = 105;
const int mod = 1e9+7;

int dp[N][M];
int b[M], c[M];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n-1;i++)
        cin>>b[i];

    int q; cin>>q;
    for(int i=0;i<q;i++) {
        int a;
        cin>>a;
        dp[0][0] = 1;
        int sum = 0, cur = 0;
        for(int k=1;k<=n;k++) {
            for(int i=0;i<1e4+10;i++) {
                for(int j=0;j<=c[k-1];j++) {
                    if(dp[i][k-1] == 0)
                        continue;

                    if((1.0*i + j - cur)/(1.0*k) >= a) {
                        dp[i+j][k] += dp[i][k-1];
                        dp[i+j][k] %= mod;
                    }
                }
            }
            sum += b[k-1];
            cur += sum;
        }
        int ans = 0;
        for(int i=0;i<1e4+10;i++) {
            ans += dp[i][n];
            ans %= mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}