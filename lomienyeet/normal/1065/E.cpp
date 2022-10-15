// 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
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
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[m+1]={},ans=1;
    for(int i=1;i<=m;i++)cin>>arr[i];
    for(int i=1;i<=m;i++){
        int wa=bm(k,arr[i]-arr[i-1]);
        (ans*=(wa*(wa+1))%mod)%=mod;
    }
    (((ans*=bm(k,n-arr[m]*2))%=mod)*=bm(bm(2,m),mod-2))%=mod;
    cout<<ans<<"\n";
}