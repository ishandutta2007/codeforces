#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int phi(int x){
    int ans=x;
    for(int i=2;i*i<=x;i++){
        if(!(x%i)){
            ans-=ans/i;
            while(!(x%i))x/=i;
        }
    }
    if(x>1)ans-=ans/x;
    return ans;
}
signed main(){
    int n,k;
    cin>>n>>k;
    (k+=1)/=2;
    while(k--){
        n=phi(n);
        if(n==1)break;
    }
    cout<<n%mod<<"\n";
}