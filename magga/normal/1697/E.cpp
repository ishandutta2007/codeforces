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

long long fact[1001];
long long ifact[1001];
long long inverses[1001];
void setFactorial(){
    fact[0]=1;
    ifact[0]=1;
    inverses[1]=1;
    for(int i=1;i<=1000;i++){
        fact[i] = mul(fact[i-1],i);
        if(i>1) inverses[i] = mod - (mod/i) * inverses[mod%i] % mod;
        ifact[i] = mul(ifact[i-1],inverses[i]);
    }
}
ll ncr(ll n,ll r){
    if(n<0 || r<0 || r>n) return 0;
    return mul(fact[n],mul(ifact[r],ifact[n-r]));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
ll dist(pii a,pii b){
    return abs(a.F - b.F) + abs(a.S - b.S);
}
void solve(){
    int n;cin>>n;
    pii arr[n];
    for(int i=0;i<n;i++) cin>>arr[i].F>>arr[i].S;
    pair<ll,bitset<100>>dp[n];
    for(int i=0;i<n;i++){
        bitset<100> ref;
        ref[i] = 1;
        dp[i] = {1e18,ref};
        for(int j=0;j<n;j++){
            if(i==j) continue;
            ll t = dist(arr[i],arr[j]);
            if(t>dp[i].F) continue;
            else if(t==dp[i].F) dp[i].S[j] = 1;
            else{
                dp[i].F = t;
                dp[i].S = ref;
                dp[i].S[j] = 1;
            } 
        }
    }
    vector<bitset<100>>components;
    vector<bool>flag(n);
    for(int i=0;i<n;i++){
        if(flag[i]) continue;
        bool combined = true;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(dp[i].S[j]){
                if(dp[i].S != dp[j].S) combined = false;
            }
        }
        if(combined){
            components.push_back(dp[i].S);
            for(int j=0;j<n;j++){
                if(dp[i].S[j]){
                    flag[j] = true;
                }
            }
        }else{
            bitset<100> ref;
            ref[i] = 1;
            components.push_back(ref);
            flag[i] = true;
        }
    }
    vector<ll>numberOfColours(n+1);
    numberOfColours[0]=1;
    for(auto i:components){
        vector<ll>nC(n+1);
        int next = i.count();
        for(int j=n;j>=0;j--){
            if(numberOfColours[j]==0) continue;
            nC[j+next] += numberOfColours[j];
            if(next>1) nC[j+1]    += numberOfColours[j];
        }
        swap(nC,numberOfColours);
    }
    ll ans = 0;
    for(int i=0;i<=n;i++){
        ans = add(ans,mul(mul(fact[i],ncr(n,i)),numberOfColours[i]));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    setFactorial();
    solve();   
}