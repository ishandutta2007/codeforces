#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,d;cin>>n>>d;
    if(n>0 && (n-1)*(n-1)-4*(d-n)>=0){
        cout<<"YES"<<"\n";
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