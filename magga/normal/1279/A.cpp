#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    if(arr[2]>1+arr[0]+arr[1]){
        cout<<"No"<<"\n";
    }else{
        cout<<"Yes"<<"\n";
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