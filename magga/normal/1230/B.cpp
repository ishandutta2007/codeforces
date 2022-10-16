#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k;cin>>n>>k;
    string s;cin>>s;
    if(n==1 && k>0){
        cout<<0<<"\n";
        return;
    }
    if(s[0]!='1' && k>0){
        k--;
        s[0]='1';
    }
    for(int i=1;i<n;i++){
        if(s[i]!='0' && k>0){
            k--;
            s[i]='0';
        }
    }
    cout<<s<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}