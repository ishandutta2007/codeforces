#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,s,d,ans=1;cin>>n>>s;
    long long int i=0;
    long long int max=0;
    long long int arr[n];
    for(;i<n;i++){
        cin>>arr[i];
    }
    i=0;
    while(s >= 0 && i <= n-1){
        s-=arr[i];
        if(arr[i]>max){
            max=arr[i];
            ans=i+1;
        }
        i++;
    }
    if(i==n && s>=0){
        cout<<0<<"\n";
    }else{
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}