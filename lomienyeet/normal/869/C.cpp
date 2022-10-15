#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=5e3+5,mod=998244353;
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
int eat(int a,int b){
    if(a>b)swap(a,b);
    int ans=0;
    for(int i=0;i<=a;i++)(ans+=((ncr(a,i)*ncr(b,i))%mod*fact[i])%mod)%=mod;
    return ans;
}
signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    fact[0]=inv[0]=1;
    for(int i=1;i<mxN;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=bm(fact[i],mod-2);
    }
    cout<<((eat(a,b)*eat(b,c))%mod*eat(c,a))%mod<<"\n";
}