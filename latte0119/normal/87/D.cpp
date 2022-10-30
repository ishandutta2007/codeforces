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

struct UF{
    int N;
    vint par,sz;
    void init(int n){
        N=n;
        par.resize(N);
        sz.resize(N);
        rep(i,N){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        while(par[x]!=x)x=par[x];
        return x;
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
};

int N;
int A[100000],B[100000],C[100000];
int val[100000];

vint G[100000];
bool used[100000];
int sz[100000],root[100000];

void dfs(int v,int r){
    used[v]=true;
    root[v]=r;

    for(auto u:G[v]){
        if(used[u])continue;
        dfs(u,r);
        sz[v]+=sz[u];
    }
}

signed main(){
    cin>>N;
    map<int,vint>lis;
    rep(i,N-1){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--;B[i]--;
        lis[C[i]].pb(i);
    }

    UF uf;
    uf.init(N);
    each(it,lis){
        vint &v=it->se;
        vint vec;
        rep(i,v.size()){
            int a=uf.find(A[v[i]]);
            int b=uf.find(B[v[i]]);
            G[a].pb(b);
            G[b].pb(a);
            vec.pb(a);vec.pb(b);
        }
        rep(i,vec.size()){
            sz[vec[i]]=uf.sz[vec[i]];
        }
        rep(i,vec.size()){
            if(used[vec[i]])continue;
            dfs(vec[i],vec[i]);
        }

        rep(i,v.size()){
            int a=uf.find(A[v[i]]);
            int b=uf.find(B[v[i]]);
            if(sz[a]>sz[b])swap(a,b);
            int s=sz[root[a]];
            val[v[i]]=sz[a]*(s-sz[a])*2;
        }

        rep(i,v.size()){
            uf.unite(A[v[i]],B[v[i]]);
        }
        rep(i,vec.size()){
            used[vec[i]]=false;
            G[vec[i]].clear();
        }
    }

    int ma=*max_element(val,val+N-1);
    int cnt=count(val,val+N-1,ma);
    printf("%lld %lld\n",ma,cnt);
    rep(i,N-1){
        if(val[i]==ma)printf("%lld ",i+1);
    }
    return 0;
}