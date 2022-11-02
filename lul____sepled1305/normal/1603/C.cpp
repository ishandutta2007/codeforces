#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int mod = 998244353;
const int N = 1e5, M = 2e2;
int dp[N][M];
 
int add(int a, int b) {
    return (int) (a+b)%mod;
}
 
int mul(int a,int b) {
    long long g = (1LL*a*b)%mod;
    return (int) g;
}
 
int recur(int n, int a[], int maxi) {
    if(n == 0) {
        //cout<<"LOOP: "<<n<<' '<<maxi<<' '<<(a[0]-1)/maxi<<endl;
        return ((a[0]-1)/maxi);
    }
    else if(maxi < 200) {
        return dp[n][maxi];
    }
    else {
        int ans = 0;
        if(maxi >= a[n]) {
            ans = recur(n-1,a,a[n]);
        }
        else {
            int next = a[n]/((a[n]+maxi-1)/maxi);
            ans = recur(n-1,a,next);
            ans = add(mul(n+1,((a[n]-1)/maxi)),ans);
        }
        return ans;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        map<pii,int> mp;
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=1;j<200;j++) {
                //cout<<i<<' '<<j<<endl;
                if(i == 0) {
                    dp[i][j] = max((a[i]-1)/j,0);
                }
                else {
                    if(j >= a[i]) {
                        dp[i][j] = dp[i-1][a[i]];
                    }
                    else {
                        int next = a[i]/((a[i]+j-1)/j);
                        dp[i][j] = add(mul(i+1,((a[i]-1)/j)),dp[i-1][next]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            ans = add(ans,recur(i,a,a[i]));
            //cout<<i<<' '<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}