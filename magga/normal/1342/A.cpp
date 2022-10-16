#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int x,y,a,b;cin>>x>>y>>a>>b;
    long long int ans = 0;
    ans+=(max(x,y)-min(x,y))*a+min(x,y)*min(2*a,b);
    cout<<ans<<"\n";
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