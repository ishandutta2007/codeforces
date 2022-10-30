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

int N,M;
int A[111111];
vint G[333333];

vint r[111111];

bool used[333333];
int c[333333];
bool dfs(int v){
    used[v]=1;
    for(auto u:G[v]){
        if(!used[u]){
            c[u]=c[v]^1;
            if(dfs(u)==0)return false;
        }
        else if(c[u]==c[v])return false;
    }
    return true;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&A[i]);

    rep(i,M){
        int x;scanf("%lld",&x);
        while(x--){
            int a;scanf("%lld",&a);
            a--;
            r[a].pb(i+N);
        }
    }

    rep(i,N){
        if(A[i]){
            G[i].pb(r[i][0]);
            G[r[i][0]].pb(i);
            G[i].pb(r[i][1]);
            G[r[i][1]].pb(i);
        }
        else{
            G[r[i][0]].pb(r[i][1]);
            G[r[i][1]].pb(r[i][0]);
        }
    }

    rep(i,N+M){
        if(used[i])continue;
        if(!dfs(i)){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}