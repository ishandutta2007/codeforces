// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int l=0,r=0,ptr=n,ans=0;
    for(int i=1;i<=n;i++){
        l+=arr[i];
        while(ptr>0&&l>r)r+=arr[ptr--];
        if(l==r&&i<=ptr)ans=max(ans,n+i-ptr);
    }
    cout<<ans<<"\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}