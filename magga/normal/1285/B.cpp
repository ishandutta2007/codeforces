#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    long long int b =0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        b+=arr[i];
    }
    long long int dp =0;
    bool flag = false;
    for(long long int i=0;i<n-1;i++){
        dp+=arr[i];
        if(dp<=0){
            flag=true;
            dp=0;
        }
        if(dp>=b){
            cout<<"NO"<<"\n";
            return;
        }
    }
    dp+=arr[n-1];
    if(dp>=b && flag){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
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