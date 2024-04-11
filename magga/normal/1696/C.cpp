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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
vector<pii>dissolve(vector<ll>v,ll m){
    vector<pii>ret;
    for(auto i:v){
        ll k = i;
        ll t = 1;
        while(k%m==0){
            k/=m;
            t*=m;
        }
        if(ret.size()>0 && ret.back().F==k){
            ret.back().S+=t;
        }else{
            ret.push_back({k,t});
        }
    }
    return ret;
}
void solve(){
    ll n,m;cin>>n>>m;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll k;cin>>k;
    vector<ll>b(k);
    for(int i=0;i<k;i++) cin>>b[i];
    if(dissolve(a,m)==dissolve(b,m)){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
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