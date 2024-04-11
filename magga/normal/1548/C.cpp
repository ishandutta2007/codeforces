#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
// Please write the recurances once :(
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
long long int sub(long long int a,long long int b){
    long long int ret = (a-b)%mod;
    if(ret<0){
        return ret+mod;
    }
    return ret;
}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
long long int fact[3001009];
long long int ifact[3001009];
long long int inv1[3001009];
void pre(){
    fact[0]=1;
    ifact[0]=1;
    inv1[1] = 1;
    for(int i = 2; i < 3001000; ++i)
        inv1[i] = mod - (mod/i) * inv1[mod%i] % mod;
    for(int i=1;i<=3001000;i++) fact[i] = mul(fact[i-1],i);
    for(int i=1;i<=3001000;i++) ifact[i] = mul(inv1[i],ifact[i-1]);
}
long long int ncr(long long int n,long long int r){
    return mul(fact[n],mul(ifact[n-r],ifact[r]));
}
vector<long long int>division(vector<long long int>&x,vector<long long int>&p){
    vector<long long int>ret(x.size()-p.size()+1);
    reverse(p.begin(),p.end());
    reverse(x.begin(),x.end());
    for(int i=0;i<ret.size();i++){
        ret[i] = x[i];
        for(int j=0;j<p.size();j++){
            x[i+j]=sub(x[i+j],ret[i]*p[j]);
        }
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
void solve(){
    long long int n,q;cin>>n>>q;
    vector<long long int>x(3*n+3);
    vector<long long int>p{3,3,1};
    long long int curr = fact[3*n+3];
    for(int i=0;i<3*n+3;i++){
        x[i]=ncr(3*n+3,i+1);
    }
    auto ans = division(x,p);
    for(int i=0;i<q;i++){
        int p;cin>>p;
        cout<<ans[p]<<"\n";
    }
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