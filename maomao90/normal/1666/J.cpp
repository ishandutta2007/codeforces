/*input
4
0 566 1 0
566 0 239 30
1 239 0 1
0 30 1 0

*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
//order_of_key #of elements less than x
// find_by_order kth element
using ll=long long;
using ld=long double;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()),c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll maxn=2e5+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
int MOD=998244353;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
vector<int> vv;
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<P.f<<' '<<vv[P.s];
    return out;
}
template<typename T>
ostream& operator<<(ostream& out,vector<T> V){
    REP(i,sz(V)) out<<V[i]<<((i!=sz(V)-1)?" ":"\n");
    return out;
}
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll mult(ll a,ll b,ll mod){
    ll res=0;
    while(b){
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
ll mypow(ll a,ll b,ll mod){
    if(b<=0) return 1;
    a%=mod;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll mypow(ll a,ll b){
    a%=MOD;
    if(a==0) return 0;
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll dp[205][205];
int par[205][205];
int arr[205][205];
ll pf[205][205];
ll get(int a,int b,int c,int d){
    return pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1];
}
int ans[205];
int rec(int l,int r){
    if(l>r) return 0;
    if(l==r){
        return l;
    }
    int k=par[l][r];
    int x=rec(l,k-1),y=rec(k+1,r);
    ans[x]=ans[y]=k;
    return k;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    REP1(i,n) REP1(j,n){
        cin>>arr[i][j];
        pf[i][j]=pf[i][j-1]+pf[i-1][j]-pf[i-1][j-1]+arr[i][j];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            dp[i][j]=INF64;
            for(int k=i;k<=j;k++){
                ll cst=dp[i][k-1]+dp[k+1][j]+get(i,1,j,i-1)+get(i,j+1,j,n);
                if(dp[i][j]>cst){
                    dp[i][j]=cst;
                    par[i][j]=k;
                }
            }
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }
    }
    //cout<<dp[1][n]<<'\n';
    rec(1,n);
    REP1(i,n) cout<<ans[i]<<' ';
}