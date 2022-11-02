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

using bs=bitset<2000>;

int N;
bs G[2222];


bool check(){
    bs vis;
    rep(i,N)vis[i]=1;
    vis[0]=0;
    queue<int>que;
    que.push(0);

    bs tmp;
    while(que.size()){
        int v=que.front();
        que.pop();
        tmp=G[v]&vis;
        for(int i=tmp._Find_first();i<N;i=tmp._Find_next(i)){
            que.push(i);
            vis[i]=0;
        }
    }

    if(vis.count())return false;
    vis[0]=1;
    que.push(0);
    while(que.size()){
        int v=que.front();
        que.pop();
        tmp=(G[v]|vis).flip();
        for(int i=tmp._Find_first();i<N;i=tmp._Find_next(i)){
            que.push(i);
            vis[i]=1;
        }
    }
    if(vis.count()!=N)return false;
    return true;
}

char buf[2222];
signed main(){
    scanf("%lld",&N);    
    rep(i,N){
        scanf("%s",buf);
        rep(j,N)G[i][j]=buf[j]=='1';
    }

    if(check()){
        cout<<0<<" "<<1<<endl;
        return 0;
    }

    if(N<=6){
        const int INF=1001001001;
        int dist[6][6];
        fill_n(*dist,36,INF);
        rep(i,N)dist[i][i]=0;
        rep(i,N)rep(j,N)if(G[i][j])dist[i][j]=1;
        rep(k,N)rep(i,N)rep(j,N)chmin(dist[i][j],dist[i][k]+dist[k][j]);
        UnionFindTree uf(N);
        rep(i,N)rep(j,N)if(dist[i][j]!=INF&&dist[j][i]!=INF)uf.unite(i,j);
        int mi=INF,ma=0,cnt=0;
        rep(i,N){
            if(uf.find(i)!=i)continue;
            cnt++;
            chmax(ma,uf.size(i));
            chmin(mi,uf.size(i));
        }
        if(cnt==2&&ma==3){
            if(mi==1)cout<<-1<<endl;
            else cout<<2<<" "<<18<<endl;
            return 0;
        }
    }


    int cnt=0;
    rep(i,N){
        rep(j,N){
            if(i==j)continue;
            int tmp=G[i][j];
            G[i][j]=G[j][i];
            G[j][i]=tmp;
        }
        if(check())cnt++;
        rep(j,N){
            if(i==j)continue;
            int tmp=G[i][j];
            G[i][j]=G[j][i];
            G[j][i]=tmp;
        }
    }

    cout<<1<<" "<<cnt<<endl;
    return 0;
}