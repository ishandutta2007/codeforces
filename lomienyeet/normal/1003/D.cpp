#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    map<int,int> mp;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    vector<pair<int,int> > v;
    for(auto i:mp)v.push_back(i);
    reverse(v.begin(),v.end());
    while(q--){
        int x,s=0;
        cin>>x;
        for(auto i:v){
            int z=min(x/i.first,i.second);
            s+=z;
            x-=i.first*z;
        }
        cout<<(!x?s:-1)<<"\n";
    }
}