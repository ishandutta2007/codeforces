#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

int N,M;
vpint G[111111];

int acc[111111];
bool vis[111111];
vint lis;
void dfs(int v,int x){
    acc[v]=x;
    vis[v]=true;
    for(auto &e:G[v]){
        if(vis[e.fi])lis.pb(acc[v]^acc[e.fi]^e.se);
       else dfs(e.fi,x^e.se);
    }
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        a--;b--;
        G[a].eb(b,c);
        G[b].eb(a,c);
    }

    dfs(0,0);
    vector<int>bs;
    for(auto x:lis){
        for(auto b:bs)if((x^b)<x)x^=b;
        if(x!=0)bs.pb(x);
    }

    sort(all(bs));
    reverse(all(bs));

    int ans=acc[N-1];
    for(auto b:bs)if((ans^b)<ans)ans^=b;
    cout<<ans<<endl;
    return 0;
}