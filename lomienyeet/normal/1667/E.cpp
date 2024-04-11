// please do not fucking pass

/*




























































*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5,mod=998244353;
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
int fact[mxN],inv[mxN],wao[mxN];
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
    for(int i=1;i<mxN;i++)wao[i]=(fact[i-1]*inv[i])%mod;
    int n;
    cin>>n;
    int weeee=(n+1)>>1,arr[n+1]={},ps[n+1]={};
    for(int i=2;i<=weeee;i++)arr[i]=((fact[n-i]*inv[weeee-i])%mod*fact[weeee-1])%mod;
    arr[1]=arr[2];
    for(int i=2;i<=weeee;i++)ps[i]=(arr[i]*wao[i-1])%mod;
    for(int i=weeee-1;i>1;i--)(ps[i]+=ps[i+1])%mod;
    for(int i=1;i<=weeee;i++)((arr[i]-=ps[i+1])+=mod)%=mod;
    arr[1]=arr[2];
    for(int i=1;i<=n;i++)cout<<(arr[i]+mod)%mod<<" ";
}