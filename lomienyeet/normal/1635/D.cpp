#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main(){
    int n,p;
    cin>>n>>p;
    int arr[n],fib[p+2]={};
    fib[0]=fib[1]=1;
    for(int i=2;i<p+2;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int ans=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int z=arr[i],ok=1;
        while(z){
            if(z&1)z>>=1;
            else if(z%4==0)z/=4;
            else break;
            if(mp[z]){
                ok=0;
                break;
            }
        }
        if(!ok)continue;
        mp[arr[i]]=1;
        ok^=1;
        while((1<<(ok+1))<=arr[i])ok++;
        (((ans+=fib[max(p-ok+1,0ll)])-=1)+=mod)%=mod;
    }
    cout<<ans<<"\n";
}