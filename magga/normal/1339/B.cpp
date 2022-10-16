#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    long long int ans[n];
    int start = n-1;
    int end  = 0;
    for(int i=n-1;i>=0;i--){
        if((n-i)%2==1){
            ans[i]=arr[start];
            start--;
        }else{
            ans[i]=arr[end];
            end++;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}