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

const int mod=1000000007;
const int SIZE=100000;
int N;
vector<int>G[SIZE];
int dp0[SIZE],dp1[SIZE];
int color[SIZE];
void dfs(int v){
    if(color[v]==0){
        dp0[v]=1;dp1[v]=0;
    }
    else{
        dp0[v]=0;dp1[v]=1;
    }

    for(int u:G[v]){
        dfs(u);
        int n0=0,n1=0;
        n0=(n0+dp0[v]*dp0[u])%mod;
        n1=(n1+dp1[v]*dp0[u]+dp0[v]*dp1[u])%mod;

        n0=(n0+dp0[v]*dp1[u])%mod;
        n1=(n1+dp1[v]*dp1[u])%mod;
        dp0[v]=n0;
        dp1[v]=n1;
    }
}

signed main(){
    scanf("%lld",&N);
    for(int i=1;i<N;i++){
        int p;
        scanf("%lld",&p);
        G[p].push_back(i);
    }
    for(int i=0;i<N;i++)scanf("%lld",&color[i]);
    dfs(0);
    printf("%lld\n",dp1[0]);
    return 0;
}