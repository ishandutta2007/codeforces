#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int INF=100000;

int H,W,Q;
int ans[1111];
int T[1111],Y[1111],X[1111];
int AA[1111][1111];
int A[1111][1111];

int dp[1111][1111];

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
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
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int calc(vint vec,int x){
    UnionFindTree uf(vec.size());

    vpint v;
    rep(i,vec.size()){
        v.pb(pint(vec[i],i));
    }
    sort(all(v));reverse(all(v));
    int ma=0;
    for(auto w:v){
        int i=w.se;

        if(i&&vec[i-1]>=vec[i])uf.unite(i-1,i);
        if(i+1!=vec.size()&&vec[i+1]>=vec[i])uf.unite(i,i+1);
        if(vec[x]>=w.fi)chmax(ma,uf.size(x)*w.fi);
    }
    return ma;
}

void solve(){
    memset(dp,0,sizeof(dp));
    rep(i,H){
        for(int j=W-1;j>=0;j--){
            if(A[i][j]==0)dp[i][j]=0;
            else dp[i][j]=dp[i][j+1]+1;
        }
    }

    rep(i,Q){
        if(T[i]==1){
            A[Y[i]][X[i]]^=1;
            for(int j=W-1;j>=0;j--){
                if(A[Y[i]][j]==0)dp[Y[i]][j]=0;
                else dp[Y[i]][j]=dp[Y[i]][j+1]+1;
            }
            continue;
        }
        vint vec;
        rep(j,H)vec.pb(dp[j][X[i]]);
        chmax(ans[i],calc(vec,Y[i]));
    }
}

signed main(){
    scanf("%lld%lld%lld",&H,&W,&Q);
    rep(i,H)rep(j,W)scanf("%lld",&AA[i][j]);
    rep(i,Q)scanf("%lld%lld%lld",&T[i],&Y[i],&X[i]),Y[i]--,X[i]--;

    rep(t,4){
        rep(i,H)rep(j,W)A[i][j]=AA[i][j];
        solve();

        rep(i,Q){
            int y,x;
            y=X[i];
            x=H-1-Y[i];
            Y[i]=y;X[i]=x;
        }
        vector<vint>AAA(W,vint(H));
        rep(i,H)rep(j,W)AAA[j][H-1-i]=AA[i][j];
        swap(H,W);
        rep(i,H)rep(j,W)AA[i][j]=AAA[i][j];
    }

    rep(i,Q)if(T[i]==2)printf("%lld\n",ans[i]);

    return 0;
}