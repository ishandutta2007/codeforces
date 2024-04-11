#include <bits/stdc++.h>
using namespace std;
void eat(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1,x;j<=m;j++){
            cin>>x;
            cout<<x+((x&1)==((i+j)&1))<<" ";
        }
        cout<<"\n";
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}