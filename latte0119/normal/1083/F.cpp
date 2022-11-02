#include<bits/stdc++.h>
using namespace std;

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

int N,K,Q;
int pos[222222],val[222222];
int H[222222];


const int INF=1001001001;
const int B=300;
const int L=1<<14;
struct Sol{
    int cost;
    vint v;
    vector<array<int,L>>cnt;
    int n;
    void init(const vint &v_){
        v=v_;
        n=v.size()/B;
        cnt.assign(n,array<int,L>());
        for(int i=0;i<v.size();i++){
            if(i%B)v[i]^=v[i-1];
            if(i<n*B)cnt[i/B][v[i]]++;
        }
        cost=calcCost();
    }

    int calcCost(){
        int acc=0;
        int ret=v.size();
        for(int i=0;i<n;i++){
            ret-=cnt[i][acc];
            acc^=v[(i+1)*B-1];
        }
        for(int i=n*B;i<v.size();i++)if(v[i]==acc)ret--;

        if(v.size()==n*B){
            if(acc)return INF;
        }
        else{
            if(acc^v.back())return INF;
        }
        return ret;
    }

    inline int getCost(){
        return cost;
    }

    void update(int k,int x){
        if(k>=n*B){
            for(int i=k;i<v.size();i++)v[i]^=x;
        }
        else{
            const int m=k/B;
            const int r=(m+1)*B;
            for(int i=k;i<r;i++){
                cnt[m][v[i]]--;
                v[i]^=x;
                cnt[m][v[i]]++;
            }
        }
        cost=calcCost();
    }
};

void solve(){
    vint D(N+1);
    D[0]=H[0];
    rep(i,N-1){
        D[i+1]=H[i]^H[i+1];
    }
    D[N]=H[N-1];

    vector<Sol>sols(K);
    rep(i,K){
        vint v;
        for(int j=i;j<=N;j+=K)v.pb(D[j]);
        sols[i].init(v);
    }

    long long cost=0;
    rep(i,K)cost+=sols[i].getCost();

    if(cost<=N)printf("%lld\n",cost);
    else puts("-1");

    rep(i,Q){
        for(int p=pos[i];p<=pos[i]+1;p++){
            cost-=sols[p%K].getCost();
            sols[p%K].update(p/K,val[i]);
            cost+=sols[p%K].getCost();
        }
        if(cost<=N)printf("%lld\n",cost);
        else puts("-1");
    }
}

signed main(){
    scanf("%d%d%d",&N,&K,&Q);
    vint A(N),B(N);
    rep(i,N)scanf("%d",&A[i]);
    rep(i,N)scanf("%d",&B[i]);
    rep(i,N)H[i]=A[i]^B[i];

    rep(i,Q){
        char c;
        int p,v;
        scanf(" %c%d%d",&c,&p,&v);
        p--;
        pos[i]=p;
        if(c=='a'){
            val[i]=v^A[p];
            A[p]=v;
        }
        else{
            val[i]=v^B[p];
            B[p]=v;
        }
    }

    solve();
    return 0;
}