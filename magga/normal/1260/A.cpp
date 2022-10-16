#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int c,s;cin>>c>>s;
    long long int a = s/c;
    long long int b = s%c;
    long long int ans = (c-b)*(a*a)+b*(a+1)*(a+1);
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