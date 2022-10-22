/*input
5 10000
10000 40000 30000 30000 20000
10000
5 2 8 3 6
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll maxn=1e5+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
ll mult(ll a,ll b){
    return (a*b)%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}
#define int ll
int arr[maxn];
int32_t main(){
    int n,k;
    cin>>n>>k;
    REP(i,n) cin>>arr[i];
    multiset<int> s;
    int add;
    cin>>add;
    ll ans=0;
    REP(i,n){
        int x;
        cin>>x;
        s.insert(x);
        if(k<arr[i]){
            int need=(arr[i]-k+add-1)/add;
            vector<int> v;
            for(auto z:s){
                need--;
                ans+=z;
                k+=add;
                v.pb(z);
                if(need==0) break;
            }
            if(need>0){
                cout<<-1;
                return 0;
            }
            for(auto z:v) s.erase(z);
        }
    }
    cout<<ans;
}