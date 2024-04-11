#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int ans =0;
    long long int arr[6];
    for(long long int i=0;i<6;i++){
        cin>>arr[i];
    }
    if(arr[4]>arr[5]){
        ans += arr[4]*min(arr[0],arr[3]);
        arr[3]-=min(arr[0],arr[3]);
        ans += arr[5]*min(arr[3],min(arr[1],arr[2]));
    }else{
        ans += arr[5]*min(arr[3],min(arr[1],arr[2]));
        arr[3]-=min(min(arr[1],arr[2]),arr[3]);
        ans += arr[4]*min(arr[0],arr[3]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
   // cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}