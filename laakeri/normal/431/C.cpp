#include <iostream>

using namespace std;

typedef long long ll;

ll dp[1001][2];

ll MOD=1000000007;

int main(){
    int n,k,d;
    cin>>n>>k>>d;
    for (int i=1;i<=k;i++){
        dp[i][i>=d]=1;
    }
    for (int i=1;i<n;i++){
        for (int ii=1;ii<=k;ii++){
            dp[i+ii][ii>=d]+=dp[i][0];
            dp[i+ii][1]+=dp[i][1];
            dp[i+ii][0]%=MOD;
            dp[i+ii][1]%=MOD;
        }
    }
    cout <<dp[n][1]%MOD<<endl;
}