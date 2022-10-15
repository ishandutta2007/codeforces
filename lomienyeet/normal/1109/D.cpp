#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e6+5,mod=1e9+7;
int fact[mxN],inv[mxN];
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
int ncr(int n,int r){
    if(n<r)return 0;
    return ((fact[n]*inv[r])%mod*inv[n-r])%mod;
}
signed main(){
    fact[0]=inv[0]=1;
    for(int i=1;i<mxN;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=bm(fact[i],mod-2);
    }
    int n,m,a,b,ans=0;
    cin>>n>>m>>a>>b; // 
    //  wow
    for(int i=1;i<n;i++){
        int weeee=(((ncr(m-1,i-1)*bm(m,n-i-1))%mod*fact[n-2])%mod*inv[n-i-1])%mod;
        if(i<n-1)(((weeee*=bm(n,n-i-2))%=mod)*=(i+1))%=mod;
        (ans+=weeee)%=mod;
    }
    cout<<ans<<"\n";
}