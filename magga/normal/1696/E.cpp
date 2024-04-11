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

const long long int mod = 1e9+7;
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

long long fact[1000001];
long long ifact[1000001];
long long inverses[1000001];
void setFactorial(){
    fact[0]=1;
    ifact[0]=1;
    inverses[1]=1;
    for(int i=1;i<=1000000;i++){
        fact[i] = mul(fact[i-1],i);
        if(i>1) inverses[i] = mod - (mod/i) * inverses[mod%i] % mod;
        ifact[i] = mul(ifact[i-1],inverses[i]);
    }
}
ll ncr(ll n,ll r){
    if(n<0 || r<0 || n<r) return 0;
    return mul(fact[n],mul(ifact[r],ifact[n-r]));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n;cin>>n;
    ll arr[n+1];
    ll ans = 0;
    int last = n+1;
    for(int i=0;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==0){}
        ans = add(ans,ncr(arr[i]+i,i+1));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    setFactorial();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}