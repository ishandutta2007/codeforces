#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,m;cin>>n>>m;
    long long int fact[n+1];
    fact[0] = 1;
    for(long long int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=m;
    }
    long long int ans = 0 ;
    for(long long int i=1;i<=n;i++){
        ans+=(((fact[i]*fact[n-i+1])%m)*(n-i+1))%m;
        ans%=m;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}