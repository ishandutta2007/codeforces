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
void solve(){
    ll n,m;cin>>n>>m;
    ll arr[n];
    ll brr[m];
    map<ll,int>occ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        occ[arr[i]]=i;
    }  
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    ll val[2][n];
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        while(s.size()>0 && s.top().F>arr[i]){
            auto j = s.top();
            s.pop();
            val[1][j.second]=i-1;
        }
        s.push({arr[i],i});
    }
    while(s.size()>0){
        auto i = s.top();
        s.pop();
        val[1][i.S]=n-1;
    }
    for(int i=n-1;i>=0;i--){
        while(s.size()>0 && s.top().F>arr[i]){
            auto j = s.top();
            s.pop();
            val[0][j.second]=i+1;
        }
        s.push({arr[i],i});
    }
    while(s.size()>0){
        auto i = s.top();
        s.pop();
        val[0][i.S]=0;
    }
    ll ans = 1;
    for(int i=0;i<m;i++){
        if( occ.find(brr[i])==occ.end() || val[1][occ[brr[i]]]!=n-1 ){
            cout<<0<<"\n";
            return;
        }
    }
    if( val[0][occ[brr[0]]]!=0){
        cout<<0<<"\n";
        return;
    }
    ll j;
    for(int i=0;i<m-1;i++){
        j = val[0][occ[brr[i+1]]];
        ans = mul(ans,occ[brr[i+1]]-j+1);
    }
    cout<<ans<<"\n";
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