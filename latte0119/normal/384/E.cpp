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

struct BIT{
    int N;
    vint dat;
    void init(int n){
        N=n;
        dat.assign(N+1,0);
    }
    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

const int SIZE=200000;


int N,M,A[SIZE];
vint G[SIZE];

int tin[SIZE],tout[SIZE],dep[SIZE];
void dfs(int v,int p,int d,int &k){
    tin[v]=k;k++;
    dep[v]=d;
    rep(i,G[v].size()){
        int to=G[v][i];
        if(to==p)continue;
        dfs(to,v,d+1,k);
    }
    tout[v]=k;
}

BIT even,odd;

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N-1){
        int u,v;scanf("%lld%lld",&u,&v);u--;v--;
        G[u].pb(v);G[v].pb(u);
    }

    int K=0;
    dfs(0,-1,0,K);

    even.init(N+114);odd.init(N+114);

    rep(i,N){
        if(dep[i]&1){
            even.add(tin[i],A[i]);
            even.add(tin[i]+1,-A[i]);
        }
        else{
            odd.add(tin[i],A[i]);
            odd.add(tin[i]+1,-A[i]);
        }
    }

    puts("");

    while(M--){
        int type;scanf("%lld",&type);
        if(type==1){
            int x,val;
            scanf("%lld%lld",&x,&val);
            x--;
            if(dep[x]&1){
                even.add(tin[x],val);
                even.add(tout[x],-val);
                odd.add(tin[x],-val);
                odd.add(tout[x],val);
            }
            else{
                odd.add(tin[x],val);
                odd.add(tout[x],-val);
                even.add(tin[x],-val);
                even.add(tout[x],val);
            }
        }
        else{
            int x;scanf("%lld",&x);
            x--;
            if(dep[x]&1)printf("%lld\n",even.sum(tin[x]));
            else printf("%lld\n",odd.sum(tin[x]));
        }
    }
    return 0;
}