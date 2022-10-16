#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    string a,b,c;cin>>a>>b>>c;
    for(long long int i=0;i<a.size();i++){
        if(a[i]==c[i] || b[i]==c[i]){
            continue;
        }
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
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