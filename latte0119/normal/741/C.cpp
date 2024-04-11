#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

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

int N;
int A[111111],B[111111];
signed main(){
    scanf("%lld",&N);
    UnionFindTree uf(4*N);
    for(int i=0;i<2*N;i+=2){
        int j=i+1;
        uf.unite(i*2,j*2+1);
        uf.unite(i*2+1,j*2);
    }

    rep(i,N){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        uf.unite(a*2,b*2+1);
        uf.unite(a*2+1,b*2);
        tie(A[i],B[i])=pint(a,b);
    }

    set<int>rs;

    vint ans(2*N);
    rep(i,2*N){
        int k=-1;
        rep(j,2)if(rs.find(uf.find(i*2+j))!=rs.end())k=j;
        if(k==-1){
            k=0;
            rs.insert(uf.find(i*2));
        }
        ans[i]=k;
    }


    rep(i,N){
        printf("%lld %lld\n",ans[A[i]]+1,ans[B[i]]+1);
    }
    return 0;
}