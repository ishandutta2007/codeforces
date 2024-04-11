#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

const int SIZE=300000;
const int mod=1000000007;
struct BIT{
    int N;
    vint dat;
    void init(int n){
        N=n;
        dat.assign(N+1,0);
    }
    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret%mod;
    }
};

int N;
vint G[SIZE];

int tin[SIZE],tout[SIZE],dep[SIZE];
void dfs(int v,int p,int d,int &k){
    dep[v]=d;
    tin[v]=k++;
    rep(i,G[v].size()){
        int to=G[v][i];
        if(to==p)continue;
        dfs(to,v,d+1,k);
    }
    tout[v]=k;
}

BIT X,Y;

signed main(){
    scanf("%lld",&N);
    for(int i=1;i<N;i++){
        int p;scanf("%lld",&p);
        p--;
        G[i].pb(p);
        G[p].pb(i);
    }
    int K=0;dfs(0,-1,0,K);

    X.init(N+114);Y.init(N+114);

    int Q;scanf("%lld",&Q);
    while(Q--){
        int type;scanf("%lld",&type);
        if(type==1){
            int v,x,k;
            scanf("%lld%lld%lld",&v,&x,&k);
            v--;
            X.add(tin[v],(x+k*dep[v])%mod);
            X.add(tout[v],-((x+k*dep[v])%mod));
            Y.add(tin[v],k);
            Y.add(tout[v],-k);
        }
        else{
            int v;
            scanf("%lld",&v);
            v--;
            int hoge=X.sum(tin[v]);
            int piyo=Y.sum(tin[v])*dep[v]%mod;
            printf("%lld\n",(hoge-piyo+mod)%mod);
        }
    }
    return 0;
}
/*
3
1 1
3
1 1 2 1
2 1
2 2
*/