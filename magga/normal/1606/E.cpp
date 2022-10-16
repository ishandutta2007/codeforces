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

const long long int mod = 998244353;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
ll cache[501][501];
ll fact[200001];
ll ncr(ll n,ll r){
    return divi(fact[n],mul(fact[r],fact[n-r]));
}
// Please write the recurances once :(
ll dp(ll n,ll x){
    if(n==1 || x<=0) return 0;
    if(n==0) return 0;
    if(cache[n][x]!=-1) return cache[n][x];
    cache[n][x] = 0;
    ll curr = 0;
    while(curr!=x){
        ll temp = min(x-curr,n-1);
        curr += temp;
        cache[n][x] = add(cache[n][x],power(temp,n));
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<x;j+=(n-1)){
            cache[n][x] = add(cache[n][x],mul(ncr(n,i),mul(dp(n-i,x-j-n+1),power(n-1,i))));
        }
    }
    return cache[n][x];
}
void pre(){
    fact[0]=1;
    for(int i=1;i<=20000;i++) fact[i] = mul(fact[i-1],i);
}
void solve(){
    int n,x; cin>>n>>x;
    for(auto &i:cache)
        for(auto &j:i)
            j = -1;
    cout<<dp(n,x)<<"\n";
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