#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5,mod=1e9+7;
int f[mxN],inv[mxN];
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
int eat(int n,int r){return ((f[n]*inv[r])%mod*inv[n-r])%mod;}
signed main(){
    int n,ans=0;
    cin>>n;
    f[0]=inv[0]=1;
    n++;
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
        inv[i]=bm(f[i],mod-2);
    }
    for(int i=1;i<=n;i++)(ans+=bm(eat(n,i),2))%=mod;
    cout<<ans<<"\n";
}