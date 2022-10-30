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

const int SIZE=300000;

int N,M,Q;

int par[SIZE],di[SIZE];
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    par[find(y)]=find(x);
}

void merge(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;

    int tmp=(di[x]+1)/2+(di[y]+1)/2+1;
    di[x]=max(tmp,max(di[x],di[y]));
    par[y]=x;
}

vint G[SIZE];
bool vis[SIZE];
pint dfs(int v,int p){
    pint res(0,v);
    vis[v]=true;
    for(auto u:G[v]){
        if(u==p)continue;
        unite(v,u);
        auto q=dfs(u,v);
        q.fi++;
        chmax(res,q);
    }
    return res;
}
void calcDi(int s){
    auto p=dfs(s,-1);
    p=dfs(p.se,-1);
    di[find(s)]=p.fi;
}

signed main(){
    scanf("%lld%lld%lld",&N,&M,&Q);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    rep(i,N)par[i]=i;
    rep(i,N)if(!vis[i])calcDi(i);

    while(Q--){
        int t;
        scanf("%lld",&t);

        if(t==2){
            int x,y;
            scanf("%lld%lld",&x,&y);
            x--;y--;
            merge(x,y);
        }
        else{
            int x;
            scanf("%lld",&x);
            x--;
            printf("%lld\n",di[find(x)]);
        }
    }
    return 0;
}