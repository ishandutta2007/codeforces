#include <iostream>

using namespace std;

typedef long long ll;

ll dp[1001][20202];

int main(){
    ll mod=1e9+7;
    int n;
    cin>>n;
    ll v=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        for (int ii=0;ii<20202;ii++){
            if (ii+a>=0){
                dp[i+1][ii+a]+=dp[i][ii];
                dp[i+1][ii+a]%=mod;
            }
            if (ii-a<20201){
                dp[i+1][ii-a]+=dp[i][ii];
                dp[i+1][ii-a]%=mod;
            }
        }
        dp[i+1][a+10001]++;
        dp[i+1][10001-a]++;
        v+=dp[i][10001];
        v%=mod;
    }
    v+=dp[n][10001];
    v%=mod;
    cout<<v<<endl;
}