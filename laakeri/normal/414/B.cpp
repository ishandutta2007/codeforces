#include <iostream>

using namespace std;

typedef long long ll;

ll dp[2002][2002];

int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        dp[0][i]=1;
    }
    for (int i=0;i<k;i++){
        for (int ii=1;ii<=n;ii++){
            for (int k=1;k<=2000;k++){
                if (ii*k>n){
                    break;
                }
                dp[i+1][ii*k]+=dp[i][ii];
                dp[i+1][ii*k]%=1000000007;
            }
        }
    }
    ll v=0;
    for (int i=1;i<=n;i++){
        v+=dp[k-1][i];
        v%=1000000007;
    }
    cout <<v<<endl;
}