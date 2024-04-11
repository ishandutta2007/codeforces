#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int a,b;cin>>a>>b;
    long long int m,n;
    m = max(a,b);
    n = min(a,b);
    if(m<=2*n && (m+n)%3==0){
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