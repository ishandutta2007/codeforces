#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
vector<ll>factors(ll x){
    ll sqrt_x = sqrt(x);
    vector<ll>ret;
    for(int i=1;i<=sqrt_x;i++){
        if(x%i==0){
            ret.push_back(i);
            ret.push_back(x/i);
        }
    } 
    return ret;
}
void solve(){
    ll w,l;cin>>w>>l;
    set<ll>possible;
    for(int i=0;i<16;i++){
        ll wb[2]{w-2,w-2};
        ll lb[2]{l-2,l-2};
        for(int j=0;j<4;j++){
            if(i&(1<<j)){
                if(j<2){
                    wb[0]++;
                }else{
                    wb[1]++;
                }
            }else{
                if(j%2){
                    lb[0]++;
                }else{
                    lb[1]++;
                }
            }
        }
        ll g = __gcd(__gcd(wb[0],wb[1]),__gcd(lb[0],lb[1]));
        auto nums = factors(g);
        for(auto i:nums){
            possible.insert(i);
        }
    }
    cout<<possible.size()<<" ";
    for(auto i:possible){
        cout<<i<<" ";
    }
    cout<<"\n";
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