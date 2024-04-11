#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a,b;
    cin>>a>>b;
    if(gcd(a,b)!=1){
        cout<<"Impossible\n";
        return 0;
    }
    vector<pair<int,char> > v;
    while(a&&b){
        if(a>b){
            v.push_back({a/b,'A'});
            a%=b;
        }
        else{
            v.push_back({b/a,'B'});
            b%=a;
        }
    }
    v.back().first--;
    for(auto i:v)cout<<i.first<<i.second;
}