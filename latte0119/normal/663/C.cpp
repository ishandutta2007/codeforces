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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}


struct UF{
    int N;
    vint par,sz;
    void init(int n){
        N=n*2;
        par.resize(N);
        sz.resize(N);
        rep(i,N){
            par[i]=i;
            sz[i]=i<n;
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
    int getsz(int x){
        return sz[find(x)];
    }
};

const int SIZE=100000;
int N,M;
int A[SIZE],B[SIZE],C[SIZE];


vint  calc(){
    vint ret;
    UF uf;uf.init(N);
    rep(i,M){
        if(C[i]){
            uf.unite(A[i],B[i]);
            uf.unite(A[i]+N,B[i]+N);
        }
        else{
            uf.unite(A[i],B[i]+N);
            uf.unite(A[i]+N,B[i]);
        }
    }
    set<int>ok,ng;
    rep(i,N){
        if(uf.same(i,i+N))return vint(N+1,0);
        if(ok.find(uf.find(i))==ok.end()&&ng.find(uf.find(i))==ng.end()){
            int x=uf.find(i);
            int y=uf.find(i+N);
            if(uf.getsz(x)>uf.getsz(y))swap(x,y);
            ok.insert(x);
            ng.insert(y);
        }

        if(ok.find(uf.find(i))!=ok.end())ret.pb(i);
    }
    return ret;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        char c;
        scanf("%lld %lld %c",&A[i],&B[i],&c);
        A[i]--;B[i]--;
        C[i]=c=='R';
    }

    vint ans=calc();
    rep(i,M)C[i]^=1;
    vint tmp=calc();
    if(tmp.size()<ans.size())ans=tmp;
    if(ans.size()==N+1)puts("-1");
    else{
        printf("%lld\n",(int)ans.size());
        rep(i,ans.size()){
            if(i)printf(" ");
            printf("%lld",ans[i]+1);
        }
        puts("");
    }
    return 0;
}