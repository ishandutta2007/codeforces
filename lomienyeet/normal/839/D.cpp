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
    int n;
    cin>>n;
    int freq[1000005]={};
    while(n--){
        int x;
        cin>>x;
        freq[x]++;
    }
    int ans[1000005]={};
    for(int i=1000004;i>1;i--){
        int tot=0,cur=0;
        for(int j=i;j<1000005;j+=i){
            tot+=freq[j];
            (cur+=ans[j])%=mod;
        }
        if(tot)ans[i]=(tot*bm(2,tot-1))%mod;
        ((ans[i]-=cur)+=mod)%=mod;
    }
    int toto=0;
    for(int i=2;i<1000005;i++)(toto+=(i*ans[i])%mod)%=mod;
    cout<<toto<<"\n";
}