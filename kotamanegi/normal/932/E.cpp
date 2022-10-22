#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
long long int Pow(long long a,int n,int mod){
    if(n==0){
        return 1;
    }
    long long p=Pow(a,n/2,mod);
    p*=p;
    p%=mod;
    if(n%2){
        p*=a;
        p%=mod;
    }
    return p;
}
 
int main(){
    int N,K;
    cin>>N>>K;
    int mod=1e9+7;
    vector<vector<long long>> dp(K+1,vector<long long>(K+1));
    dp[0][0]=1;
    for(int k=0;k<K;k++){
        for(int i=0;i<K;i++){
            dp[k+1][i]+=dp[k][i]*i;
            dp[k+1][i+1]+=dp[k][i]*(N-i);
            dp[k+1][i]%=mod;
        }
    }
    long long ans=0;
    dp[K][K] %= mod;
    for(int i=0;i<K+1;i++){
        ans+=dp[K][i]*Pow(2,N-i,mod);
        ans%=mod;
    }
    ans%=mod;
    cout<<ans;
}