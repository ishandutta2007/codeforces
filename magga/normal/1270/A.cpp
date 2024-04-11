#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,k1,k2,d;cin>>n>>k1>>k2;
    bool flag = false;
    for(long long int i=0;i<k1;i++){
        cin>>d;
        if(d==n){
            flag=true;
        }
    }
    for(long long int i=0;i<k2;i++){
        cin>>d;
    }
    if(flag){
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