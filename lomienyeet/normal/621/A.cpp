#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,s=0,mn=7e13; // seventy three
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        s+=x;
        if(x&1)mn=min(mn,x);
    }
    if(s&1)s-=mn;
    cout<<s<<"\n";
}