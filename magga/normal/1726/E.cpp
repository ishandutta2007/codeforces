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

const long long int MAXN = 1000001;
long long fact[MAXN];
long long ifact[MAXN];
long long inverses[MAXN];
void setFactorial(){
    fact[0]=1;
    ifact[0]=1;
    inverses[1]=1;
    for(int i=1;i<MAXN;i++){
        fact[i] = mul(fact[i-1],i);
        if(i>1) inverses[i] = mod - (mod/i) * inverses[mod%i] % mod;
        ifact[i] = mul(ifact[i-1],inverses[i]);
    }
}

long long ncr(long long n,long long r){
    if(r<0 || n<0 || n<r) return 0;
    return mul(fact[n],mul(ifact[r],ifact[n-r]));
}

long long int brute(int n){
    int curr = 1;
    vector<int>p;
    for(int i=1;i<=n;i++){
        curr*=i;
        p.push_back(i-1);
    }
    int ans = 0;

    for(int i=0;i<curr;i++){
        vector<int>k(n);
        for(int i=0;i<n;i++) k[p[i]] = i;
        bool a = 1;
        for(int i=0;i<n;i++) if(abs(k[i]-p[i])>=2) a = 0;
        ans += a;
        next_permutation(p.begin(),p.end());        
    }
    return ans;
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int dp[300001];
void pre(){
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<300001;i++){
        dp[i] = add(dp[i-1],mul(dp[i-2],i-1));
    }
}
long long int pairing(int n){
    return divi(mul(ncr(n,n/2),fact[n/2]),1);
}
void solve(){
    int n;cin>>n;
    long long int ans = 0;
    for(int i=0;i<=n;i+=4){
        long long int p = i/2;
        ans = add(ans,mul(mul(mul(power(1,p/2),ncr(n-p,p)),dp[n-i]),pairing(p)));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    // for(int i=1;i<10;i++) cout<<brute(i)<<" ";
    // cout<<"\n";
    setFactorial();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}