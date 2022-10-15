#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;string s;
    cin>>n>>k>>s;
    string ans(k,'z'),tp="";
    for(int i=0;i<s.length();i++){
        tp.push_back(s[i]);
        string e=tp;
        while(e.length()<k)e+=e;
        while(e.length()>k)e.pop_back();
        ans=min(ans,e);
    }
    cout<<ans<<"\n";
}