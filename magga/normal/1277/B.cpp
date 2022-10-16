#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,d;cin>>n;
    set<long long int>s;
    long long int ans =0;
    for(long long int i=0;i<n;i++){
        cin>>d;
        while(s.find(d)==s.end() && d%2==0){
            s.insert(d);
            d/=2;
            ans++;
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