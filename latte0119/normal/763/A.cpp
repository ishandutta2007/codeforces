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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
vint G[111111];

int C[111111];

int latte[111111];

void dfs(int v,int p){
    latte[v]=C[v];
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v);
        if(latte[u]!=latte[v])latte[v]=-1;
    }
}

int solve(int v,int p,int c){
    vint lis;
    for(auto u:G[v]){
        if(u==p)continue;
        if(latte[u]==-1)lis.pb(u);
    }

    if(lis.size()==0)return v;
    if(lis.size()>1)return -1;
    int to=lis[0];
    if(c==-1)c=C[v];
    if(c!=C[v])return -1;
    for(auto u:G[v]){
        if(u==p||u==to)continue;
        if(latte[u]!=c)return -1;
    }
    return solve(to,v,c);
}

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    rep(i,N)scanf("%lld",&C[i]);
    dfs(0,-1);

    int tmp=solve(0,-1,-1);
    if(tmp==-1)puts("NO");
    else{
        puts("YES");
        printf("%lld\n",tmp+1);
    }


    return 0;
}