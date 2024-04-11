#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    int ans=s.length();
    for(int i=1;i<=n;i++){
        (ans+=(ans-i)*(s[i-1]-'1'))%=mod;
        if(s.length()<n){
            string wao=s.substr(i);
            for(int j=0;j<s[i-1]-'1';j++)s+=wao;
        }
    }
    cout<<(ans+mod)%mod<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}