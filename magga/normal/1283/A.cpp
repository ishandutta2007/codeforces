#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int a,b;cin>>a>>b;
    cout<<(23-a)*60+(60-b)<<"\n";
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