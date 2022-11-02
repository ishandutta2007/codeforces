#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;

int N;
int A[222222];

vint G[222222];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int ans[222222];

void dfs(int v,int p,int g,vint x){
    rep(i,x.size())x[i]=gcd(x[i],A[v]);
    x.pb(g);
    sort(all(x));x.erase(unique(all(x)),x.end());
    g=gcd(g,A[v]);
    ans[v]=max(x.back(),g);
    for(auto u:G[v]){
        if(u!=p)dfs(u,v,g,x);
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    vint x;
    dfs(0,-1,0,x);
    rep(i,N){
        printf("%lld ",ans[i]);
    }
    return 0;
}