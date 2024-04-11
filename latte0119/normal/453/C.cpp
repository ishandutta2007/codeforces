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
vint G[111111];
int X[111111];

vint ans;
bool vis[111111];

int cnt[111111],par[111111];

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    par[find(y)]=find(x);
}

void dfs(int v,int p){
    X[v]^=1;
    vis[v]=true;
    ans.pb(v);
    for(auto u:G[v]){
        if(vis[u])continue;
        dfs(u,v);
        X[v]^=1;
        ans.pb(v);
    }

    if(X[v]==0)return;
    if(p!=-1){
        ans.pb(p);
        ans.pb(v);
        X[p]^=1;
    }
    else{
        ans.pb(G[v][0]);
        ans.pb(v);
        ans.pb(G[v][0]);
    }
}

signed main(){
    scanf("%lld%lld",&N,&M);

    rep(i,N)par[i]=i;


    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
        unite(a,b);
    }
    rep(i,N)scanf("%lld",&X[i]);
    rep(i,N)cnt[find(i)]+=X[i];

    vint lis;
    rep(i,N)if(find(i)==i&&cnt[i])lis.pb(i);

    if(lis.size()>1){
        cout<<-1<<endl;
        return 0;
    }
    if(lis.size()==0){
        cout<<0<<endl;
        return 0;
    }

    dfs(lis[0],-1);

    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld ",ans[i]+1);
    puts("");
    
    return 0;
}