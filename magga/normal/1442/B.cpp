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

void pre(){}
map<int,int>f,ba;
int ans = 1;
set<ll>s;
void calculate( ll c ){
    s.erase(c);
    ll ret = 2;
    if( s.find(f[c])!=s.end() ){
        ret--;
    }
    if( s.find(ba[c])!=s.end() ){
        ret--;
    }
    ans = mul(ans,ret);
    ll a = f[c];
    ll b = ba[c];
    if(a!=-1)
        ba[a] = b;
    if(b!=-1){
        f[b] = a; 
    }
}
void solve(){
    ll n,k;cin>>n>>k;
    ll arr[n];
    ans = 1;
    for(int i=0;i<n;i++) cin>>arr[i];
    f.clear();
    ba.clear();
    for(int i=0;i<n-1;i++){
        f[arr[i]] = arr[i+1];
    }
    for(int i=1;i<n;i++){
        ba[arr[i]] = arr[i-1];
    }
    f[arr[n-1]] = -1;
    ba[arr[0]] = -1;
    s.clear();
    s.insert(-1);
    ll brr[k];
    for(int i=0;i<k;i++){
        cin>>brr[i];
        s.insert(brr[i]);
    }
    for(int i=0;i<k;i++)
        calculate(brr[i]);
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