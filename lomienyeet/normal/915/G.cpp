#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
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
    int n,k,ans=0;
    cin>>n>>k;
    int arr[k+1]={},ps[k+1]={};
    for(int i=1;i<=k;i++){
        ps[i]=(ps[i-1]+arr[i])%mod;
        int x=((bm(i,n)-ps[i])%mod+mod)%mod;
        (ans+=x^i)%=mod;
        for(int j=2;i*j<=k;j++){
            arr[i*j]+=x;
            if((i+1)*j<=k)arr[(i+1)*j]-=x;
        }
    }
    cout<<ans<<"\n";
}