#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int a,b;cin>>a>>b;
    if(a%b==0){
        cout<<0<<"\n";
    }else{
        cout<<(a/b+1)*b-a<<"\n";
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