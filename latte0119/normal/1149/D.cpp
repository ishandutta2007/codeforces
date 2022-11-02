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

const int INF=1001001001001001001;
int N,M,A,B;
int X[222],Y[222],C[222];

vpint G[77];

int id[77];


int dist[1<<17][70];

inline int nb(int b,int k){
    if(k==-1)return b;
    return b|(1<<k);
}

using tap=tuple<int,int,int>;
signed main(){
    scanf("%lld%lld%lld%lld",&N,&M,&A,&B);
    UnionFindTree uf(N);

    rep(i,M){
        scanf("%lld%lld%lld",&X[i],&Y[i],&C[i]);
        X[i]--;Y[i]--;
        if(C[i]==A){
            uf.unite(X[i],Y[i]);
        }
    }

    rep(i,M){
        if(C[i]==B&&uf.areSame(X[i],Y[i]))continue;
        G[X[i]].eb(Y[i],C[i]);
        G[Y[i]].eb(X[i],C[i]);
    }

    vint rs;
    rep(i,N){
        if(uf.find(i)!=i)continue;
        if(uf.size(i)<4)continue;
        rs.pb(i);
    }

    rep(i,N){
        int k=find(all(rs),uf.find(i))-rs.begin();
        if(k==rs.size())id[i]=-1;
        else id[i]=k;
    }

    fill_n(*dist,(1<<17)*70,INF);
    dist[nb(0,id[0])][0]=0;
    priority_queue<tap,vector<tap>,greater<tap>>que;
    que.emplace(0,nb(0,id[0]),0);
    while(que.size()){
        int d,b,v;
        tie(d,b,v)=que.top();
        que.pop();

        if(dist[b][v]<d)continue;
        for(auto &e:G[v]){
            int u,c;
            tie(u,c)=e;
            if(uf.areSame(u,v)){
                if(dist[b][u]>d+c){
                    dist[b][u]=d+c;
                    que.emplace(dist[b][u],b,u);
                }
                continue;
            }
            if(id[u]!=-1&&(b>>id[u]&1))continue;
            int bb=nb(b,id[u]);
            if(dist[bb][u]<=d+c)continue;
            dist[bb][u]=d+c;
            que.emplace(dist[bb][u],bb,u);
        }
    }

    vint ans(N,INF);
    rep(i,1<<17)rep(j,N)chmin(ans[j],dist[i][j]);    
    rep(i,N){
        if(i)printf(" ");
        printf("%lld",ans[i]);
    }
    puts("");
    return 0;
}