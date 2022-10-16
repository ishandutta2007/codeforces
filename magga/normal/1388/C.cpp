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
vector<int>arr[100001];
ll n,u,v,w,m;
ll val[100001];
ll target[100001];
ll subset[100001];
pii ppl[100001];
bool ans = 1;
void dfs(int i,int from){
    subset[i] = val[i];
    for(auto to:arr[i]){
        if(to!=from){
            dfs(to,i);
            subset[i]+=subset[to];
        }
    }
}
void dfs2(int i,int from){
    ll hoo = 0;
    ll boo = 0;
    for(auto to:arr[i]){
        if(to!=from){
            dfs2(to,i);
            hoo += ppl[to].F;
            boo += ppl[to].S;
        }
    }
    hoo -= max(0ll,val[i]-ppl[i].S);
    if( hoo>ppl[i].F){
        ans = 0;
    }
}
void pre(){}
void solve(){
    ans = 1;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        arr[i].clear();
    }
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=n;i++) cin>>target[i];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    dfs(1,0);
    for(int i = 1;i<=n;i++){
        ppl[i].F = (target[i] + subset[i])/2;
        ppl[i].S = (subset[i] - target[i])/2;
        if( (target[i] + subset[i])%2!=0 || subset[i]<target[i] ){
            cout<<"NO"<<"\n";
            return;
        }
    }
    dfs2(1,0);
    if(ans){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
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