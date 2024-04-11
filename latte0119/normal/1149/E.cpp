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

int N,M;
vint G[222222];

int topbit(int a){
    return 63-__builtin_clzll(a);
}

signed main(){
    scanf("%lld%lld",&N,&M);
    vint A(N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);
    }

    vint ord;
    vint deg(N);
    rep(i,N)for(auto u:G[i])deg[u]++;
    rep(i,N)if(deg[i]==0)ord.pb(i);
    rep(i,N){
        int v=ord[i];
        for(auto u:G[v]){
            if(--deg[u]==0)ord.pb(u);
        }
    }
    reverse(all(ord));

    vint q(N);
    for(auto v:ord){
        set<int>s;
        for(auto u:G[v])s.insert(q[u]);
        q[v]=0;
        while(s.find(q[v])!=s.end())q[v]++;
    }

    vint x(N);
    rep(i,N)x[q[i]]^=A[i];
    
    int w=-1;
    rep(i,N)if(x[i])w=i;
    if(w==-1){
        puts("LOSE");
        return 0;
    }

    rep(i,N){
        if(q[i]!=w)continue;
        if(!(A[i]>>topbit(x[w])&1))continue;
        A[i]^=x[w];
        for(auto u:G[i]){
            A[u]^=x[q[u]];
            x[q[u]]=0;
        }
        break;
    }

    puts("WIN");
    rep(i,N){
        if(i)printf(" ");
        printf("%lld",A[i]);
    }
    puts("");
    return 0;
}