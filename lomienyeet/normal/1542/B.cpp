#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n,a,b;
    cin>>n>>a>>b;
    int s=1;
    while(s<=n){
        if(!((n-s)%b)){
            cout<<"Yes\n";
            return;
        }
        s*=a;
        if(a==1)break;
    }
    cout<<"No\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}