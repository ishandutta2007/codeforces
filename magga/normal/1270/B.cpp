#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool flag = false;
    long long int index = -1;
    for(long long int i = 0;i<n-1;i++){
        if(abs(arr[i] - arr[i+1]) > 1){
            flag = true;
            index=i+1;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<"\n";
        cout<<index<<" "<<index+1<<"\n";
    }else{
        cout<<"NO"<<"\n";
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