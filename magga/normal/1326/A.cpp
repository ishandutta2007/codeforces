#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    if(n==1){
        cout<<-1<<"\n";
        return;
    }
    cout<<2;
    for(long long int i=0;i<n-1;i++)
        cout<<3;
    cout<<"\n";    
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