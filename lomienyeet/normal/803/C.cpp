// hi commentators may i know why the fuck this q need int128?
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,k;
    cin>>n>>k;
    if(k>1000000||((k*(k+1))>>1)>n){
        cout<<"-1\n";
        return 0;
    }
    int z=n*2/(k*(k+1)),ee=min(z,(int)(sqrt(n))),ans=1;
    for(int i=1;i<=ee;i++){
        if(!(n%i)){
            if(n/i<=z)ans=max(ans,n/i);
            else ans=max(ans,i);
        }
    }
    for(int i=1;i<k;i++)cout<<ans*i<<" ";
    cout<<ans*(n/ans-(((k-1)*k)/2))<<"\n";
}