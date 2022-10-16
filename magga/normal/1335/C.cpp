#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,d;cin>>n;
    map<long long int,long long int>m;
    for(int i=0;i<n;i++){
        cin>>d;
        m[d]++;
    }
    long long int ma = 0;
    for(auto i:m){
        ma=max(i.second,ma);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(ma>i && m.size()>=i){
            ans=i;
        }else if(ma==i && m.size()>i){
            ans=i;
        }
    }
    cout<<ans<<"\n";
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