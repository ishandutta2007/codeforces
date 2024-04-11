#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n,s=0;
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        s+=x;
    }
    int z=s%n;
    cout<<z*(n-z)<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}