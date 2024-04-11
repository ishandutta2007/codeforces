#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

vector<int>sum[222222],cnt[222222];
int N,K;
vint G[222222];

int ans;
void dfs(int v,int p){
    sum[v].resize(K);cnt[v].resize(K);
    cnt[v][0]=1;

    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v);
        rep(i,K){
            cnt[v][(i+1)%K]+=cnt[u][i];
            sum[v][(i+1)%K]+=sum[u][i]+cnt[u][i];
        }
    }
}

void dfs2(int v,int p,vint s,vint c){
    rep(i,K)ans+=(s[i]+(K-i)%K*c[i])/K;

    for(auto u:G[v]){
        if(u==p)continue;
        vint ss=s;
        vint cc=c;
        vint sss=sum[u];
        vint ccc=cnt[u];
        rep(i,K){
            cc[(i+1)%K]-=cnt[u][i];
            ss[(i+1)%K]-=cnt[u][i]+sum[u][i];
        }

        rep(i,K){
            ccc[(i+1)%K]+=cc[i];
            sss[(i+1)%K]+=ss[i]+cc[i];
        }
        dfs2(u,v,sss,ccc);
    }
}

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    dfs(0,-1);

    vector<int>s=sum[0];
    vector<int>c=cnt[0];
    dfs2(0,-1,s,c);

    printf("%lld\n",ans/2);
    return 0;
}