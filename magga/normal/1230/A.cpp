#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    int arr[4];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    sort(arr,arr+4);
    if(arr[0]+arr[3]==arr[1]+arr[2]){
        cout<<"YES"<<"\n";
    }else if(arr[3]==arr[1]+arr[0]+arr[2]){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}