#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main(){
    string s;
    cin>>s;
    int n=s.length(),arr[n];
    for(int i=0;i<n;i++)arr[i]=s[i]-'0';
    int ans=0,z=0,ptr=1;
    for(int i=n-1;i>=0;i--){
        int weeee=((((i*(i+1))/2)%mod*ptr)%mod+z)%mod;
        (z+=(ptr*(n-i))%mod)%=mod;
        (ptr*=10)%=mod;
        (ans+=(weeee*arr[i])%mod)%=mod;
    }
    cout<<ans<<"\n";
}