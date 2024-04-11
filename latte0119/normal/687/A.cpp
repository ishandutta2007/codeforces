#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
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

int color[100000];
bool dfs(int v,int c){
    if(color[v]!=-1){
        if(color[v]!=c)return false;
        return true;
    }
    color[v]=c;
    for(auto u:G[v]){
        if(!dfs(u,1-c))return false;
    }
    return true;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    memset(color,-1,sizeof(color));
    bool ok=true;
    for(int i=0;i<N;i++)if(color[i]==-1)ok&=dfs(i,1);
    if(!ok){
        puts("-1");
    }
    else{
        vint A,B;
        rep(i,N){
            if(color[i]==1)A.pb(i);
            else B.pb(i);
        }
        printf("%lld\n",(int)A.size());
        rep(i,A.size())printf("%lld ",A[i]+1);
        puts("");
        printf("%lld\n",(int)B.size());
        rep(i,B.size())printf("%lld ",B[i]+1);
        puts("");


    }
    return 0;
}