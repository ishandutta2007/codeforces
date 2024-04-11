#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,d;cin>>n;
    set<long long int>s;
    for(long long int i=0;i<n;i++){
        cin>>d;
        s.insert(d);
    }
    cout<<s.size()<<"\n";
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