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

int N,M;
int in[111111],out[111111];
vpint es;
vpint G[111111];
bool vis[111111];
void dfs(int v,int pre){
    vis[v]=true;
    for(auto &e:G[v]){
        if(vis[e.fi])continue;
        dfs(e.fi,e.se);
    }
    if(in[v]%2==0)return;
    in[es[pre].fi]--;out[es[pre].se]--;
    in[es[pre].se]++;out[es[pre].fi]++;
    swap(es[pre].fi,es[pre].se);
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        es.pb({a,b});
        out[a]++;in[b]++;
    }
    vint latte;
    rep(i,N)if((in[i]+out[i])%2)latte.pb(i);

    for(int i=0;i<latte.size();i+=2){
        es.pb({latte[i],latte[i+1]});
        out[latte[i]]++;in[latte[i+1]]++;
    }

    rep(i,es.size()){
        G[es[i].fi].pb({es[i].se,i});
        G[es[i].se].pb({es[i].fi,i});
    }
    if(es.size()%2==1){
        es.pb({0,0});in[0]++;out[0]++;
    }
    dfs(0,-1);

    printf("%lld\n",(int)es.size());
    rep(i,es.size())printf("%lld %lld\n",es[i].fi+1,es[i].se+1);
    return 0;
}