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
vint G[222222];
void dfs(int v,int p,int d,vint &dist){
    dist[v]=d;
    for(auto u:G[v]){
        if(u!=p)dfs(u,v,d+1,dist);
    }
}
signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    vint distX(N);
    dfs(0,-1,0,distX);
    int X=max_element(all(distX))-distX.begin();
    dfs(X,-1,0,distX);
    int Y=max_element(all(distX))-distX.begin();
    vint distY(N);
    dfs(Y,-1,0,distY);

    int ans=(distX[Y]+1)*distX[Y]/2;
    rep(i,N)if(distX[i]+distY[i]!=distX[Y])ans+=max(distX[i],distY[i]);

    printf("%lld\n",ans);
    vpint ord,ord2;
    rep(i,N){
        if(distX[i]+distY[i]!=distX[Y])ord.pb({distX[i],i});
        else ord2.pb({distX[i],i});
    }
    sort(all(ord));reverse(all(ord));
    rep(i,ord.size()){
        int v=ord[i].se;
        int z;
        if(distX[v]>=distY[v])z=X;
        else z=Y;
        printf("%lld %lld %lld\n",v+1,z+1,v+1);
    }

    sort(all(ord2));
    reverse(all(ord2));
    rep(i,ord2.size()){
        int v=ord2[i].se;
        if(v==X)break;
        printf("%lld %lld %lld\n",v+1,X+1,v+1);
    }

    return 0;
}