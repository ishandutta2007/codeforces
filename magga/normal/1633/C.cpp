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
bool check(ll hc,ll dc,ll hm,ll dm){
    return (hc + dm - 1)/dm >= (hm + dc - 1)/dc ;
}
void solve(){
    ll hc,dc,hm,dm,k,w,a;cin>>hc>>dc>>hm>>dm>>k>>w>>a;
    for(int i=0;i<=k;i++){
        if(check(hc + a*i,dc+(k-i)*w,hm,dm)){
            cout<<"YES"<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
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
/*
win condition - (hc + dm - 1)/dm >= (hd + dc - 1)/dc 
hcdc - dc >= hddm - dm

*/