#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int mini=1e18,maxi=-1e18,s=0;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        s+=abs(arr[i]);
        maxi=max(maxi,arr[i]);
        mini=min(mini,arr[i]);
    }
    if(n==1){
        cout<<arr[1]<<"\n";
        return 0;
    }
    if(mini>=0)cout<<s-mini*2<<"\n";
    else if(maxi<=0)cout<<s+maxi*2<<"\n";
    else cout<<s<<"\n";
}