#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
signed main(){
    int n,k;string s;
    set<char> vis;
    cin>>n>>k>>s;
    for(auto i:s)vis.insert(i);
    auto x=*vis.begin();
    if(n<k){
        for(int i=n;i<k;i++)s+=x;
    }
    else{
        s.resize(k);
        for(int i=k-1;i>=0;i--){
            auto wa=next(vis.find(s[i]));
            if(wa==vis.end()){
                s[i]=x;
                continue;
            }
            s[i]=*wa;
            break;
        }
    }
    cout<<s<<"\n";
}