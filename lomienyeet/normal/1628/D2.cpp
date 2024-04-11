#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
const int mxN=1e6+5,mod=1e9+7;
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
int fact[mxN],invf[mxN],inv[mxN];
int ncr(int n,int r){
    if(n<r)return 0;
    return ((fact[n]*invf[r])%mod*invf[n-r])%mod;
}
int calc(){
    fact[0]=fact[1]=inv[0]=1;
    inv[1]=bm(2,mod-2);
    for(int i=2;i<mxN;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=(inv[i-1]*inv[1])%mod;
    }
    invf[mxN-1]=bm(fact[mxN-1],mod-2);
    for(int i=mxN-1;i>0;i--)invf[i-1]=(invf[i]*i)%mod;
}
void eat(){
    int n,m,k;
    cin>>n>>m>>k;
    if(n==m){
        cout<<(n*k)%mod<<"\n";
        return;
    }
    int ans=0;
    for(int i=1;i<=m;i++)(ans+=((i*ncr(n-i-1,m-i))%mod*inv[n-i])%mod)%=mod;
    cout<<(ans*k)%mod<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    calc();
    while(t--)eat();
}