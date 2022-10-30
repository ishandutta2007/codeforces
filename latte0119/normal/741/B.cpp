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

int N,M,W;
int w[1111],b[1111];

struct UF{
    vector<int>par,sz;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

vector<int>vs[1111];
int allW[1111],allB[1111];

int dp[1111],dp2[1111];

signed main(){
    scanf("%lld%lld%lld",&N,&M,&W);
    rep(i,N)scanf("%lld",&w[i]);
    rep(i,N)scanf("%lld",&b[i]);
    UF uf;uf.init(N);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        uf.unite(a,b);
    }
    rep(i,N){
        int p=uf.find(i);
        allW[p]+=w[i];
        allB[p]+=b[i];
        vs[p].pb(i);
    }

    rep(i,N){
        for(int j=0;j<=W;j++){
            dp2[j]=dp[j];
        }
        for(int j=0;j<=W;j++){
            if(j+allW[i]<=W)chmax(dp2[j+allW[i]],dp[j]+allB[i]);
        }

        for(auto u:vs[i]){
            for(int j=0;j<=W;j++){
                if(j+w[u]<=W)chmax(dp2[j+w[u]],dp[j]+b[u]);
            }
        }
        for(int j=0;j<=W;j++)dp[j]=dp2[j];
    }
    cout<<dp[W]<<endl;
    return 0;
}