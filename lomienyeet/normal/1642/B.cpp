#include <bits/stdc++.h>
using namespace std;
void eat(){
    int n,ans=1;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<n;i++)ans+=(arr[i]!=arr[i+1]);
    for(int i=1;i<=ans;i++)cout<<ans<<" ";
    for(int i=ans+1;i<=n;i++)cout<<++ans<<" ";
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)eat();
}