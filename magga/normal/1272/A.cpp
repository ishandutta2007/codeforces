#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int arr[3];
    long long int brr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    brr[0]=arr[0];brr[1]=arr[1];brr[2]=arr[2];
    bool flag = false; 
    if(arr[0]!=arr[1]){
        brr[0]++;
    }else if(arr[0]==arr[1] && arr[1]!=arr[2]){
        brr[0]++;
        flag = true;
        brr[1]++;
    }
    if(brr[2]!=brr[1]){
        brr[2]--;
    }else if(!flag && arr[2]==arr[1] && brr[0]!=brr[1]){
        brr[2]--;
        brr[1]--;
    }
    long long int ans = abs(brr[0]-brr[1])+ abs(brr[2]-brr[1])+ abs(brr[0]-brr[2]);
    cout<<ans<<"\n";
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