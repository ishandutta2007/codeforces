#include<bits/stdc++.h>
using namespace std;
void pre(){}
bool count(long long int n,int i){
    long long int ret = 0;
    long long int oo = n;
    while(n>0){
        if(n%2==1){
            ret++;
        }
        n/=2;
    }
    if(i<ret){
        return false;
    }else if(i>oo){
        return false;
    }
    return true;
}
void solve(){
    long long int n,p;cin>>n>>p;
    long long int ans = -1;
    for(long long int i = 1;i<=32;i++){
        if(count(n-p*i,i)){
            ans=i;
            break;
        }
    }
    //cout<<count(28)<<"\n";
    cout<<ans<<"\n";
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