#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,u,v;cin>>n;
    vector<long long int>arr[n+1];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(arr[i].size()==2){
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
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}