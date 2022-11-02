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

int N;
int A[222222];
vint G[222222];

int S[222222];
int M[222222];
void calc(int v,int p){
    S[v]=A[v];
    M[v]=LLONG_MIN;
    for(auto u:G[v]){
        if(u==p)continue;
        calc(u,v);
        S[v]+=S[u];
        chmax(M[v],M[u]);
    }
    chmax(M[v],S[v]);
}

int ans;
void solve(int v,int p,int t){
    if(t!=LLONG_MIN){
        chmax(ans,S[v]+t);
    }
    vint lis={LLONG_MIN};
    for(auto u:G[v]){
        if(u==p)continue;
        lis.pb(M[u]);
    }
    rep(i,lis.size()-1)chmax(lis[i+1],lis[i]);
    int r=LLONG_MIN;
    for(int i=(int)G[v].size()-1;i>=0;i--){
        int u=G[v][i];
        if(u==p)continue;
        lis.pop_back();
        solve(u,v,max(t,max(lis.back(),r)));
        chmax(r,M[u]);
    }
}
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    calc(0,-1);
    ans=LLONG_MIN;
    solve(0,-1,LLONG_MIN);
    if(ans==LLONG_MIN)cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}