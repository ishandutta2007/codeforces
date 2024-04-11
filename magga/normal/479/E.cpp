#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
void pre(){}
void solve(){
    int n,a,b,k;cin>>n>>a>>b>>k;
    long long int dp[k+1][n+1];
    for(long long int i=0;i<=k;i++)
        for(long long int j=0;j<=n;j++)
        dp[i][j]=0;
    dp[0][a]=1;
    for(int j=0;j<=n;j++){
        //cout<<j<<" ";
    }
    //cout<<"\n";
    for(int j=0;j<=n;j++){
        //cout<<dp[0][j]<<" ";
    }
    //cout<<"\n";
    long long int pre[n+1];
    int ran;
    for(int i=1;i<=k;i++){
        pre[0]=0;
        for(int j=1;j<=n;j++)  pre[j]=(pre[j-1]+dp[i-1][j])%mod;
        for(int j=1;j<=n;j++){
            if(j<b){
                dp[i][j]+=pre[j-1];
                dp[i][j]+=(pre[(b+j-1)/2]-pre[j]+mod)%mod;
            }else if(j>b){
                dp[i][j]+=(pre[n]-pre[j]+mod)%mod;
                dp[i][j]+=(pre[j-1]-pre[(j+b)/2]+mod)%mod;
            }
            dp[i][j]%=mod;
        }
        for(int j=0;j<=n;j++){
         //   cout<<dp[i][j]<<" ";
        }
       // cout<<"\n";
    }
    long long int nas = 0;
    for(int i=1;i<=n;i++){
        nas+=dp[k][i];
    } 
    cout<<nas%mod<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}