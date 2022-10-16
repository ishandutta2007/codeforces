#include<bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int cach[400001];
void pre(){
    cach[0]=1;
    for(long long int i=1;i<=400000;i++){
        cach[i]=(cach[i-1]*10)%mod;
    }
}
void solve(){
    long long int n;cin>>n;
    long long int ans[n];
    for(long long int i=0;i<n-1;i++){
        ans[i]=2*10*9*cach[n-i-2]%mod;
        if(i!=n-2){
            ans[i]+=((10*9*9*cach[n-i-3])%mod)*(n-i-2)%mod;
        }
        ans[i]%=mod;
    }
    ans[n-1]=10;
    for(auto i:ans){
        cout<<i<<" "; 
    }
    cout<<"\n";
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