#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int aa =2;
void solve(){
    long long int n,x;cin>>n>>x;
    long long int arr[n];
    bool flag = false;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==x){
            flag = true;
        }
    }
    sort(arr,arr+n);
    if(flag){
        cout<<1<<"\n";
        return;
    }
    long long int ans = 1e10;
    for(long long int i = 0;i<n;i++){
        if(arr[i]>x){
            ans=min(ans,aa);
            break;
        }
        if(x%arr[i]==0){
            ans=min(ans,x/arr[i]);
        }else{
            ans=min(ans,(x/arr[i])+1);
        }
    }
    cout<<ans<<"\n";
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