#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;
 
// #define int ll
 
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
// const ll m2 = 1e14 - 27;
 
 
void GG(){cout<<"No\n"; exit(0);}
 
ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}
 
ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}
 
const int maxn = 3000+5;
 
ll dp[maxn][maxn];
 
unordered_map <ull, ll> seen;
// unordered_map<ull, ll> val;
ll B = 59;
bool ok[100];
 
ull hval[maxn];
bool can[maxn];
int a[maxn];
 
main(){
    seen.max_load_factor(0.7);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m; cin>>m;
    // vector<ull> hval(m+1);
    ok[5]=1; ok[3]=1; ok[14]=1; ok[15]=1;
    ll re = 0;
    REP(i,m) dp[i][0]=1;
    REP(i,m) cin>>a[i];
    REP(i,m){
        if (i-3>=0){
            ll HV = 0;
            FOR(k,i-3,i+1){
                HV *=2; HV += a[k];
            }
            if (!ok[HV]) can[i]=1;
        }
    }
    REP(i,m){
        // cin>>a[i];
        REP(j,i+1){
            hval[j] = hval[j]*B + a[i] + 1; 
            //dp[j][i-j]
            if (seen.count(hval[j])){
                // cout<<j<<" to "<<i<<" repeated\n";
                dp[j][i-j+1] = seen[hval[j]]; 
                // re += dp[j][i-j+1];
                continue;
            }
            REP(k,3){
                if (i-j-k>=0){
                    dp[j][i-j+1] += dp[j][i-j-k];
                }else break;
            }
            if (i-3-j >=0){
                if (can[i]) {
                    dp[j][i-j+1] += dp[j][i-j-2-1]; 
                }
            }
            dp[j][i-j+1] %= mod;
            
            re += dp[j][i-j+1];
            seen[hval[j]] = dp[j][i-j+1];
            if (re >= mod) re-= mod;
        }
        cout<<re<<'\n';
    }
    
 
    
}