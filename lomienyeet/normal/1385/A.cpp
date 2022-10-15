#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a,a+3,greater<int>());
    int x=a[0],y=a[1],z=a[2];
    if(x!=y and y!=z){
        cout<<"NO\n";
        return;
    }
    if(x>z and y>z){
        cout<<"YES\n"<<x<<" "<<z<<" "<<z<<"\n";
        return;
    }
    if(x==y and y==z){
        cout<<"YES\n"<<x<<" "<<y<<" "<<z<<"\n";
        return;
    }
    else cout<<"NO\n";
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}