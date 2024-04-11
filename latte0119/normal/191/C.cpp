#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


int N;
vint G[111111];
int ans[111111];
int dep[111111];
set<int>s[111111];

int A[111111],B[111111];
void dfs(int v,int p,int d){
    dep[v]=d;
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v,d+1);
        if(s[v].size()<s[u].size())swap(s[v],s[u]);
        for(auto &x:s[u]){
            if(s[v].find(x)!=s[v].end())s[v].erase(x);
            else s[v].insert(x);
        }
    }

    ans[v]=s[v].size();
}

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
        A[i]=a;B[i]=b;
    }


    int Q;scanf("%lld",&Q);
    rep(i,Q){
        int a,b;scanf("%lld%lld",&a,&b);
        a--;b--;
        if(a==b)continue;
        s[a].insert(i);s[b].insert(i);
    }

    dfs(0,-1,0);
    rep(i,N-1){
        if(dep[A[i]]<dep[B[i]])swap(A[i],B[i]);
        printf("%lld ",ans[A[i]]);
    }
}