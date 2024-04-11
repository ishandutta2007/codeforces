/*input
5 6
1 2 3
2 3 4
3 4 5
4 5 6
1 5 1
2 4 2

*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const ll INF=0x3f3f3f3f;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof(x))y)
#define MXTO(x,y) x=max(x,(__typeof(x))y)
ll sub(ll a,ll b){
    ll x=a-b;
    while(x<0) x+=MOD;
    while(x>MOD) x-=MOD;
    return x;
}
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
const int maxn=1e5+5;
int dist[maxn*51];
vector<pii> v[maxn*51];
int32_t main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m;
    cin>>n>>m;
    REP(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        --a;
        --b;
        v[a*51].pb({b*51+c,0});
        REP1(i,50) v[a*51+i].pb({b*51,(i+c)*(i+c)});
        swap(a,b);
        v[a*51].pb({b*51+c,0});
        REP1(i,50) v[a*51+i].pb({b*51,(i+c)*(i+c)});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    REP(i,51*n) dist[i]=INF;
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int z=pq.top().s;
        int d=pq.top().f;
        pq.pop();
        if(d!=dist[z]) continue;
        for(auto x:v[z]){
            //cout<<x.f<<' '<<dist[x.f]<<'\n';
            if(dist[x.f]>dist[z]+x.s){
                dist[x.f]=dist[z]+x.s;
                pq.push({dist[x.f],x.f});
            }
        }
    }
    REP(i,n){
        int z=dist[i*51];
        if(z==INF) z=-1;
        cout<<z<<' ';
    }
}