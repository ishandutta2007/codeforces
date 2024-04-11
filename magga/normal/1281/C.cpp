#include<bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void solve(){
    long long int x;cin>>x;
    string s;cin>>s;
    s.reserve(10000000);
    long long int ans = s.size();
    for(long long int i=0;i<x;i++){
        long long int ref = int(s[i]) - int('0');
        long long int wol = ans-i-1;
        if(wol<0){
            wol+=mod;
        }
        ans+=((wol)*(ref-1))%mod;
        ans%=mod;
        if(s.size()<x*5){
            long long int j=1;
            string p = s.substr(i+1);
            while(s.size()<x*5 && j<ref){
                s.append(p);
                j++;
            }   
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}