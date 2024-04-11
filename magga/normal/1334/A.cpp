#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,u,v;cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=1;i<n;i++){
        if(arr[i].first-arr[i-1].first<arr[i].second-arr[i-1].second){
            cout<<"NO"<<"\n";
            return;
        }
        if(arr[i].first<arr[i-1].first || arr[i].second<arr[i-1].second){
            cout<<"NO"<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i].first<arr[i].second){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
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