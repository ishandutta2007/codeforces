#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll N;
    cin>>N;
    N++;
    if(N==1){
        cout<<"0\n";
        return;
    }
    if(N%2==0){
        N/=2;
    }
    cout<<N<<"\n";
}
int main(){
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}