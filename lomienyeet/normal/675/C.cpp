#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,s=0,opt=0;
    cin>>n;
    map<int,int> mp;
    for(int i=0,x;i<n;i++){
        cin>>x;
        s+=x;
        mp[s]++;
        opt=max(opt,mp[s]);
    }
    cout<<n-opt<<"\n";
}