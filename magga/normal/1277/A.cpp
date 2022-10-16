#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin>>n;
    long long int ans=0;
    if(n<10){
        ans=n;
    }else{
        ans+=9;
    }
    if(n<100){
        ans+=n/11;
    }else{
        ans+=9;
    }
    if(n<1000){
        ans+=n/111;
    }else{
        ans+=9;
    }
    if(n<10000){
        ans+=n/1111;
    }else{
        ans+=9;
    }
    if(n<100000){
        ans+=n/11111;
    }else{
        ans+=9;
    }
    if(n<1000000){
        ans+=n/111111;
    }else{
        ans+=9;
    }
    if(n<10000000){
        ans+=n/1111111;
    }else{
        ans+=9;
    }
    if(n<100000000){
        ans+=n/11111111;
    }else{
        ans+=9;
    }
    if(n<1000000000){
        ans+=n/111111111;
    }else{
        ans+=9;
    }
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