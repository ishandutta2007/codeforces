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

int N,M;
int D[333333];
bool vis[333333];
int pre[333333];
vint G[333333];
int w[333333];

map<pint,int>id;

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&D[i]);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
        id[{a,b}]=id[{b,a}]=i;
    }
    int x=-1,y=-1;
    int cnt=0;
    rep(i,N){
        if(D[i]==-1)x=i;
        if(D[i]==1)y=i,cnt++;
    }

    if(x==-1&&cnt%2){
        cout<<-1<<endl;
        return 0;
    }

    if(x==-1)x=y;
    if(x==-1){
        cout<<0<<endl;
        return 0;
    }

    vint vs={x};
    vis[x]=true;
    rep(i,N){
        int v=vs[i];
        for(auto u:G[v]){
            if(vis[u])continue;
            vis[u]=true;
            pre[u]=v;
            vs.pb(u);
        }
    }

    vint ans;
    for(int i=N-1;i>0;i--){
        int v=vs[i];
        if(D[v]==1)w[v]++;
        if(w[v]&1){
            ans.pb(id[{pre[v],v}]);
        }
        w[pre[v]]+=w[v];
    }

    sort(all(ans));
    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld\n",ans[i]+1);
    return 0;
}