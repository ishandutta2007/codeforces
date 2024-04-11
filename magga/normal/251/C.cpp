#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int a,b,k;
long long int inf = 1e9;
long long int oo = 0;
long long int val(long long int k){
    long long int ret = 1;
    for(long long int i=2;i<=k;i++){
        ret=(ret*i)/(__gcd(i,ret));
    }
    return ret;
}
long long int distance(long long int a,long long int b){
    long long int dp[oo];
    for(int i=0;i<oo;i++)
        dp[i]= inf;
    dp[a]=0;
    for(int i=a;i>b;i--){
        for(int j=2;j<=k;j++){
            dp[i-(i%j)]=min(dp[i-(i%j)],dp[i]+1);
        }
        dp[i-1]=min(dp[i-1],dp[i]+1);
    }
    return dp[b];
}
void solve(){
    cin>>a>>b>>k;
    oo=val(k);
    //cout<<oo<<"\n";
    if(a/oo==b/oo){
        cout<<distance(a%oo,b%oo)<<"\n";
        return;
    }
    cout<<distance(a%oo,0)+1+(a/oo - b/oo-1)*(distance(oo-1,0)+1)+distance(oo-1,b%oo)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}