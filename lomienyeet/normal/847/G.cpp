#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            if(s[j]=='1')mp[j]++;
        }
    }
    int mx=0;
    for(auto i:mp)mx=max(mx,i.second);
    cout<<mx<<"\n";
}