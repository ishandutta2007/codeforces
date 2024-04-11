#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
int inrange(ll a,ll l,ll r){
    if(a<=r && a>=l) return 1;
    return 0;
}
int check(ll a,ll l,ll r){
    return inrange(a*a,l,r) + inrange(a*a+a,l,r) + inrange(a*a+2*a,l,r);
}
void solve(){
    ll l,r;cin>>l>>r;
    long long int start = max(ll(sqrtl(l)-1),1ll);
    long long int end   = sqrtl(r) + 1;
    ll ans = 0;
    if(end-start<=10){
        for(int i=start;i<=end;i++){
            ans += check(i,l,r);
        }
        cout<<ans<<"\n";
        return;
    }
    int buffer = 4;
    for(int i=start;i<start+buffer;i++){
        ans += check(i,l,r);
    }
    start= start + buffer;
    for(int i=end;i>end-buffer;i--){
        ans += check(i,l,r);
    }
    end = end - buffer;
    ans += (end - start + 1)*3;
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