#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int k,b,n,s=0,ans=0;
    cin>>k>>b>>n;
    k--;
    map<int,int> mp;
    mp[0]=1;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        s+=arr[i];
        ans+=mp[(s%k-b+k)%k];
        mp[s%k]++;
    }
    int z=0;
    for(int i=1,j=1;i<=n;i=j){
        j=i+1;
        if(!arr[i]){
            while(j<=n&&!arr[j])j++;
            z+=(j-i)*(j-i+1)/2;
        }
    }
    if(!b)cout<<z<<"\n";
    else if(b==k)cout<<ans-z<<"\n";
    else cout<<ans<<"\n";
}