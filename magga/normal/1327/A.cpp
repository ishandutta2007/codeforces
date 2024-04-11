#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k;cin>>n>>k;
    if(k*k<=n && k%2==n%2){
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
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}