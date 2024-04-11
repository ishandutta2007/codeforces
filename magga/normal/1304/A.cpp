#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int x,y,a,b;cin>>x>>y>>a>>b;
    if((y-x)%(a+b)==0){
        cout<<(y-x)/(a+b)<<"\n";
    }else{
        cout<<"-1"<<"\n";
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