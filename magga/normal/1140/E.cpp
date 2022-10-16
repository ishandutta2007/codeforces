#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
const long long int mod = 998244353;//1e9+7;
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
ll n,k,d;
vector<ll>odd;
vector<ll>eve;
void pre(){}
ll ans = 1;
void cac(ll l, ll r,ll n){
    if(n==0 && l!=r){
        return;
    }else if(n==0){
        ans = 0;
        return;
    }
    if(l==0 && r==0){
        ans*=mul(k,power(k-1,n-1));
        ans%=mod;
        return;
    }else if(l==0){
        ans*=power(k-1,n);
        ans%=mod;
        return;
    }else if(r==0){
        ans*=power(k-1,n);
        ans%=mod;
        return;
    }
    ll dp[2][n];
    if(l!=r){
        dp[0][0]=1;
        dp[1][0]=k-2;
    }else{
        dp[0][0]=0;
        dp[1][0]=k-1;
    }
    for(int i=1;i<n;i++){
        dp[0][i] = dp[1][i-1];
        dp[1][i] = add(mul(dp[0][i-1],k-1),mul(dp[1][i-1],k-2));
    }
    ans = mul(ans,dp[1][n-1]);
}
void account(vector<ll> a){
    ll lst = 0;
    ll count = 0;
    ll n= a.size();
    for(int i = 1;i<n;i++){
        if(a[i]==-1){
            count++;
        }else{
            cac(lst,a[i],count);
            lst = a[i];
            count=0;
        }
    }
}
void solve(){
    cin>>n>>k;
    eve.push_back(0);
    odd.push_back(0);
    for(int i=0;i<n;i++){
        cin>>d;
        if(i%2==0)
            eve.push_back(d);
        else
            odd.push_back(d);
    }
    eve.push_back(0);
    odd.push_back(0);
    account(odd);
    account(eve);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); 
}