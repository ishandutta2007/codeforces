#include <bits/stdc++.h>
using namespace std;
void solve(){
    //why is this task bullying me
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e=min(d/c,a);
    e=d-e*c;
    if(e>b)cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}