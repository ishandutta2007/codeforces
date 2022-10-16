#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int a,b,p;cin>>a>>b>>p;
    string s;cin>>s;
    long long int curr = 0 ;
    long long int n = s.size();
    char ls = s[n-2];
    if(ls=='A'){
        curr+=a;
    }else{
        curr+=b;
    }
    if(curr>p){
        cout<<n<<"\n";
        return;
    }
    for(long long int i=n-3;i>=0;i--){
        if(s[i] == ls){
            continue;
        }
        if(s[i]=='A'){
            curr+=a;
            ls='A';
        }else{
            curr+=b;
            ls='B';
        }
        if(curr>p){
            cout<<i+2<<"\n";
            return;
        }
    }
    cout<<1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}