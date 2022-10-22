/*input
9
9 10 9 18 9 9 9 28 9
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
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()),c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET(v,x) lower_bound(ALL(v),x)-v.begin()
const ll maxn=5e5+5;
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
#define int ll
int arr[maxn];
int pf[maxn];
int gt(int x){
    if(x<0) return 0;
    if(x>=maxn) return pf[maxn-1];
    return pf[x];
}
int32_t main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    int mx=0,sum=0;
    REP(i,n) cin>>arr[i],MXTO(mx,arr[i]),sum+=arr[i],pf[arr[i]]++;
    sort(arr,arr+n);
    REP1(i,maxn-1) pf[i]+=pf[i-1];
    int ans=0;
    int pv=INF;
    for(int y=2;y<=mx;y++){
        int l=0,r=sum/y;
        int cnt=0;
        for(int i=0;i<maxn;i+=y) cnt+=(gt(i+y-1)-gt(i-1))*(i/y);
        while(l<r){
            int mid=(l+r+1)/2;
            int tot=n-(lower_bound(arr,arr+n,mid)-arr),t2=n-(lower_bound(arr,arr+n,2*mid)-arr);
            int asd=0,a2=0;
            for(int i=(mid)/y*y;i<maxn;i+=y){
                asd+=(gt(i+y-1)-gt(i+(mid%y)-1));
            }
            for(int i=(2*mid)/y*y;i<maxn;i+=y){
                a2+=(gt(i+y-1)-gt(i+((2*mid)%y)-1));
            }
            MNTO(asd,2),MNTO(a2,1);
            if(tot<2 and t2<1){
                r=mid-1;
                continue;
            }
            //cout<<mid<<' '<<asd<<' '<<a2<<'\n';
            if(cnt-min(asd*(mid/y)+(2-asd)*((mid+y-1)/y),a2*(2*mid/y)+(1-a2)*((2*mid+y-1)/y))>=mid) l=mid;
            else r=mid-1; 
        }
        if(l<=1) break;
        //cout<<l<<' ';
        assert(pv>=l);
        pv=l;
        MXTO(ans,l*y);
    }   
    cout<<ans;
}