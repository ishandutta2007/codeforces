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
typedef long long int ll;
using namespace std;
ll dp[2][300001]{0};
const long long int mod = 1e9+9;
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
void fix(ll &a){a%=mod;}
ll c1 = 276601605;
ll c2 = 691504013;
ll c3 = 308495997;
int n;
const int MAX = 300000;
ll t[2*MAX];
long long int si[2*MAX]{0};
ll sip[2*MAX]{0};
int h = sizeof(int) * 8 - __builtin_clz(MAX);
pair<long long int,ll> d[MAX];
pii combine(pii a,pii b){
    a.first+=b.first;
    a.second+=b.second;
    fix(a.first);fix(a.second);
    return a;
}
pii as(pii lp,int a){
    lp.first=mul(lp.first,power(c2,a));
    lp.second=mul(lp.second,power(c3,a));
    return lp;
}
void buil(){
    for(long long int i=n-1;i>0;i--) t[i]=add(t[i<<1],t[i<<1|1]);
    for(int i=0;i<n;i++) si[n+i]=1;
    for(int i=0;i<n;i++) sip[n+i]=i;
    for(long long int i=n-1;i>0;i--) si[i]=si[i<<1]+si[i<<1|1];
    for(long long int i=n-1;i>0;i--) sip[i]=min(sip[i<<1],sip[i<<1|1]);
}  
void apply(pii value,int p){
  t[p]=add(t[p],sub(mul(dp[0][si[p]],value.first),mul(dp[1][si[p]],value.second)));
  if (p < n) d[p] = combine(value,d[p]);
}
void build(int p) {
  while (p > 1) p >>= 1, t[p] = add(add(t[p<<1],t[p<<1|1]),sub(mul(dp[0][si[p]],d[p].first),mul(dp[1][si[p]],d[p].second)));
}
pii oi = {0,0};
void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i]!=oi){
      apply(d[i],i<<1);
      apply(as(d[i],(si[i]/2)),i<<1|1);
      d[i] ={0,0};
    }
  }
}
void inc(int l, int r){
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1){
        l++;
        apply({power(c2,sip[l-1]-l0+n),power(c3,sip[l-1]-l0+n)},l-1);
    }if (r&1){
        r--;
        apply({power(c2,sip[r]-l0+n),power(c3,sip[r]-l0+n)},r);
    }
  }
  build(l0);
  build(r0 - 1);
}
ll query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    ll res = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = add(res,t[l++]);
        if (r&1) res = add(t[--r],res);
    }
    return mul(res,c1);
}
void pre(){
    dp[0][0]=0;
    dp[1][0]=0;
    ll a=1,b=1;
    for(int i=1;i<300001;i++){
        a=mul(a,c2);
        b=mul(b,c3);
        dp[0][i]=add(a,dp[0][i-1]);
        dp[1][i]=add(b,dp[1][i-1]);
    }
}
void solve(){
    ll m;cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];     
    }    
    ll pref[n+1];
    pref[0]=0;
    for(int i=0;i<n;i++)
        pref[i+1]=add(pref[i],arr[i]);
    ll u,v,o;
    buil();
    for(int i=0;i<m;i++){
        cin>>o;
        if(o==1){
            cin>>u>>v;
            inc(u-1,v);
        }else{
            cin>>u>>v;
            cout<<add(sub(pref[v],pref[u-1]),query(u-1,v))<<"\n";
        }  
    }   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}