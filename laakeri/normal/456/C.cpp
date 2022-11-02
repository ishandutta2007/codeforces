#include <iostream>

using namespace std;

typedef long long ll;

ll dp[100005][2];
ll a[100001];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int b;
        cin>>b;
        a[b]+=b;
    }
    dp[1][0]=0;
    dp[1][1]=a[1];
    for (int i=2;i<=100000;i++){
        dp[i][0]=max(dp[i-1][1], dp[i-1][0]);
        dp[i][1]=dp[i-1][0]+a[i];
    }
    cout<<max(dp[100000][0],dp[100000][1])<<endl;
}