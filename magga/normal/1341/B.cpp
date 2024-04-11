#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k;cin>>n>>k;
    long long int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans[n];
    for(int i=0;i<n;i++)ans[i]=0;
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            ans[i]=1;
        }else{
            ans[i]=0;
        }
    }
    int curr = 0;
    int ans1 = -1;int max = 0;
    for(int i=1;i<n-1;i++){
        if(i<k-1){
            curr+=ans[i];
            max=curr;
            continue;
        }
        curr-=ans[i-k+2];
        curr+=ans[i];
        //cout<<curr<<" ";
        if(curr>max){
            max=curr;
            ans1=i-k+1;
        }
    }
    cout<<max+1<<" "<<ans1+2<<"\n";
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