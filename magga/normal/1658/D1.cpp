#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
void solve(){
    ll l,r;cin>>l>>r;
    ll arr[r-l+1];
    for(int i=0;i<(r-l+1);i++){
        cin>>arr[i];
    }
    vector<ll>curr;
    for(auto i:arr)
        curr.push_back(i);
    if((r-l+1)&(r-l)){
        int ans = 0;
        for(ll i=17;i>=0;i--){
            int in = 0;
            int out = 0;
            for(int j=0;j<curr.size();j++){
                if((1ll<<i)&curr[j]){
                    in++;
                }else{
                    out++;
                }
            } 
            if(out==0){
                ans|=(1ll<<i);
                for(auto &j:curr){
                    j^=(1ll<<i);
                }
            }else if(in==0){
                continue;
            }else if(out>in){
                vector<ll>new_arr;
                for(auto j:curr){
                    if((1ll<<i)&j) new_arr.push_back(j^(1ll<<i));
                }
                swap(curr,new_arr);
            }else{
                vector<ll>new_arr;
                ans|=(1ll<<i);
                for(auto j:curr){
                    if((1ll<<i)&j){}   
                    else new_arr.push_back(j^(1ll<<i));
                }
                swap(curr,new_arr);
            }
        }
        cout<<ans<<"\n";
    }else{
        cout<<arr[0]<<"\n";
    }
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