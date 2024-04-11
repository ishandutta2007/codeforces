#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N,M;
vint G[100000];

int dist[100000];
void dfs(int v,int p,int d){
    dist[v]=d;
    for(auto u:G[v]){
        if(u!=p)dfs(u,v,d+1);
    }
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    dfs(0,-1,0);
    int ma=0;
    rep(i,N)if(dist[ma]<dist[i])ma=i;
    dfs(ma,-1,0);
    cout<<*max_element(dist,dist+N)<<endl;
    return 0;
}