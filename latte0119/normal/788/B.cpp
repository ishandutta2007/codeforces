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

const int SIZE=1000000;

int N,M;
int A[SIZE],B[SIZE];

int cnt[SIZE];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M)scanf("%lld%lld",&A[i],&B[i]);

    vint vs;
    rep(i,M){
        vs.pb(A[i]);vs.pb(B[i]);
    }
    sort(all(vs));vs.erase(unique(all(vs)),vs.end());
    rep(i,M){
        A[i]=lower_bound(all(vs),A[i])-vs.begin();
        B[i]=lower_bound(all(vs),B[i])-vs.begin();
    }
    N=vs.size();

    UnionFindTree uf(N);
    rep(i,M)uf.unite(A[i],B[i]);

    if(uf.size(0)!=N){
        puts("0");
        return 0;
    }

    int luz=0;
    rep(i,M){
        if(A[i]==B[i])luz++;
        else{
            cnt[A[i]]++;cnt[B[i]]++;
        }
    }
    int ans=0;
    ans+=luz*(M-luz);
    ans+=luz*(luz-1)/2;
    for(int i=0;i<N;i++)ans+=cnt[i]*(cnt[i]-1)/2;

    cout<<ans<<endl;
    return 0;
}