#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int mod,k;
long long int po(long long int x){
    long long int y = x; 
    x*=x;x%=mod;
    x*=x;x%=mod;
    x=( x + mod - (k*y)%mod )%mod ;
    return x;
}
void solve(){
    long long int n,d;cin>>n>>mod>>k;
    map<long long int,int>m;
    long long int ans = 0;
    for(int i=0;i<n;i++){
        cin>>d;
        m[po(d)]++;
        //cout<<d<<" "<<po(d)<<"\n";
    }
    for(auto i:m){
        ans+=(i.second*(i.second-1))/2;
    }
    cout<<ans<<"\n";
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