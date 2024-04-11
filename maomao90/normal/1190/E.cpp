/*input
3 1
2 0
0 2
-1 0
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//order_of_key #of elements less than x
// find_by_order kth element
using ll=long long;
using ld=long double;
using pii=pair<ll,ll>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()),c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET(v,x) lower_bound(ALL(v),x)-v.begin()
const ll maxn=2e5+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1.0l);
const ld eps=1e-6;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<P.f<<' '<<P.s;
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
pii arr[maxn];
int par[maxn][20];
int n,m;
#define pdd pair<ld,ld> 
bool cmp(pdd a,pdd b){
    return a.s<b.s;
}
bool wk(ld mid){
    vector<pdd> v;
    REP(i,n){
        ld len=sqrtl(arr[i].f*arr[i].f+arr[i].s*arr[i].s);
        if(len<mid){
            return false;
        }
        ld a=atan2(arr[i].s,arr[i].f);
        ld x=a-acos(mid/len),y=a+acos(mid/len);
        while(y<0) x+=2*PI,y+=2*PI;
        while(y>=2*PI) x-=2*PI,y-=2*PI;
        v.pb({x,y}); 
        v.pb({x+2*PI,y+2*PI});
        //cout<<x<<' '<<y<<'\n';
    }
    sort(ALL(v),cmp);
    int p=0;
    REP(i,sz(v)){
        while(p<sz(v) and v[p].f<=v[i].s) ++p;
        if(p==sz(v)) par[i][0]=-1;
        else par[i][0]=p;
        //cout<<i<<' '<<par[i][0]<<'\n';
    }
    REP1(j,19){
        REP(i,sz(v)){
            if(par[i][j-1]!=-1) par[i][j]=par[par[i][j-1]][j-1];
            else par[i][j]=-1;
        }
    }
    REP(i,n){
        int z=m;
        int x=i;
        while(x!=-1 and z){
            x=par[x][__lg(lowb(z))];
            z-=lowb(z);
        }   
        if(x==-1 or x>=i+n){
            return true;
        }
    }
    return false;
}
int32_t main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    REP(i,n) cin>>arr[i].f>>arr[i].s;
    ld l=0,r=2e5;
    REP(asd,40){
        ld mid=(l+r)/2;
        if(wk(mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(20)<<l;
}