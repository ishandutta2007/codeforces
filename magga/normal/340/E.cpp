#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
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
ll fact[2001];
void pre(){
    fact[0]=1;
    for(int i =1;i<=2000;i++){
        fact[i]=mul(fact[i-1],i);
    }
}
ll ncr(ll n,ll r){
    return divi(fact[n],mul(fact[r],fact[n-r]));
}
void solve(){
    ll n;cin>>n;
    ll arr[n+1];
    int oo = 0;
    set<int>s,p;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==-1)
            oo++;
        s.erase(arr[i]);
        if(arr[i]==-1){
            p.insert(i);
        }            
    }    
    ll bo = 0;
    for(auto i:s){
        if(p.find(i)!=p.end()){
            bo++;
        }
    }
    ll ans = fact[oo];
    int j = 1;
    for(int i=1;i<=bo;i++){
        //cout<<ncr(oo,i)<<"\n";
        ans=sub(ans,j*mul(ncr(bo,i),fact[oo-i]));
        //cout<<-1*j*mul(ncr(oo,i),fact[oo-i])<<"\n";
        j*=-1;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}