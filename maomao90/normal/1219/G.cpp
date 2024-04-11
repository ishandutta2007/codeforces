/*input
10 1
1 2 3 4 5 6 7 8 9 10

*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll=long long;
using ld=long double;
using pii=pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()),c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll maxn=1e5+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)

vector<vector<int>> arr;
ll r[maxn],c[maxn];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m;
    cin>>n>>m;

    if(n>=m){
        arr.resize(m);
        REP(i,m) arr[i].resize(n);
        REP(i,n){
            REP(j,m) cin>>arr[j][i];
        }
        swap(n,m);
    }
    else{
        arr.resize(n);
        REP(i,n){
            arr[i].resize(m);
            REP(j,m) cin>>arr[i][j];
        }
    }
    REP(i,n) REP(j,m) r[i]+=arr[i][j];
    REP(i,m) REP(j,n) c[i]+=arr[j][i];
    vector<ll> rr,cc;
    REP(i,n) rr.pb(r[i]);
    REP(i,m) cc.pb(c[i]);
    sort(ALL(rr)),reverse(ALL(rr));
    sort(ALL(cc)),reverse(ALL(cc));
    ll ans=0;
    ll sum=0;
    REP(j,min(4,sz(rr))) sum+=rr[j];
    MXTO(ans,sum);
    sum=0;
    REP(j,min(4,sz(cc))) sum+=cc[j];
    MXTO(ans,sum);
    REP(i,n){
        vector<ll> v;
        REP(j,m){
            v.pb(c[j]-arr[i][j]);
        }
        sort(ALL(v));
        reverse(ALL(v));
        sum=0;
        REP(j,min(3,sz(v))) sum+=v[j];
        MXTO(ans,sum+r[i]);
    }
    REP(i,m){
        vector<ll> v;
        REP(j,n){
            v.pb(r[j]-arr[j][i]);
        }
        sort(ALL(v));
        reverse(ALL(v));
        sum=0;
        REP(j,min(3,sz(v))) sum+=v[j];
        MXTO(ans,sum+c[i]);
    }
    REP(i,n){
        REP(j,i){
            ll mx=0,mx2=0;
            REP(k,m){
                ll cur=c[k]-arr[i][k]-arr[j][k];
                if(cur>=mx){
                    mx2=mx;
                    mx=cur;
                }
                else if(cur>mx2){
                    mx2=cur;
                }
            }
            MXTO(ans,mx+mx2+r[i]+r[j]);
        }
    }
    cout<<ans;
}