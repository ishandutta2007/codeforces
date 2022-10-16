#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,d,k;cin>>n>>k;
    long long int sum = 0;
    long long int ans = 0;
    multiset<long long int>s;
    for(int i=0;i<n;i++){
        cin>>d;
        if(d>=k){
            sum+=d-k;
            ans++;
        }else{
            s.insert(k-d);
        }
    }
    for(auto i:s){
        if(i<=sum){
            sum-=i;
            ans++;
        }else{
            break;
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