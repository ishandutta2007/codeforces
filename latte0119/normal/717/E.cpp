#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
vint G[200000];
int C[200000];

int sz[200000];

void hoge(int v,int p){
    sz[v]=C[v]==-1;
    for(auto u:G[v]){
        if(u==p)continue;
        hoge(u,v);
        sz[v]+=sz[u];
    }
}

vint vec;
void dfs(int v,int p){
    vec.pb(v);
    for(auto u:G[v]){
        if(u==p)continue;
        if(sz[u]==0)continue;
        C[u]=-C[u];
        dfs(u,v);
        vec.pb(v);
        C[v]=-C[v];
        if(C[u]==-1){
            vec.pb(u);
            vec.pb(v);
            C[v]=-C[v];
        }
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&C[i]);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    hoge(0,-1);
    dfs(0,-1);

    if(C[0]==-1){
        vec.pb(G[0][0]);
        vec.pb(0);
        vec.pb(G[0][0]);
    }
    rep(i,vec.size())printf("%lld ",vec[i]+1);
    return 0;
}