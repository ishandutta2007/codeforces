#include<bits/stdc++.h>
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    ll ans = 0;
    for(auto i:s){
        if(i=='1') ans+=11;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            if(k>=(n-i-1)){
                if(i!=n-1) swap(s[n-1],s[i]);
                k-=(n-i-1);
                ans-=10;
            }
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(s[i]=='1'){
            if(k>=i){
                ans-=1;
            }
            break;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int i=0;i<t;i++)
        solve();
}