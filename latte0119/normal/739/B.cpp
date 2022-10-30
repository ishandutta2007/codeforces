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
int ans[222222];

vpint G[222222];
multiset<int>st[222222];
int add[222222];



void dfs(int v){
    st[v].insert(A[v]);
    add[v]=0;

    rep(i,G[v].size()){
        int u,c;
        tie(u,c)=G[v][i];
        dfs(u);
        add[u]+=c;
        while(st[u].size()&&*st[u].begin()<add[u])st[u].erase(st[u].begin());
        if(st[v].size()<st[u].size()){
            swap(st[v],st[u]);
            swap(add[v],add[u]);
        }
        each(it,st[u]){
            int d=*it;
            st[v].insert(d-add[u]+add[v]);
        }
    }
    ans[v]=st[v].size();
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    for(int i=1;i<N;i++){
        int p,c;
        scanf("%lld%lld",&p,&c);
        p--;
        G[p].pb({i,c});
    }

    dfs(0);
    rep(i,N)printf("%lld ",ans[i]-1);
    puts("");
    return 0;
}