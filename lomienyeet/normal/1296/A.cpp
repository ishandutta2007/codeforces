#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N,wtf=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        if(temp%2==1)wtf++;
    }
    if ((wtf%2==1||(wtf%2==0&&wtf<N))&&wtf) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}