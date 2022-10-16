#include<bits/stdc++.h>
using namespace std;
#define push_back pb;
typedef long long int ll;
void pre(){}
void solve(){
    ll n,m;cin>>n>>m;
    ll arr[n][m];
    ll curr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            arr[i][j]-=j+1;
        }
    }
    ll ans = 0;
    for(ll i=0;i<m;i++){
        map<int,int>m1;
        for(ll j=0;j<n;j++){
            if(arr[j][i]%m==0 && arr[j][i]/m<n){
                curr[j][i]=(j-(arr[j][i]/m)+n)%n;
                m1[(j-(arr[j][i]/m)+n)%n]++;
            }else{
                curr[j][i]=-1;
            }
        }
        ll o = n;
        for(auto i:m1){
            o=min(o,i.first+n-i.second);
        }
        ans+=o;
    }
    cout<<ans<<"\n";
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